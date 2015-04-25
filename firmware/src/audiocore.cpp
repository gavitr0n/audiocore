/**
 ***********************************************************
 * @file    audiocore.cpp
 * @author  Gavin Lee
 * @brief   source file for audiocore functions
 ***********************************************************
 */
#include "inc/audiocore.h"

static int volume_control(int);
static int mute_control(bool);
static int spark_led_control(int);
static int filter_shape(int);

/*******************************************************************************
 * Function Name  : tinkerDigitalWrite
 * Description    : Sets the specified pin HIGH or LOW
 * Input          : Pin and value
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int tinkerDigitalWrite(String command)
{
   bool value = 0;
	//convert ascii to integer
   int pinNumber = command.charAt(1) - '0';
	//Sanity check to see if the pin numbers are within limits
   if (pinNumber< 0 || pinNumber >7) return -1;

   if(command.substring(3,7) == "HIGH") value = 1;
   else if(command.substring(3,6) == "LOW") value = 0;
   else return -2;

   if(command.startsWith("D"))
   {
      //-- using pin 5 for mute control
      if(pinNumber == 5)
      {
         return mute_control(value);
      }

      if(pinNumber == 6)
      {
         return audiocore_reset();
      }
      if(pinNumber == 7)
      {
         return spark_led_control(value);
      }
      return 1;
   }
   else if(command.startsWith("A"))
   {
      pinMode(pinNumber+10, OUTPUT);
      digitalWrite(pinNumber+10, value);
      return 1;
   }
   else return -3;
}

/*******************************************************************************
 * Function Name  : tinkerAnalogWrite
 * Description    : Writes an analog value (PWM) to the specified pin
 * Input          : Pin and Value (0 to 255)
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int tinkerAnalogWrite(String command)
{
   //convert ascii to integer
   int pinNumber = command.charAt(1) - '0';
   //Sanity check to see if the pin numbers are within limits
   if (pinNumber< 0 || pinNumber >7) return -1;

   int value = (command.substring(3)).toInt();

   if(command.startsWith("D"))
   {
      pinMode(pinNumber, OUTPUT);
      analogWrite(pinNumber, value);
      return 1;
   }
   else if(command.startsWith("A"))
   {
      /* run volume control if A0 was selected */
      if (pinNumber==0)
      {
         return volume_control(value);    
      }
      if (pinNumber==1)
      {
         return filter_shape(value);
      }
      return 1;
   }
   else return -2;
}

static int volume_control(int p_value){

   s_volume = ~p_value;
   if(s_volume<0 || s_volume>255) return -1;
                     
   es9018k2m.set_volume(s_volume);

   //s_volume = es9018k2m.get_volume_1();
   return 1;
}

int audiocore_reset(){
   int err_status =  es9018k2m.set_soft_reset();
   es9018k2m.set_vol_rate(7);
   volume_control(200);
   return err_status;
}

static int mute_control(bool p_value)
{
   spark_led_control(p_value);
   es9018k2m.set_mute(p_value,p_value);
   
   return 1;
}


static int spark_led_control(int p_value)
{
   s_led = p_value;  
   pinMode(7, OUTPUT);
   digitalWrite(7, p_value);

   return 1;
}

static int filter_shape(int p_value)
{
   int err_status = es9018k2m.set_filter_shape(p_value);

   sprintf(s_filter_shape,"%s", es9018k2m.filter_shape_);

   return err_status;
}

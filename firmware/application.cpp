/**   
 ***************************************************************
 * @file    application.cpp
 * @author  Gavin Lee
 * @version 1.0.0
 * @date    1/22/2015    
 * @brief   IoT frontend to control my DIY DAC/AMP
 *
 * This is a front-end for my DAC / AMP combo powered by an
 * ES9018K2m dac. The DACs internal registers can be controlled
 * through it's i2c interface. The sparkcore is used to control
 * the dac based off external peripherals like my phone or by 
 * external hardware.
 ***************************************************************
 */

/* Includes */
#include "inc/audiocore.h"

/* Scheduling */
// timing is based on a 0.5msec clock. Task timing = 0.5msec*[next task]
const unsigned int next_Serial = 1000; // launch every second
unsigned int task_Serial = next_Serial;

IntervalTimer schedulerTimer;
void schedulerTimer_ISR(void);


SYSTEM_MODE(AUTOMATIC); //automatically connect to wifi at startup

/* application setup routin */
void setup()
{
   //-- i2c init
   //Wire.setSpeed(CLOCK_SPEED_100KHZ);
   Wire.begin();
   
   //-- serial init
   Serial.begin(9600);
  
   //-- timer setup
   schedulerTimer.begin(schedulerTimer_ISR,2,hmSec,TIMER3);

   //-- Spark functions
   Spark.function("digitalwrite", tinkerDigitalWrite);
   Spark.function("analogwrite", tinkerAnalogWrite);

   //-- Spark Variables
   Spark.variable("led",(int*)&s_led,INT);
   Spark.variable("volume",(int*)&s_volume,INT);
   Spark.variable("filter",&s_filter_shape,STRING);

   //--audiocore init
   audiocore_reset();
}


/* application main. I'm running a scheduler in the main loop*/
void loop()
{
   if (g_tick > task_Serial)
   {
      uint8_t chip_id = 0;
      uint8_t rev = 0;

      chip_id = es9018k2m.get_chip_id();
      rev = es9018k2m.get_revision();

      Serial.print("chip id: ");
      Serial.print(chip_id);
      Serial.print(" rev: ");
      Serial.println(rev);

      task_Serial += next_Serial;;
   }

}

void schedulerTimer_ISR(){
   g_tick++;

}



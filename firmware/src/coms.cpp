/**
 **********************************************************************
 * @file    coms.cpp 
 * @author  Gavin Lee
 * @brief   library functions relating to coms (I2C,SPI) are here. 
 **********************************************************************
 */
#include "inc/audiocore.h"

/**
* @fn    read_i2c
* @brief reads data from the intended address.
* @param i2c_add  the chip address to communicate with
* @param reg_add  the register address to be read
* @param length   number of byte to be read
* @parma *data    the data in bytes to be read
*/
void read_i2c(uint8_t i2c_add, uint8_t reg_add,int length, uint8_t * data)
{
   Wire.beginTransmission(i2c_add); //start i2c transmission
   Wire.write(reg_add);             //send register address
   Wire.endTransmission(0);         //hold start bit. do not send stop condition

   Wire.requestFrom((int)i2c_add,length);//grab data from bus for length "length"

   while ( Wire.available() )
   {
      *data = Wire.read(); //store data to "data"
      data++;
   }
   Wire.endTransmission();
   if (MESSAGE_LEVEL)
   {
      for (int ii = 0; ii<length; ii++) Serial.println(data[ii],HEX);
   }
}

/**
* @fn    write_i2c
* @brief writes data to the intended address.
* @param i2c_add  the chip address to communicate with
* @param reg_add  the register address to be written
* @param length   number of byte to be written
* @parma *data    the data in bytes to be written
*/
void write_i2c(uint8_t i2c_add,uint8_t reg_add, int length, uint8_t * data)
{
   Wire.beginTransmission(i2c_add);
   Wire.write(reg_add);

   for (int ii = 0; ii<length ; ii ++)
   {
      Wire.write(*data);
      data++;
   }
   
   Wire.endTransmission();
}

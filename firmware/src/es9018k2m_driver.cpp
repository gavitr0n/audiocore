/**
 ***********************************************************
 * @file    es9018k2m_driver.cpp
 * @author  Gavin Lee
 * @brief   source file for the es9018k2m driver
 ***********************************************************
 */
#include "inc/audiocore.h"

es9018k2m_class es9018k2m;

int es9018k2m_class::set_soft_reset()
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SYSTEM_SETTINGS,1,&t_data);
   t_data |= (1<<SOFT_RESET);
   write_i2c(ES9018K2M_ADDR,RA_SYSTEM_SETTINGS,1,&t_data);

   return 0;
}
std::string es9018k2m_class::get_input_select()
{
   uint8_t t_data;
   uint8_t output[100];

   read_i2c(ES9018K2M_ADDR,RA_INPUT_CONFIG,1,&t_data);
   t_data |= (1<<INPUT_SELECT);
   write_i2c(ES9018K2M_ADDR,RA_INPUT_CONFIG,1,&t_data);
   read_i2c(ES9018K2M_ADDR,RA_INPUT_CONFIG,1,output);
   
   return std::string((char*)output);
}
int es9018k2m_class::set_automute(uint8_t time,bool loopback,unsigned int level)
{
   set_automute_time(time);
   set_automute_loopback(loopback);
   set_automute_level(level);

   return 0;
}
int es9018k2m_class::set_automute_time(uint8_t _data)
{
   if( _data > 8) return 1; 

   uint8_t t_data;
   t_data = _data;
   write_i2c(ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_1,1,&t_data);

   return 0;
}
int es9018k2m_class::set_automute_loopback(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_2,1,&t_data);
   t_data |= (_bit<<AUTOMUTE_LOOPBACK);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_2,1,&t_data);

   return 0;
}
int es9018k2m_class::set_automute_level(uint8_t _data)
{
   if (_data > 0x7F ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_2,1,&t_data);
   t_data |= (_data<<AUTOMUTE_LEVEL);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_2,1,&t_data);

   return 0;
}
int es9018k2m_class::set_vol_rate(uint8_t _data)
{
   if (_data > 0x7) return -1;
   
   uint8_t t_data;
   

   read_i2c (ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_3,1,&t_data);
   t_data |= (_data<<VOL_RATE);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_VOLUME_CNTRL_3,1,&t_data);

   return 0;
}
int es9018k2m_class::set_deemph_bypass(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_DEEMPHASIS,1,&t_data);
   t_data |= (_bit<<DEEMPH_BYPASS);
   write_i2c(ES9018K2M_ADDR,RA_DEEMPHASIS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_filter_shape(uint8_t _data)
{
   if (_data > 2) return -1;
  
   /* store the filter shape data */
   switch (_data)
   {
      case 1:
         sprintf(filter_shape_, "Slow Rolloff ");
         break;
      case 2:
         sprintf(filter_shape_, "Minimum Phase");
         break;
      case 3:
         return -2; // this case is reserved in the address space
      default:
         sprintf(filter_shape_, "Fast Rolloff ");
         break;
   }
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);
   t_data |= (_data<<FILTER_SHAPE);
   write_i2c(ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_iir_bw(uint8_t _data)
{
   if (_data > 0x3 ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);
   t_data |= (_data<<IIR_BW);
   write_i2c(ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_mute(bool _left_bit, bool _right_bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);
   if (_left_bit){
      if(_right_bit){
         t_data |= (_right_bit<<(MUTE+1))+(_left_bit<<MUTE); //mute channel 1 and 2
      }else {
         t_data |= (1<<MUTE);       //mute channel 1
         t_data &= ~(1<<(MUTE+1));  // unmute channel 2
      }
   } else{
      if(_right_bit){
         t_data |= (1<<(MUTE+1));   // unmute channel 1
         t_data &= ~(1<<MUTE);      // mute channel 2
      } else{
         t_data &= ~(1<<(MUTE+1));  //unmute channel 1
         t_data &= ~(1<<MUTE);      //unmute channel 2

      }
   }
   write_i2c(ES9018K2M_ADDR,RA_GENERAL_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_gpio1_cfg(uint8_t _data)
{
   if( _data > 0xF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GPIO_CONFIG,1,&t_data);
   t_data |= (_data<< GPIO1_CFG);
   write_i2c(ES9018K2M_ADDR,RA_GPIO_CONFIG,1,&t_data);

   return 0;
}
int es9018k2m_class::set_gpio2_cfg(uint8_t _data)
{
   if( _data > 0xF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GPIO_CONFIG,1,&t_data);
   t_data |= (_data<< GPIO2_CFG);
   write_i2c(ES9018K2M_ADDR,RA_GPIO_CONFIG,1,&t_data);

   return 0;
}
int es9018k2m_class::set_ch2_analog_swap(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);
   t_data |= (_bit<< CH2_ANALOG_SWAP);
   write_i2c(ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);

   return 0;
}
int es9018k2m_class::set_ch1_analog_swap(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);
   t_data |= (_bit<< CH1_ANALOG_SWAP);
   write_i2c(ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);

   return 0;
}
int es9018k2m_class::set_ch2_sel(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);
   t_data |= (_bit<< CH2_SEL);
   write_i2c(ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);

   return 0;
}
int es9018k2m_class::set_ch1_sel(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);
   t_data |= (_bit<< CH1_SEL);
   write_i2c(ES9018K2M_ADDR,RA_CHANNEL_MAPPING,1,&t_data);

   return 0;
}
int es9018k2m_class::set_dpll_bw_dsd(uint8_t _data)
{
   if( _data > 0xF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_DPLL_ASRC_SETTINGS,1,&t_data);
   t_data |= (_data<< DPLL_BW_DSD);
   write_i2c(ES9018K2M_ADDR,RA_DPLL_ASRC_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_dpll_bw_i2s(uint8_t _data)
{
   if( _data > 0xF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_DPLL_ASRC_SETTINGS,1,&t_data);
   t_data |= (_data<< DPLL_BW_I2S);
   write_i2c(ES9018K2M_ADDR,RA_DPLL_ASRC_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_soft_start(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);
   t_data |= (_bit<< SOFT_START);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_soft_start_on_lock(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);
   t_data |= (_bit<< SOFT_START_ON_LOCK);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_soft_start_time(uint8_t _data)
{
   if( _data > 0xF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);
   t_data |= (_data<< SOFT_START_TIME);
   write_i2c(ES9018K2M_ADDR,RA_SOFT_START_SETTINGS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_volume_1(uint8_t _data)
{
   //if( _data > 0xFF ) return 1;

   //uint8_t t_data;

   //read_i2c (ES9018K2M_ADDR,RA_VOLUME_1,1,&t_data);
   //t_data |= (_data<< VOLUME_1);
   write_i2c(ES9018K2M_ADDR,RA_VOLUME_1,1,&_data);

   return 0;
}
int es9018k2m_class::set_volume_2(uint8_t _data)
{
   //if( _data > 0xFF ) return 1;

   //uint8_t t_data;

   //read_i2c (ES9018K2M_ADDR,RA_VOLUME_2,1,&t_data);
   //t_data |= (_data<< VOLUME_2);
   write_i2c(ES9018K2M_ADDR,RA_VOLUME_2,1,&_data);

   return 0;
}
uint8_t es9018k2m_class::get_volume_1()
{
   //if( _data > 0xFF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_VOLUME_1,1,&t_data);

   return t_data;
}
uint8_t es9018k2m_class::get_volume_2()
{
   //if( _data > 0xFF ) return 1;

   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_VOLUME_2,1,&t_data);

   return t_data;
}
int es9018k2m_class::set_volume(uint8_t _data)
{
   set_volume_1(_data);
   set_volume_2(_data);

   return 0;
}
int es9018k2m_class::set_bypass_osf(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GPIO_SEL_OSF_BYPASS,1,&t_data);
   t_data |= (_bit<< BYPASS_OSF);
   write_i2c(ES9018K2M_ADDR,RA_GPIO_SEL_OSF_BYPASS,1,&t_data);

   return 0;
}
int es9018k2m_class::set_bypass_iir(bool _bit)
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_GPIO_SEL_OSF_BYPASS,1,&t_data);
   t_data |= (_bit<< BYPASS_IIR);
   write_i2c(ES9018K2M_ADDR,RA_GPIO_SEL_OSF_BYPASS,1,&t_data);

   return 0;
}
bool es9018k2m_class::get_lock_status()
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHIP_STATUS,1,&t_data);
   
   lock_status_ = t_data & LOCK_STATUS;
   return lock_status_;
}
bool es9018k2m_class::get_automute_status()
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHIP_STATUS,1,&t_data);
   
   automute_status_ = t_data & AUTOMUTE_STATUS;
   return (bool)automute_status_;
}
uint8_t es9018k2m_class::get_chip_id()
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHIP_STATUS,1,&t_data);
   
   chip_id_ = (t_data>>CHIP_ID) & 0x7 ;
   return chip_id_;
}
bool es9018k2m_class::get_revision()
{
   uint8_t t_data;

   read_i2c (ES9018K2M_ADDR,RA_CHIP_STATUS,1,&t_data);
   
   revision_ = t_data & REVISION;
   return revision_;
}
uint32_t es9018k2m_class::get_dpll_num()
{
   uint8_t t_data[4];

   read_i2c (ES9018K2M_ADDR,RA_CHIP_STATUS,4,t_data);
   
   dpll_num_ = (t_data[0]<<3) + (t_data[1]<<2) +(t_data[2]<<1) +(t_data[3]<<0);
   return dpll_num_;
}

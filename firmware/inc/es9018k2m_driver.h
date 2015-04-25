/**
 ***********************************************************
 * @file    es9018k2m_driver.h
 * @author  Gavin Lee
 * @brief   header file for the es9018k2m driver
 ***********************************************************
 */
#ifndef ES9018K2M_DRIVER_H
#define ES9018K2M_DRIVER_H
 class es9018k2m_class
 {
   public:
      String input_select_;
      bool deemph_bypass_;
      char filter_shape_[15];
      bool lock_status_;
      bool automute_status_;
      volatile uint8_t chip_id_;
      volatile bool revision_;
      uint32_t dpll_num_;
      int set_soft_reset();
      std::string get_input_select();
      //-- automute functions
      int set_automute(uint8_t time,bool loopback,unsigned int level);
      int set_automute_time(uint8_t _data);
      int set_automute_loopback(bool _bit);
      int set_automute_level(uint8_t _data);
      //-- deemphasis fucntions
      int set_deemph_bypass(bool _bit);
      int set_vol_rate(uint8_t _data);
      //-- general settings
      int set_filter_shape(uint8_t _data);
      int set_iir_bw(uint8_t _data);
      int set_mute(bool _left_bit,bool _right_bit);
      //-- gpio config
      int set_gpio1_cfg(uint8_t _data);
      int set_gpio2_cfg(uint8_t _data);
      //-- channel mapping 
      int set_ch2_analog_swap(bool _bit);
      int set_ch1_analog_swap(bool _bit);
      int set_ch2_sel(bool _bit);
      int set_ch1_sel(bool _bit);
      //-- dpll/asrc settings
      int set_dpll_bw_dsd(uint8_t _data);
      int set_dpll_bw_i2s(uint8_t _data);
      //-- soft start settings
      int set_soft_start(bool _bit);
      int set_soft_start_on_lock(bool _bit);
      int set_mute_on_lock(bool _bit);
      int set_soft_start_time(uint8_t _data);
      //-- volume controls
      int set_volume_1(uint8_t _data);
      uint8_t get_volume_1();
      int set_volume_2(uint8_t _data);
      uint8_t get_volume_2();
      int set_volume(uint8_t _data);
      //-- gpio input selection and osf bypass
      int set_bypass_osf(bool _bit);
      int set_bypass_iir(bool _bit);
      int set_gpio_input_sel1(uint8_t _data);
      int set_gpio_input_sel2(uint8_t _data);
      //-- programmable filter address
      int set_coeff_stage(bool _bit);
      int set_coeff_addr(uint8_t _data);
      //-- programmable filter coefficient
      int set_prog_coeff(uint32_t _data);
      //-- programmable filter controlkk
      int set_prog_coeff_en(bool _bit);
      int set_prog_coeff_we(bool _bit);
      int set_even_stage2_coeff(bool _bit);
      //-- chip status
      bool get_lock_status();
      bool get_automute_status();
      uint8_t get_chip_id();
      bool get_revision();
      uint32_t get_dpll_num();
 };

 extern es9018k2m_class es9018k2m;;

#endif

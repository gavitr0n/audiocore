/**
 ***********************************************************
 * @file    define.h
 * @author  Gavin Lee
 * @brief   here lies all defines and macros for the project
 ***********************************************************
 */
#ifndef DEFINE_H
#define DEFINE_H

#define MESSAGE_LEVEL  0 
//#define OPUS 
//#define ES9018 
//#define AK4490 
#define ES9018K2M

#ifdef ES9018K2M
   #define ES9018K2M_ADDR           (0x48)
   /* Register Address Macros */
   #define RA_SYSTEM_SETTINGS       (0x00)
   #define RA_INPUT_CONFIG          (0x01)
   #define RA_SOFT_VOLUME_CNTRL_1   (0x04)
   #define RA_SOFT_VOLUME_CNTRL_2   (0x05)
   #define RA_SOFT_VOLUME_CNTRL_3   (0x06) // this and demphasis point to same address
   #define RA_DEEMPHASIS            (0x06) // this and soft volume control 3 point to same address
   #define RA_GENERAL_SETTINGS      (0x07)
   #define RA_GPIO_CONFIG           (0x08)
   #define RA_MASTER_MODE_CNTRL     (0x0A)
   #define RA_CHANNEL_MAPPING       (0x0B)
   #define RA_DPLL_ASRC_SETTINGS    (0x0C)
   #define RA_SOFT_START_SETTINGS   (0x0E)
   #define RA_VOLUME_1              (0x0F)
   #define RA_VOLUME_2              (0x10)
   #define RA_MASTER_TRIM_1         (0x11)
   #define RA_MASTER_TRIM_2         (0x12)
   #define RA_MASTER_TRIM_3         (0x13)
   #define RA_MASTER_TRIM_4         (0x14)
   #define RA_GPIO_SEL_OSF_BYPASS   (0x15)
   #define RA_PROG_FILTER_ADDR      (0x1A)
   #define RA_PROG_FILTER_COEFF1    (0x1B)
   #define RA_PROG_FILTER_COEFF2    (0x1C)
   #define RA_PROG_FILTER_COEFF3    (0x1D)
   #define RA_PROG_FILTER_CTRL      (0x1E)
   #define RA_CHIP_STATUS           (0x40)
   #define RA_DPLL_RATIO            (0x42)
   
   /* Register Bit Masks*/
   //-- System setting bit masks
   #define SOFT_RESET               (0)
   #define OSCR_DRV                 (4)
   //-- Input configuration bit masks
   #define INPUT_SELECT             (0)
   #define AUTO_INPUT_SELECT        (2)
   #define I2S_MODE                 (4)
   #define I2S_LENGTH               (6)
   //-- Soft volume control 1 bit masks
   #define AUTOMUTE_TIME            (0)
   //-- Soft colume control 2 bit masks
   #define AUTOMUTE_LEVEL           (0)
   #define AUTOMUTE_LOOPBACK        (7)
   #define VOL_RATE                 (0)
   //-- Deemphasis bit masks
   #define DEEMPH_SEL               (4)
   #define DEEMPH_BYPASS            (6)
   #define SPDIF_AUTO_DEEMPH        (7)
   //-- General Settings bit masks
   #define MUTE                     (0)
   #define IIR_BW                   (1)
   #define FILTER_SHAPE             (5)
   //-- GPIO bit masks
   #define GPIO1_CFG                (0)
   #define GPIO2_CFG                (4)
   //-- Master mode bit masks
   #define STOP_DIV                 (0)
   #define SYNC_MODE                (4)
   #define CLOCK_DIVIDER_SELECT     (5)
   #define MASTER_CLOCK_ENABLE      (7)
   //-- Channel mapping bit masks
   #define CH1_SEL                  (0)
   #define CH2_SEL                  (1)
   #define CH1_ANALOG_SWAP          (2)
   #define CH2_ANALOG_SWAP          (3)
   #define SPDIF_SEL                (4)
   //-- DPLL/ASRC settings
   #define DPLL_BW_DSD              (0)
   #define DPLL_BW_I2S              (4)
   //-- Soft start settings
   #define SOFT_START_TIME          (0)
   #define MUTE_ON_LOCK             (5)
   #define SOFT_START_ON_LOCK       (6)
   #define SOFT_START               (7)
   //-- Volume 1 bit masks
   #define VOLUME_1                 (0)
   //-- Volume 2 bit masks
   #define VOLUME_2                 (0)
   //-- Master trim bit masks
   #define MASTER_TRIM              (0)
   //-- GPIO input selection and OSF bypass bitmasks
   #define BYPASS_OSF               (0)
   #define BYPASS_IIR               (2)
   #define GPIO_INPUT_SEL1          (4)
   #define GPIO_INPUT_SEL2          (5)
   //-- Programmable filter address bit masks
   #define PROG_COEFF_ADDR          (0)
   #define PROG_COEFF_STAGE         (7)
   //-- Programmable filter coefficient bit masks
   #define PROG_COEFF               (0)
   //-- Programmable filter control bit masks
   #define PROG_COEFF_EN            (0)
   #define PROG_COEFF_WE            (1)
   #define EVEN_STAGE2_COEFF        (2)
   //-- Chip status 
   #define LOCK_STATUS              (0)
   #define AUTOMUTE_STATUS          (1)
   #define CHIP_ID                  (2)
   #define REVISION                 (5)
   //-- DPLL ratio bit masks
   #define DPLL_NUM                 (0)
#endif
/*** AK4490 macros ***/
#ifdef AK4490
   #define AK44990_ADDR 0x10
   
   /* REGISTER ADDRESSES */
   #define CONTROL_1 0x00
   #define CONTROL_2 0x01
   #define CONTROL_3 0x02
   #define LCH_ATT   0x03
   #define RCH_ATT   0x04
   #define CONTROL_4 0x05
   #define CONTROL_5 0x06
   #define CONTROL_6 0x07
   #define CONTROL_7 0x08
   #define CONTROL_8 0x09

   /*** REGISTER DATA BIT MASKS ***/
   //-- Control 1 bitmasks
   #define ACKS      0x80
   #define EXDF      0x40
   #define ECS       0x20
   #define DIF2      0x08
   #define DIF1      0x04
   #define DIF0      0x02
   #define RSTN      0x01
   //-- Control 2 bitmasks
   #define DZFE      0x80
   #define DZFM      0x40
   #define SD        0x20
   #define DFS1      0x10
   #define DFS0      0x08
   #define DEM1      0x04
   #define DEM0      0x02
   #define SMUTE     0x01
   //-- Control 3 bitmasks
   #define DP        0x80
   #define DCKS      0x20
   #define DCKB      0x10
   #define MONO      0x08
   #define DZFB      0x04
   #define SELLR     0x02
   #define SLOW      0x01
   //-- Control 4 bitmasks
   #define INVL      0x80
   #define INVR      0x40
   #define DFS2      0x02
   #define SSLOW     0x01
   //-- Control 5 bitmasks
   #define DDM       0x80
   #define DML       0x40
   #define DMR       0x20
   #define DMC       0x10
   #define DMRE      0x08
   #define DSDD      0x02
   #define DSDSEL0   0x01
   //-- Control 6 bitmasks
   #define SYNCE     0x01
   //-- Control 7 bitmasks
   #define SC1       0x02
   #define SC0       0x01
   //-- Control 8 bitmasks
   #define DSDF      0x02
   #define DSDSEL1   0x01
#endif

/*** OPUS macros ***/
#ifdef OPUS
   /* register addresses*/
   #define DACLLSB               (0x00<<1)
   #define DACLMSB               (0x01<<1)
   #define DACRLSB               (0x02<<1)
   #define DACRMSB               (0x04<<1)
   #define VOLUME_CONTROL        (0x04<<1)
   #define FORMAT_CONTROL        (0x05<<1)
   #define FILTER_CONTROL        (0x06<<1)
   #define MODE_CONTROL_1        (0x07<<1)
   #define MODE_CONTROL_2        (0x08<<1)
   #define SOFTWARE_RESET        (0x09<<1)
   #define ADDITIONAL_CONTROL_1  (0x20<<1)

   /*** REGISTER DATA BIT MASKS ***/
   // if the data is greater than a bit, assume that the macro is calling the LSB of the data.
   // i.e  for LAT[4:0] the macro, LAT0, will point to LAT[0]. no other bits in the data will be defined.
   //--  DAC side attenuation bit masks
   #define LAT       0x00
   #define UPDATELL  0x20
   #define UPDATELM  0x20
   #define RAT       0x00
   #define UPDATERL  0x20
   #define UPDATERM  0x20
   //-- Volume control bit masks
   #define VOL_RAMP  0x01
   #define ATT2DB    0x02
   #define ATC       0x04
   #define SOFT_MUTE 0x08
   #define IZD       0x10
   #define ZEROFLR   0x20
   #define AMUTE     0x80
   //-- Format control bit masks
   #define IWL       0x01
   #define FMT       0x04
   #define LRP       0x10
   #define BCP       0x20
   #define REV       0x40
   #define PWDN      0x80
   //-- Filter control bit masks
   #define FIRSEL    0x00
   #define DSDFILT   0x08
   #define DEEMP0    0x20
   #define ZFLAG_HI  0x80
   //-- Mode control 1 bit masks
   #define MODESEL   0x00
   #define SR0       0x04
   #define OSR0      0x20
   #define MODE8X    0x80
   //-- Mode control 2 bit masks
   #define DITHER    0x00
   #define DIFF      0x00
   #define DOUT      0x10
   #define SDOUT     0x20
   #define DSD_GAIN  0x40
   //-- Additional control bit masks
   #define DSD_NO_NOTCH 0x01
   #define DSD_LEVEL    0x02
#endif
/*** I2C general macros ***/
#define READ   1
#define WRITE  0
#endif

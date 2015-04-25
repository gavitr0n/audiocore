/**
 ***********************************************************
 * @file    stm_driver.h
 * @author  Gavin Lee
 * @brief   header file for the coms library
 ***********************************************************
 */

#ifndef STM32_DRIVER_H
#define STM32_DRIVER_H

#include "application.h"
extern void timer4_init();

#ifdef __cplusplus
extern "C" {
#endif

extern void (*Wiring_TIM4_Interrupt_Handler)(void);
extern void Wiring_TIM4_Interrupt_Handler_override(void);

#ifdef __cplusplus
}
#endif
#endif

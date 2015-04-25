/**
 ***********************************************************
 * @file    stm32_driver.cpp
 * @author  Gavin Lee
 * @brief   source file for the stm32f10x microcontroller.
 *          Using this file to setup controller peripherals.
 ***********************************************************
 */
#include "inc/audiocore.h"
/**
 * @fn timer4_init
 * @brief sets up timer 4 for 10kHz reload, and enables interrupts
 * TIM4->PSC = 0x47 (counter frequency = fclk/(0x47+1)
 * TIM4->EGR = 0x01 (load prescaler immediately)
 * TIM4->ARR = 0x63 (autoreload register value)
 *
 */

void timer4_init()
{
   Wiring_TIM4_Interrupt_Handler = Wiring_TIM4_Interrupt_Handler_override;
   
   TIM_TimeBaseInitTypeDef timerInitStructure;

   timerInitStructure.TIM_Prescaler = (uint16_t) (SystemCoreClock / 1000000) - 1;
   timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
   timerInitStructure.TIM_Period = 1000;
   timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   timerInitStructure.TIM_RepetitionCounter = 0;

   TIM_TimeBaseInit(TIM4, &timerInitStructure);
   TIM_Cmd(TIM4, ENABLE);
   TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);


   //configure NVIC for TIM4
   NVIC_InitTypeDef NVIC_InitStructure;
   NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //Highest priority since this will be scheduler clock
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;;
   NVIC_Init(&NVIC_InitStructure);

   //Enable TIM4 interupt flags
}


/**
 ***********************************************************
 * @file    global.h
 * @author  Gavin Lee
 * @brief   here lies all defines and macros for the project
 ***********************************************************
 */
#ifndef GLOBAL_H
#define GLOBAL_H

extern volatile unsigned long g_tick;

extern volatile int s_led;
extern volatile uint8_t s_volume;
extern char s_filter_shape[50];
#endif

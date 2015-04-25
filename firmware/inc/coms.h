/**
 ***********************************************************
 * @file    coms.h
 * @author  Gavin Lee
 * @brief   header file for the coms library
 ***********************************************************
 */

#ifndef COMS_H
#define COMS_H

void read_i2c(uint8_t i2c_add, uint8_t reg_add, int length, uint8_t * data);
void write_i2c(uint8_t i2c_add, uint8_t reg_add, int length, uint8_t * data);

#endif

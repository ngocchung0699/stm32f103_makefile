#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

extern volatile uint64_t Timing;

void SysTick_Init();
void Delay_us(uint32_t us);
void Delay_ms(uint16_t ms);
uint64_t Micros();
uint64_t Millis();
#endif 



#ifndef __NC_GPIO_H
#define __NC_GPIO_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void GPIO_Config(GPIO_TypeDef* GPIOx, uint8_t GPIO_Mode, uint16_t GPIO_Pin);
void GPIO_Enable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Disable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Lock(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t GPIO_Read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Write_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t Status);

#endif 

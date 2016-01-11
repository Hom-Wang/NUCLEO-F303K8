/* #include "experiment_stm32f3.h" */

#ifndef __EXPERIMENT_STM32F3_H
#define __EXPERIMENT_STM32F3_H

#include "stm32f3xx_hal.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define LED_PIN                 GPIO_PIN_3
#define LED_GPIO_PORT           GPIOB
#define LED_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED_Set()               __GPIO_SET(LED_GPIO_PORT, LED_PIN)
#define LED_Reset()             __GPIO_RST(LED_GPIO_PORT, LED_PIN)
#define LED_Toggle()            __GPIO_TOG(LED_GPIO_PORT, LED_PIN)
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void );

void Serial_evenCallBack( void );
/*====================================================================================================*/
/*====================================================================================================*/
#endif

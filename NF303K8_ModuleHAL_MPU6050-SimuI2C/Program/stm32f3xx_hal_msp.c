/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f3_system.h"

#include "main.h"
/*====================================================================================================*/
/*====================================================================================================*/
/*
System Clock source            = PLL (HSI)
SYSCLK(Hz)                     = 64000000
HCLK(Hz)                       = 64000000
AHB Prescaler                  = 1
APB1 Prescaler                 = 2
APB2 Prescaler                 = 1
HSI Frequency(Hz)              = 8000000
PLLMUL                         = 16
Flash Latency(WS)              = 2
*/
void HAL_MspInit( void )
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef state = HAL_OK;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  state = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(state != HAL_OK)
    while(1) { ; }

  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  state = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
  if(state != HAL_OK)
    while(1) { ; }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Clk ******************************************************************/
  LED_GPIO_CLK_ENABLE();

  /* GPIO Pin ******************************************************************/
  /* LED */
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin   = LED_PIN;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  /* GPIO Pin ******************************************************************/
  LED_Set();
}
/*====================================================================================================*/
/*====================================================================================================*/

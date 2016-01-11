/* #include "module_bh1750.h" */

#ifndef __MODULE_BH1750_H
#define __MODULE_BH1750_H

#include "stm32f3xx_hal.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define BH1750_I2C_ADDR         ((uint8_t)0x46) // If ADD pin is H -> 0xB8

#define BH1750_PowerDOWN        ((uint8_t)0x00) // No active state.
#define BH1750_PowerON          ((uint8_t)0x01) // Waiting for measurement command.
#define BH1750_Reset            ((uint8_t)0x01) // Reset Data register value. Reset command is not acceptable in Power Down mode.
#define BH1750_Contimus_1lx     ((uint8_t)0x10) // Start measurement at 1lx resolution. Measurement Time is typically 120ms.
#define BH1750_Contimus_0p5lx   ((uint8_t)0x11) // Start measurement at 0.5lx resolution. Measurement Time is typically 120ms.
#define BH1750_Contimus_4lx     ((uint8_t)0x13) // Start measurement at 4lx resolution. Measurement Time is typically 16ms.
#define BH1750_OneTime_1lx      ((uint8_t)0x20) // Start measurement at 1lx resolution. Measurement Time is typically 120ms. It is automatically set to Power Down mode after measurement.
#define BH1750_OneTime_0p5x     ((uint8_t)0x21) // Start measurement at 0.5lx resolution. Measurement Time is typically 120ms. It is automatically set to Power Down mode after measurement.
#define BH1750_OneTime_4lx      ((uint8_t)0x23) // Start measurement at 4lx resolution. Measurement Time is typically 16ms. It is automatically set to Power Down mode after measurement.
#define BH1750_SetMeasureTimeH  ((uint8_t)0x40) // MT[7,6,5], Change measurement time. Please refer "adjust measurement result for influence of optical window."
#define BH1750_SetMeasureTimeL  ((uint8_t)0x60) // MT[4,3,2,1,0], Change measurement time. ※ Please refer "adjust measurement result for influence of optical window."
/*=====================================================================================================*/
/*=====================================================================================================*/
void     BH1750_Config( void );
void     BH1750_Init( void );
uint16_t BH1750_getData( void );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif

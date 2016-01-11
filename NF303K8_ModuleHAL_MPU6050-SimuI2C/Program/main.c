/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f3_system.h"
#include "modules\module_serial.h"
#include "modules\module_mpu6050.h"

#include "main.h"
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  MPU_InitTypeDef MPU_InitStruct;

  HAL_Init();
  GPIO_Config();
  Serial_Config();
  MPU6050_Config();

  delay_ms(100);
  printf("\fHello World!\r\n\r\n");

  LED_Set();
  MPU_InitStruct.MPU_Gyr_FullScale     = MPU_GyrFS_2000dps;
  MPU_InitStruct.MPU_Gyr_LowPassFilter = MPU_GyrLPS_41Hz;
  MPU_InitStruct.MPU_Acc_FullScale     = MPU_AccFS_4g;
  MPU_InitStruct.MPU_Acc_LowPassFilter = MPU_AccLPS_41Hz;
  while(MPU6050_Init(&MPU_InitStruct) != SUCCESS) {
    LED_Toggle();
    delay_ms(100);
  }
  LED_Reset();
  delay_ms(100);
}

int main( void )
{
  int16_t IMU_Buf[10] = {0};

  System_Init();

  while(1) {
    LED_Toggle();
    delay_ms(10);

    MPU6050_getData(IMU_Buf);
    printf("%d,%d,%d,%d,%d,%d\r", IMU_Buf[1], IMU_Buf[2], IMU_Buf[3], IMU_Buf[4], IMU_Buf[5], IMU_Buf[6]);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/

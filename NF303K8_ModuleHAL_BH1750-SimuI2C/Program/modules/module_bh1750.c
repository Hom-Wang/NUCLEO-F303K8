/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f3_system.h"
#include "drivers\stm32f3_i2cSimu.h"

#include "module_bh1750.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define I2CxS_SCL_PIN         GPIO_PIN_6
#define I2CxS_SCL_GPIO_PORT   GPIOB
#define I2CxS_SDO_PIN         GPIO_PIN_7
#define I2CxS_SDO_GPIO_PORT   GPIOB
#define I2CxS_FREQUENCY       10
/*====================================================================================================*/
/*====================================================================================================*/
static SimuI2C_InitTypeDef SimuI2C_InitStruct;
/*====================================================================================================*/
/*====================================================================================================*
**函數 : BH1750_WriteData
**功能 : Write Data
**輸入 : writeData
**輸出 : None
**使用 : BH1750_WriteData(writeData);
**====================================================================================================*/
/*====================================================================================================*/
void BH1750_WriteData( uint8_t writeData )
{
  SimuI2C_WriteData(&SimuI2C_InitStruct, BH1750_I2C_ADDR, &writeData, 1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : BH1750_SetMeasureTime
**功能 : Write Data
**輸入 : writeData
**輸出 : None
**使用 : BH1750_SetMeasureTime(writeData);
**====================================================================================================*/
/*====================================================================================================*/
void BH1750_SetMeasureTime( uint8_t writeData )
{
  uint8_t sendData[2] = {0};
  sendData[0] = BH1750_SetMeasureTimeH | ((writeData & 0xE0) >> 5);
  SimuI2C_WriteData(&SimuI2C_InitStruct, BH1750_I2C_ADDR, sendData, 1);
  sendData[1] = BH1750_SetMeasureTimeL | (writeData & 0xEF);
  SimuI2C_WriteData(&SimuI2C_InitStruct, BH1750_I2C_ADDR, sendData + 1, 1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : BH1750_Config
**功能 : BH1750 Config
**輸入 : None
**輸出 : None
**使用 : BH1750_Config();
**====================================================================================================*/
/*====================================================================================================*/
void BH1750_Config( void )
{
  SimuI2C_InitStruct.PinSCL    = I2CxS_SCL_PIN;
  SimuI2C_InitStruct.PortSCL   = I2CxS_SCL_GPIO_PORT;
  SimuI2C_InitStruct.PinSDA    = I2CxS_SDO_PIN;
  SimuI2C_InitStruct.PortSDA   = I2CxS_SDO_GPIO_PORT;
  SimuI2C_InitStruct.Freguency = I2CxS_FREQUENCY;
  SimuI2C_Config(&SimuI2C_InitStruct);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : BH1750_Init
**功能 : BH1750 Init
**輸入 : None
**輸出 : None
**使用 : BH1750_Init();
**====================================================================================================*/
/*====================================================================================================*/
void BH1750_Init( void )
{
  BH1750_WriteData(BH1750_PowerON);
  BH1750_WriteData(BH1750_Contimus_4lx);  // conv time max = 24ms
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : BH1750_getData
**功能 : Get Sensor Data
**輸入 : None
**輸出 : recvData
**使用 : recvData = BH1750_getData();
**====================================================================================================*/
/*====================================================================================================*/
uint16_t BH1750_getData( void )
{
  uint8_t readData[2] = {0};
  SimuI2C_ReadData(&SimuI2C_InitStruct, BH1750_I2C_ADDR, readData, 2);
  return Byte16(uint16_t, readData[1], readData[0]);
}
/*====================================================================================================*/
/*====================================================================================================*/

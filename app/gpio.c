////////////////////////////////////////////////////////////////////////////////
/// @file     GPIO.C
/// @author   C Yuan
/// @version  v2.0.0
/// @date     2019-03-13
/// @brief    THIS FILE PROVIDES ALL THE GPIO EXAMPLE.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT 2018-2019 MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion  --------------------------------------
#define _GPIO_C_

// Files includes  -------------------------------------------------------------
#include <string.h>
#include "types.h"
#include "mm32.h"

#include "system_mm32.h"

#include "common.h"
#include "bsp.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "gpio.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Example_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup EXAMPLE_GPIO
/// @{


////////////////////////////////////////////////////////////////////////////////
/// @addtogroup GPIO_Exported_Constants
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function handles App SysTick Handler.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void AppTaskTick()
{
    if (tickCnt++ >= 500) {
        tickCnt  = 0;
        tickFlag = true;
	}
    
    BSP_KeyTick();
}

void Key1Down()     { ledStatus[0] = !ledStatus[0]; };
void Key2Down()     { ledStatus[1] = !ledStatus[1]; };
void Key3Down()     { ledStatus[2] = !ledStatus[2]; };
void Key4Down()     { ledStatus[3] = !ledStatus[3]; };

void Key1Pressing() { if(tickFlag) {tickFlag = false; ledStatus[0] = !ledStatus[0];} };
void Key2Pressing() { if(tickFlag) {tickFlag = false; ledStatus[1] = !ledStatus[1];} };
void Key3Pressing() { if(tickFlag) {tickFlag = false; ledStatus[2] = !ledStatus[2];} };
void Key4Pressing() { if(tickFlag) {tickFlag = false; ledStatus[3] = !ledStatus[3];} };

////////////////////////////////////////////////////////////////////////////////
/// @brief  GPIO example
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	/* ====  System Clock & SysTick & AppTaskTick Setting  ==== */
	/* When the parameter is NULL, AppTaskTick function used */
	MCUID = SetSystemClock(emSYSTICK_On, AppTaskTick);
	
    COMMON_EnableIpClock(emCLOCK_GPIOA);
    COMMON_EnableIpClock(emCLOCK_GPIOB);
    GPIO_Mode_IPD_Init(KEY1_PORT, KEY1_BIT, NO_REMAP, GPIO_AF_0);
    GPIO_Mode_IPU_Init(KEY2_PORT, KEY2_BIT, NO_REMAP, GPIO_AF_0);
    GPIO_Mode_IPU_Init(KEY3_PORT, KEY3_BIT, NO_REMAP, GPIO_AF_0);
    GPIO_Mode_IPU_Init(KEY4_PORT, KEY4_BIT, NO_REMAP, GPIO_AF_0);
    
    GPIO_SetBits(LED1_PORT, LED1_BIT);
    GPIO_SetBits(LED2_PORT, LED2_BIT);
    GPIO_SetBits(LED3_PORT, LED3_BIT);
    GPIO_SetBits(LED4_PORT, LED4_BIT);
    GPIO_Mode_OUT_OD_20MHz_Init(LED1_PORT, LED1_BIT, NO_REMAP, GPIO_AF_0);
    GPIO_Mode_OUT_OD_20MHz_Init(LED2_PORT, LED2_BIT, EXTI_MAPR_SWJ_JTAGDISABLE, GPIO_AF_0);
    GPIO_Mode_OUT_OD_20MHz_Init(LED3_PORT, LED3_BIT, NO_REMAP, GPIO_AF_0);
    GPIO_Mode_OUT_OD_20MHz_Init(LED4_PORT, LED4_BIT, NO_REMAP, GPIO_AF_0);
    
    while (1) {
         GPIO_ReadInputDataBit(KEY1_PORT, KEY1_BIT) ? GPIO_ResetBits(LED1_PORT, LED1_BIT) : GPIO_SetBits  (LED1_PORT, LED1_BIT);
        !GPIO_ReadInputDataBit(KEY2_PORT, KEY2_BIT) ? GPIO_ResetBits(LED2_PORT, LED2_BIT) : GPIO_SetBits  (LED2_PORT, LED2_BIT);
        !GPIO_ReadInputDataBit(KEY3_PORT, KEY3_BIT) ? GPIO_ResetBits(LED3_PORT, LED3_BIT) : GPIO_SetBits  (LED3_PORT, LED3_BIT);
        !GPIO_ReadInputDataBit(KEY4_PORT, KEY4_BIT) ? GPIO_ResetBits(LED4_PORT, LED4_BIT) : GPIO_SetBits  (LED4_PORT, LED4_BIT);
    }
}

/// @}


/// @}

/// @}



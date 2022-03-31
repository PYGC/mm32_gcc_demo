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
#include "mm32_types.h"
#include "mm32.h"

#include "stdlib.h"

#include "mm32_system.h"

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
static void AppTaskTick(void)
{
    if (sysTickCnt++ >= 500) {
        sysTickCnt  = 0;
        tickFlag = true;
    }

    BSP_KeyTick();
}

static void Key1Down(void) { ledStatus[0] = !ledStatus[0]; }
static void Key2Down(void) { ledStatus[1] = !ledStatus[1]; }
static void Key3Down(void) { ledStatus[2] = !ledStatus[2]; }
static void Key4Down(void) { ledStatus[3] = !ledStatus[3]; }

static void Key1Pressing(void) { if(tickFlag) {tickFlag = false; ledStatus[0] = !ledStatus[0];} }
static void Key2Pressing(void) { if(tickFlag) {tickFlag = false; ledStatus[1] = !ledStatus[1];} }
static void Key3Pressing(void) { if(tickFlag) {tickFlag = false; ledStatus[2] = !ledStatus[2];} }
static void Key4Pressing(void) { if(tickFlag) {tickFlag = false; ledStatus[3] = !ledStatus[3];} }

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

    BSP_KEY_Configure();
    BSP_KeyFuncSet(1, Key1Down, Key1Pressing);
    BSP_KeyFuncSet(2, Key2Down, Key2Pressing);
    BSP_KeyFuncSet(3, Key3Down, Key3Pressing);
    BSP_KeyFuncSet(4, Key4Down, Key4Pressing);

    BSP_LED_Configure();
    CloseLED();

    bool* led4Flag = (bool*)malloc(sizeof(bool));
    if (led4Flag == NULL) {
        while (1) {}
    }

    while (1) {
        BSP_Key(1);
        BSP_Key(2);
        BSP_Key(3);
        BSP_Key(4);

        ledStatus[0] ? LD1_on() : LD1_off();
        ledStatus[1] ? LD2_on() : LD2_off();
        ledStatus[2] ? LD3_on() : LD3_off();
        
        *led4Flag = ledStatus[3];
        *led4Flag ? LD4_on() : LD4_off();
    }
}

/// @}

/// @}

/// @}



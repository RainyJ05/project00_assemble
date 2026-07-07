//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "stdio.h"
#include "hw_w25qxx.h"
#include "string.h"
#include "vofa.h"
#include "tjx_init.h"
#include "oled.h"
#include "key.h"

//
// Defines
//
#define EPWM_PERIOD             3000
#define ADC_SCALE               1/4096.0
#define comp_threshold          2500

//
// Globals
//
uint16_t adcAResult;          // value used to store ADC conversion
uint16_t CMPA_result;         // value used to calculate CMPA for new duty cycle value
float duty;                   // value that holds part of the calculation for CMPA

//
// Function Prototypes
//
//__interrupt void INT_myCPUTIMER0_ISR(void);
__interrupt void INT_myADCA_1_ISR(void);

//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    //
    // 定义局部变量
    //

    OLED_Init();
    Key_Open();
//    CPUTimer_startTimer(myCPUTIMER0_BASE); // 开启定时器
    EPWM_enableADCTrigger(myEPWM1_BASE, EPWM_SOC_A);// Start ePWM1, enabling SOCA

    uint8_t KeyNum = 0;
    for(;;)
    {
        if((EPWM_getTripZoneFlagStatus(myEPWM1_BASE) & EPWM_TZ_FLAG_OST) != 0U)
             {
                 //
                 // Wait for comparator CTRIP to de-assert
                 //
                 while((CMPSS_getStatus(myCMPSS3_BASE) & CMPSS_STS_HI_FILTOUT) != 0U);

                 //
                 // Clear trip flags
                 //
                 KeyNum = Key_GetNum();
                 if(KeyNum == 1)
                 {
                     EPWM_clearTripZoneFlag(myEPWM1_BASE, EPWM_TZ_INTERRUPT | EPWM_TZ_FLAG_OST | EPWM_TZ_FLAG_DCAEVT1);
                 }
             }
    }
} // end of main

//定时器中断服务函数，1kHz
__interrupt void INT_myCPUTIMER0_ISR(void)
{
//    GPIO_togglePin(TEST_GPIO);
//    Key_Tick();
    //清除中断标志位
    Interrupt_clearACKGroup(INT_myCPUTIMER0_INTERRUPT_ACK_GROUP);
}

// ADC转换完成中断服务函数
__interrupt void INT_myADCA_1_ISR(void)
{
    // 按键
    Key_Tick();

    // 获取转换结果
    adcAResult= ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);

    // 计算比较值
    duty = adcAResult*ADC_SCALE;
    CMPA_result = EPWM_PERIOD*(1-duty);

    // 更新占空比
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, CMPA_result);

    // 清除中断标志位
    ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);

    // 检查ADC溢出
    if(true == ADC_getInterruptOverflowStatus(myADCA_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);
    }

    // 响应中断向量组
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

//
// End of File
//

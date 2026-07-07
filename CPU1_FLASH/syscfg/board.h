/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// EPWM1 -> myEPWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define myEPWM1_EPWMA_GPIO 0
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define myEPWM1_EPWMB_GPIO 1
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B
//
// GPIO31 - GPIO Settings
//
#define LED0_GPIO_PIN_CONFIG GPIO_31_GPIO31
//
// GPIO55 - GPIO Settings
//
#define FLASH_CS_GPIO_PIN_CONFIG GPIO_55_GPIO55
//
// GPIO27 - GPIO Settings
//
#define SCREEN_SCL_GPIO_PIN_CONFIG GPIO_27_GPIO27
//
// GPIO26 - GPIO Settings
//
#define SCREEN_SDA_GPIO_PIN_CONFIG GPIO_26_GPIO26
//
// GPIO57 - GPIO Settings
//
#define KEY0_GPIO_PIN_CONFIG GPIO_57_GPIO57
//
// GPIO58 - GPIO Settings
//
#define KEY1_GPIO_PIN_CONFIG GPIO_58_GPIO58
//
// GPIO59 - GPIO Settings
//
#define KEY2_GPIO_PIN_CONFIG GPIO_59_GPIO59
//
// GPIO44 - GPIO Settings
//
#define TEST_GPIO_GPIO_PIN_CONFIG GPIO_44_GPIO44

//
// SCIB -> mySCIB Pinmux
//
//
// SCIB_RX - GPIO Settings
//
#define GPIO_PIN_SCIB_RX 23
#define mySCIB_SCIRX_GPIO 23
#define mySCIB_SCIRX_PIN_CONFIG GPIO_23_SCIB_RX
//
// SCIB_TX - GPIO Settings
//
#define GPIO_PIN_SCIB_TX 22
#define mySCIB_SCITX_GPIO 22
#define mySCIB_SCITX_PIN_CONFIG GPIO_22_SCIB_TX

//
// SPIA -> FLASH_SPI Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 16
#define FLASH_SPI_SPIPICO_GPIO 16
#define FLASH_SPI_SPIPICO_PIN_CONFIG GPIO_16_SPIA_SIMO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 17
#define FLASH_SPI_SPIPOCI_GPIO 17
#define FLASH_SPI_SPIPOCI_PIN_CONFIG GPIO_17_SPIA_SOMI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 56
#define FLASH_SPI_SPICLK_GPIO 56
#define FLASH_SPI_SPICLK_PIN_CONFIG GPIO_56_SPIA_CLK

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADCA_BASE ADCA_BASE
#define myADCA_RESULT_BASE ADCARESULT_BASE
#define myADCA_SOC0 ADC_SOC_NUMBER0
#define myADCA_FORCE_SOC0 ADC_FORCE_SOC0
#define myADCA_SAMPLE_WINDOW_SOC0 100
#define myADCA_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM1_SOCA
#define myADCA_CHANNEL_SOC0 ADC_CH_ADCIN0
void myADCA_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
#define myCMPSS3_BASE CMPSS3_BASE
#define myCMPSS3_HIGH_COMP_BASE CMPSS3_BASE    
#define myCMPSS3_LOW_COMP_BASE CMPSS3_BASE    
void myCMPSS3_init();

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM1_BASE EPWM1_BASE
#define myEPWM1_TBPRD 3000
#define myEPWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define myEPWM1_TBPHS 0
#define myEPWM1_CMPA 0
#define myEPWM1_CMPB 0
#define myEPWM1_CMPC 0
#define myEPWM1_CMPD 0
#define myEPWM1_DBRED 120
#define myEPWM1_DBFED 120
#define myEPWM1_TZA_ACTION EPWM_TZ_ACTION_LOW
#define myEPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM1_OSHT_SOURCES EPWM_TZ_SIGNAL_DCAEVT1
#define myEPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void myEPWMXBAR4_init();
#define myEPWMXBAR4 XBAR_TRIP4
#define myEPWMXBAR4_ENABLED_MUXES (XBAR_MUX04)

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED0 31
void LED0_init();
#define FLASH_CS 55
void FLASH_CS_init();
#define SCREEN_SCL 27
void SCREEN_SCL_init();
#define SCREEN_SDA 26
void SCREEN_SDA_init();
#define KEY0 57
void KEY0_init();
#define KEY1 58
void KEY1_init();
#define KEY2 59
void KEY2_init();
#define TEST_GPIO 44
void TEST_GPIO_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myADCA_1
#define INT_myADCA_1 INT_ADCA1
#define INT_myADCA_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADCA_1_ISR(void);

// Interrupt Settings for INT_myCPUTIMER0
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myCPUTIMER0_ISR(void);

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCIB_BASE SCIB_BASE
#define mySCIB_BAUDRATE 115200
#define mySCIB_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCIB_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCIB_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCIB_FIFO_TX_LVL SCI_FIFO_TX0
#define mySCIB_FIFO_RX_LVL SCI_FIFO_RX0
void mySCIB_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define FLASH_SPI_BASE SPIA_BASE
#define FLASH_SPI_BITRATE 1000000
#define FLASH_SPI_DATAWIDTH 8
void FLASH_SPI_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CMPSS_init();
void	CPUTIMER_init();
void	EPWM_init();
void	EPWMXBAR_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SCI_init();
void	SPI_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition

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
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	GPIO_init();
void	SCI_init();
void	SPI_init();
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

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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	GPIO_init();
	SCI_init();
	SPI_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	// GPIO31 -> LED0 Pinmux
	GPIO_setPinConfig(GPIO_31_GPIO31);
	// GPIO55 -> FLASH_CS Pinmux
	GPIO_setPinConfig(GPIO_55_GPIO55);
	// GPIO27 -> SCREEN_SCL Pinmux
	GPIO_setPinConfig(GPIO_27_GPIO27);
	// GPIO26 -> SCREEN_SDA Pinmux
	GPIO_setPinConfig(GPIO_26_GPIO26);
	//
	// SCIB -> mySCIB Pinmux
	//
	GPIO_setPinConfig(mySCIB_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(mySCIB_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCIB_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(mySCIB_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(mySCIB_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCIB_SCITX_GPIO, GPIO_QUAL_ASYNC);

	//
	// SPIA -> FLASH_SPI Pinmux
	//
	GPIO_setPinConfig(FLASH_SPI_SPIPICO_PIN_CONFIG);
	GPIO_setPadConfig(FLASH_SPI_SPIPICO_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FLASH_SPI_SPIPICO_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(FLASH_SPI_SPIPOCI_PIN_CONFIG);
	GPIO_setPadConfig(FLASH_SPI_SPIPOCI_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FLASH_SPI_SPIPOCI_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(FLASH_SPI_SPICLK_PIN_CONFIG);
	GPIO_setPadConfig(FLASH_SPI_SPICLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FLASH_SPI_SPICLK_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	LED0_init();
	FLASH_CS_init();
	SCREEN_SCL_init();
	SCREEN_SDA_init();
}

void LED0_init(){
	GPIO_writePin(LED0, 1);
	GPIO_setPadConfig(LED0, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED0, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED0, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED0, GPIO_CORE_CPU1);
}
void FLASH_CS_init(){
	GPIO_setPadConfig(FLASH_CS, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FLASH_CS, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(FLASH_CS, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(FLASH_CS, GPIO_CORE_CPU1);
}
void SCREEN_SCL_init(){
	GPIO_setPadConfig(SCREEN_SCL, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP | GPIO_PIN_TYPE_INVERT);
	GPIO_setQualificationMode(SCREEN_SCL, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SCREEN_SCL, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(SCREEN_SCL, GPIO_CORE_CPU1);
}
void SCREEN_SDA_init(){
	GPIO_setPadConfig(SCREEN_SDA, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP | GPIO_PIN_TYPE_INVERT);
	GPIO_setQualificationMode(SCREEN_SDA, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SCREEN_SDA, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(SCREEN_SDA, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
void SCI_init(){
	mySCIB_init();
}

void mySCIB_init(){
	SCI_clearInterruptStatus(mySCIB_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(mySCIB_BASE);
	SCI_resetTxFIFO(mySCIB_BASE);
	SCI_resetRxFIFO(mySCIB_BASE);
	SCI_resetChannels(mySCIB_BASE);
	SCI_setConfig(mySCIB_BASE, DEVICE_LSPCLK_FREQ, mySCIB_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(mySCIB_BASE);
	SCI_performSoftwareReset(mySCIB_BASE);
	SCI_setFIFOInterruptLevel(mySCIB_BASE, SCI_FIFO_TX0, SCI_FIFO_RX0);
	SCI_enableFIFO(mySCIB_BASE);
	SCI_enableModule(mySCIB_BASE);
}

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
void SPI_init(){
	FLASH_SPI_init();
}

void FLASH_SPI_init(){
	SPI_disableModule(FLASH_SPI_BASE);
	SPI_setConfig(FLASH_SPI_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
				  SPI_MODE_CONTROLLER, FLASH_SPI_BITRATE, FLASH_SPI_DATAWIDTH);
	SPI_setPTESignalPolarity(FLASH_SPI_BASE, SPI_PTE_ACTIVE_HIGH);
	SPI_disableFIFO(FLASH_SPI_BASE);
	SPI_disableLoopback(FLASH_SPI_BASE);
	SPI_setEmulationMode(FLASH_SPI_BASE, SPI_EMULATION_STOP_MIDWAY);
	SPI_enableModule(FLASH_SPI_BASE);
}


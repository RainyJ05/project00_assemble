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
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CMPSS_init();
	CPUTIMER_init();
	EPWM_init();
	EPWMXBAR_init();
	GPIO_init();
	SCI_init();
	SPI_init();
	INTERRUPT_init();

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
	
	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	// Analog PinMux for A0/B15/C15/DACA_OUT
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(231, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A1/B7/DACB_OUT
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(232, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A10/B1/C10
	GPIO_setPinConfig(GPIO_230_GPIO230);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(230, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A11/B10/C0
	GPIO_setPinConfig(GPIO_237_GPIO237);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(237, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A12, C5
	GPIO_setPinConfig(GPIO_238_GPIO238);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(238, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A14/B14/C4
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(239, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/B6/C9
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3, C7/B9
	GPIO_setPinConfig(GPIO_229_GPIO229);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(229, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A4/B8
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(225, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A5
	GPIO_setPinConfig(GPIO_249_GPIO249);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(249, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A6
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(228, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A8
	GPIO_setPinConfig(GPIO_240_GPIO240);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(240, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A9
	GPIO_setPinConfig(GPIO_227_GPIO227);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(227, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B0/C11
	GPIO_setPinConfig(GPIO_253_GPIO253);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(253, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B11
	GPIO_setPinConfig(GPIO_251_GPIO251);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(251, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B11, GPIO21
	GPIO_setPinConfig(GPIO_21_GPIO21);
	// AGPIO -> Analog mode selected
	// On 100PZ package for F28003x, if both "B5, GPIO20" and "B5" are selected as analog,
	// "B5, GPIO20" will drive the ADC instead of "B5"
	// On 100PZ package for F28003x, if both "B11, GPIO21" and "B11" are selected as analog,
	// "B11, GPIO21" will drive the ADC instead of "B11"
	GPIO_setAnalogMode(21, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B2/C6
	GPIO_setPinConfig(GPIO_226_GPIO226);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(226, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B3/VDAC
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(242, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B4/C8
	GPIO_setPinConfig(GPIO_236_GPIO236);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(236, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B5
	GPIO_setPinConfig(GPIO_252_GPIO252);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(252, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B5, GPIO20
	GPIO_setPinConfig(GPIO_20_GPIO20);
	// AGPIO -> Analog mode selected
	// On 100PZ package for F28003x, if both "B5, GPIO20" and "B5" are selected as analog,
	// "B5, GPIO20" will drive the ADC instead of "B5"
	// On 100PZ package for F28003x, if both "B11, GPIO21" and "B11" are selected as analog,
	// "B11, GPIO21" will drive the ADC instead of "B11"
	GPIO_setAnalogMode(20, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C1
	GPIO_setPinConfig(GPIO_248_GPIO248);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(248, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C14
	GPIO_setPinConfig(GPIO_247_GPIO247);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(247, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C2/B12
	GPIO_setPinConfig(GPIO_244_GPIO244);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(244, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C3/A7
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(245, GPIO_ANALOG_ENABLED);
	//
	// EPWM1 -> myEPWM1 Pinmux
	//
	GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO31 -> LED0 Pinmux
	GPIO_setPinConfig(GPIO_31_GPIO31);
	// GPIO55 -> FLASH_CS Pinmux
	GPIO_setPinConfig(GPIO_55_GPIO55);
	// GPIO27 -> SCREEN_SCL Pinmux
	GPIO_setPinConfig(GPIO_27_GPIO27);
	// GPIO26 -> SCREEN_SDA Pinmux
	GPIO_setPinConfig(GPIO_26_GPIO26);
	// GPIO57 -> KEY0 Pinmux
	GPIO_setPinConfig(GPIO_57_GPIO57);
	// GPIO58 -> KEY1 Pinmux
	GPIO_setPinConfig(GPIO_58_GPIO58);
	// GPIO59 -> KEY2 Pinmux
	GPIO_setPinConfig(GPIO_59_GPIO59);
	// GPIO44 -> TEST_GPIO Pinmux
	GPIO_setPinConfig(GPIO_44_GPIO44);
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
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	myADCA_init();
}

void myADCA_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(myADCA_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADCA_BASE, ADC_CLK_DIV_4_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADCA_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(myADCA_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADCA_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(myADCA_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADCA_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 12 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN0, 12U);
	ADC_setInterruptSOCTrigger(myADCA_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		Source	: ADC_SOC_NUMBER0
	// 		Interrupt Source: enabled
	// 		Continuous Mode	: disabled
	//
	//
	ADC_setInterruptSource(myADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
	ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);
	ADC_disableContinuousMode(myADCA_BASE, ADC_INT_NUMBER1);
	ADC_enableInterrupt(myADCA_BASE, ADC_INT_NUMBER1);
}

//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to external.
	//
	ASysCtl_setAnalogReferenceExternal( ASYSCTL_VREFHI );
}

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_init(){
	myCMPSS3_init();
}

void myCMPSS3_init(){
    //
    // Select the value for CMP3HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_3,2U);
    //
    // Select the value for CMP3LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_3,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(myCMPSS3_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(myCMPSS3_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(myCMPSS3_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(myCMPSS3_BASE,2500U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(myCMPSS3_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(myCMPSS3_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(myCMPSS3_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(myCMPSS3_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(myCMPSS3_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(myCMPSS3_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(myCMPSS3_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(myCMPSS3_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(myCMPSS3_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(myCMPSS3_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(myCMPSS3_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(myCMPSS3_BASE,false,false);
    //
    // Enables the CMPSS module.
    //
    CMPSS_enableModule(myCMPSS3_BASE);
    //
    // Delay for CMPSS DAC to power up.
    //
    DEVICE_DELAY_US(500);
}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 11U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 10000U);
	CPUTimer_enableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 3000);	
    EPWM_setTimeBaseCounter(myEPWM1_BASE, 0);	
    EPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_disablePhaseShiftLoad(myEPWM1_BASE);	
    EPWM_setPhaseShift(myEPWM1_BASE, 0);	
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 0);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(myEPWM1_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(myEPWM1_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);	
    EPWM_setRisingEdgeDelayCount(myEPWM1_BASE, 120);	
    EPWM_setDeadBandDelayMode(myEPWM1_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(myEPWM1_BASE);	
    EPWM_setFallingEdgeDelayCount(myEPWM1_BASE, 120);	
    EPWM_setTripZoneAction(myEPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_enableTripZoneSignals(myEPWM1_BASE, EPWM_TZ_SIGNAL_DCAEVT1);	
    EPWM_selectDigitalCompareTripInput(myEPWM1_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAH);	
    EPWM_setTripZoneDigitalCompareEventCondition(myEPWM1_BASE, EPWM_TZ_DC_OUTPUT_A1, EPWM_TZ_EVENT_DCXH_HIGH);	
    EPWM_enableADCTrigger(myEPWM1_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(myEPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(myEPWM1_BASE, EPWM_SOC_A, 1);	
}

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void EPWMXBAR_init(){
	myEPWMXBAR4_init();
}

void myEPWMXBAR4_init(){
		
	XBAR_setEPWMMuxConfig(myEPWMXBAR4, XBAR_EPWM_MUX04_CMPSS3_CTRIPH);
	XBAR_enableEPWMMux(myEPWMXBAR4, XBAR_MUX04);
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
	KEY0_init();
	KEY1_init();
	KEY2_init();
	TEST_GPIO_init();
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
void KEY0_init(){
	GPIO_setPadConfig(KEY0, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(KEY0, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(KEY0, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(KEY0, GPIO_CORE_CPU1);
}
void KEY1_init(){
	GPIO_setPadConfig(KEY1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(KEY1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(KEY1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(KEY1, GPIO_CORE_CPU1);
}
void KEY2_init(){
	GPIO_setPadConfig(KEY2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(KEY2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(KEY2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(KEY2, GPIO_CORE_CPU1);
}
void TEST_GPIO_init(){
	GPIO_setPadConfig(TEST_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(TEST_GPIO, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(TEST_GPIO, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(TEST_GPIO, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_myADCA_1
	Interrupt_register(INT_myADCA_1, &INT_myADCA_1_ISR);
	Interrupt_enable(INT_myADCA_1);
	
	// Interrupt Settings for INT_myCPUTIMER0
	Interrupt_register(INT_myCPUTIMER0, &INT_myCPUTIMER0_ISR);
	Interrupt_enable(INT_myCPUTIMER0);
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

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}

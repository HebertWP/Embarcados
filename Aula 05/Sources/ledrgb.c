/* ***************************************************************** */
/* File name:        ledrgb.c                                        */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related RGB LED from the FRDM-KL25Z board       */
/*                   controller. REMARKS LEDS are inverted output    */ 
/*                                                                   */
/* Author name:      Rodrigo M Bacurau                               */
/* Creation date:    26fev2020                                       */
/* Revision date:    02mar2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"


/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"


/* ************************************************ */
/* Method name: 	   ledrgb_init	         		*/
/* Method description: Initialize the RGB LED device*/
/* Input params:	   n/a                          */
/* Output params:	   n/a 							*/
/* ************************************************ */
void ledrgb_init(void)
{
	/* un-gate port clock*/
	CLOCK_SYS_EnablePortClock(PORTB_IDX);
	CLOCK_SYS_EnablePortClock(PORTD_IDX);

	/* set pin as gpio */
	PORT_HAL_SetMuxMode(RED_LED_PORT_BASE_PNT, RED_LED_PIN, kPortMuxAsGpio);
	PORT_HAL_SetMuxMode(GREEN_LED_PORT_BASE_PNT, GREEN_LED_PIN, kPortMuxAsGpio);
	PORT_HAL_SetMuxMode(BLUE_LED_PORT_BASE_PNT, BLUE_LED_PIN, kPortMuxAsGpio);

	/* set pin as digital output */
	GPIO_HAL_SetPinDir(RED_LED_GPIO_BASE_PNT, RED_LED_PIN, kGpioDigitalOutput);
	GPIO_HAL_SetPinDir(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN, kGpioDigitalOutput);
	GPIO_HAL_SetPinDir(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN, kGpioDigitalOutput);

	/* clear all leds */
	GPIO_HAL_SetPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);
	GPIO_HAL_SetPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);
	GPIO_HAL_SetPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
}



/* ************************************************ */
/* Method name: 	   ledrgb_write	         		*/
/* Method description: Write the color of the RGB   */
/*                     led.REMARKS LEDS are inverted*/
/* Input params:	   ucRGBColor 0..7 (0 = off     */
/*                     1 = red                      */
/*                     2 = green                    */
/*                     3 = red + green              */
/*                     4 = blue                     */
/*                     5 = blue + red               */
/*                     6 = blue + green             */
/*                     7 = blue + green + red)      */
/* Output params:	   n/a 							*/
/* ************************************************ */
void ledrgb_write(unsigned char ucRGBColor)
{
	// if ucRGBColor is 1, 3 or 7
	if (ucRGBColor & 1)
		// lights up red LED 
		GPIO_HAL_ClearPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);
	else
		// turn off red LED 
		GPIO_HAL_SetPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);

	// if ucRGBColor is 2, 3 or 6
	if (ucRGBColor & 2)
		// lights up green LED
		GPIO_HAL_ClearPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);
	else
		// turn off green LED
		GPIO_HAL_SetPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);

	// if ucRGBColor is 4, 5 or 6
	if (ucRGBColor & 4)
		// lights up blue LED 
		GPIO_HAL_ClearPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
	else
		// turn off blue LED
		GPIO_HAL_SetPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
}

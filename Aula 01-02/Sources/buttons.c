/*
 * buttons.c
 *
 *  Created on: 05/03/2020
 *  Author: Caio Villela
 *          Hebert Wandick
 */

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
void buttons_init(void)
{
	/* un-gate port clock*/
	CLOCK_SYS_EnablePortClock(PORTA_IDX);

	/* set pin as gpio */
	PORT_HAL_SetMuxMode(BUTTON_PORT_BASE_PNT, BUTTON_PIN, kPortMuxAsGpio);

	/* set pin as digital output */
	GPIO_HAL_SetPinDir(BUTTON_GPIO_BASE_PNT, BUTTON_PIN, kGpioDigitalInput);

	/* clear all leds */
	//GPIO_HAL_SetPinOutput(RED_LED_GPIO_BASE_PNT, RED_LED_PIN);
	//GPIO_HAL_SetPinOutput(GREEN_LED_GPIO_BASE_PNT, GREEN_LED_PIN);
	//GPIO_HAL_SetPinOutput(BLUE_LED_GPIO_BASE_PNT, BLUE_LED_PIN);
}

int button_read()
{
	 return (int)GPIO_HAL_ReadPinInput(BUTTON_GPIO_BASE_PNT,BUTTON_PIN);
}

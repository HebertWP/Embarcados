/* ***************************************************************** */
/* File name:        ledSwi.c                                        */
/* File description: This file implements the functions needed to    */
/*                   initialize, switch in between and operate RGB   */
/*                   leds and buttons                                */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    02apr2020                                       */
/* ***************************************************************** */

/* our includes */
#include "board.h"
#include "ledSwi.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

#define

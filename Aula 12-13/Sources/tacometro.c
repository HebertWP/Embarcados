/* ***************************************************************** */
/* File name:        tacometro.c  		                             */
/* File description: File containing the implementation of functions */
/*                   used to control the tacometro			         */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    08/may/2020                                     */
/* Revision date:    08/may/2020                                     */
/* ***************************************************************** */

/*my  includes*/
#include "board.h"
#include "tacometro.h"

/*system include*/
#include "fsl_clock_manager.h"

/* ************************************************ */
/* Method name:        tachometer_init              */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void tachometer_init(void){

}

/* ************************************************ */
/* Method name:        tachometer_readSensor        */
/* Method description: read cooler speed 			*/
/* Input params:       uiPeriod the period of		*/
/*  				   measurement 					*/
/* Output params:      cooler speed in RPM          */
/* ************************************************ */
unsigned int tachometer_readSensor(unsigned int uiPeriod){
	return 0;
}

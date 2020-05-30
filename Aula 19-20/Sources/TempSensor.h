/* ***************************************************************** */
/* File name:        TempSensor.h                                    */
/* File description: file containing the description of functions    */
/*                   used to control the Temperature sensor          */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    30/May/2020                                     */
/* Revision date:    30/May/2020                                     */
/* ***************************************************************** */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

/* ************************************************ */
/* Method name:        initTempSensor 	            */
/* Method description: Init Temperature sensor 	    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void initTempSensor(void);

/* ************************************************ */
/* Method name:        getTemp		                */
/* Method description: get Temperature		        */
/* Input params:       n/a                          */
/* Output params:      unsiged int with the current */
/*					   temperature 			        */
/* ************************************************ */
unsigned int getTemp();

#endif

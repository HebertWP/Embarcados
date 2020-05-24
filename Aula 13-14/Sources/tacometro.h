/* ***************************************************************** */
/* File name:        tacometro.h                                     */
/* File description: Header file containing the functions needed to  */
/*					 use tachometer 								 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    08/may/2020                                     */
/* Revision date:    08/may/2020                                     */
/* ***************************************************************** */
#ifndef TACOMETRO_H_
#define TACOMETRO_H_

/* ************************************************ */
/* Method name:        tachometer_init              */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void tachometer_init(void);

/* ************************************************ */
/* Method name:        tachometer_readSensor        */
/* Method description: read cooler speed 			*/
/* Input params:       uiPeriod the period of		*/
/*  				   measurement 					*/
/* Output params:      cooler speed in RPM          */
/* ************************************************ */
unsigned int tachometer_readSensor(unsigned int uiPeriod);

#endif

/* ***************************************************************** */
/* File name:        TempSensor.c                                    */
/* File description: Measurement Temperature 				         */
/* Author name:      Hebert Wandick, Caio Villela 	                 */
/* Creation date:    30/May/2020                                     */
/* Revision date:    30/May/2020                                     */
/* ***************************************************************** */

#include "adc.h"
#include "lut_adc_3v3.h"

/* ************************************************ */
/* Method name:        initTempSensor 	            */
/* Method description: Init Temperature sensor 	    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void initTempSensor(void){
	adc_initADCModule();
};

/* ************************************************ */
/* Method name:        getTemp		                */
/* Method description: get Temperature		        */
/* Input params:       n/a                          */
/* Output params:      unsiged int with the current */
/*					   temperature 			        */
/* ************************************************ */
unsigned int getTemp(){
	adc_initConvertion();
	while(!adc_isAdcDone());
	int iAux=adc_getConvertionValue();
	return tabela_temp[255-iAux];
};

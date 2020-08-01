/* ***************************************************************** */
/* File name:        adc.h                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the ADC from the peripheral board.      */
/*                   The converter is connected to the Temperature   */
/*                   sensor.                                         */
/* Author name:      dloubach, julioalvesMS, IagoAF e rbacurau       */
/* Creation date:    07jun2018                                       */
/* Revision date:    20mai2020                                       */
/* ***************************************************************** */

#ifndef SOURCES_ADC_H_
#define SOURCES_ADC_H_


/* *************************************************** */
/* Method name:        adc_initADCModule               */
/* Method description: Init a the ADC converter device */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */
void adc_initADCModule(void);


/* ************************************************** */
/* Method name:        adc_initConvertion             */
/* Method description: init a conversion from A to D  */
/* Input params:       n/a                            */
/* Output params:      n/a                            */
/* ************************************************** */
void adc_initConvertion(void);


/* ************************************************** */
/* Method name:        adc_isAdcDone                  */
/* Method description: check if conversion is done    */
/* Input params:       n/a                            */
/* Output params:      char: 1 if Done, else 0        */
/* ************************************************** */
char adc_isAdcDone(void);


/* ************************************************** */
/* Method name:        adc_getConvertionValue         */
/* Method description: Retrieve converted value       */
/* Input params:       n/a                            */
/* Output params:      int: Result from convertion    */
/* ************************************************** */
int adc_getConvertionValue(void);


#endif /* SOURCES_ADC_H_ */

/* ***************************************************************** */
/* File name:        aquecedorECooler.h                              */
/* File description: Header file containing the functions needed to	 */
/* 					 use heater and cooler                           */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    10/apr/2020                                     */
/* Revision date:    26/jul/2020                                     */
/* ***************************************************************** */

#ifndef AQUECEDORECOOLER_H_
#define AQUECEDORECOOLER_H_

/* ************************************************ */
/* Method name:        PWM_init	                    */
/* Method description: Initialize PWM				*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void PWM_init(void);

/* ************************************************ */
/* Method name:        coolerfan_init               */
/* Method description: Initialize coolerfan			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void coolerfan_init(void);

/* ************************************************ */
/* Method name:        heater_init		            */
/* Method description: Initialize heater			*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void heater_init(void);

/* ************************************************ */
/* Method name:        coolerfan_PWMDuty            */
/* Method description: set the coolerfan speed		*/
/* Input params:       fCoolerDuty how many 		*/
/* 					   percentage time the cooler 	*/
/* 					   will be in high				*/
/* Output params:      n/a                          */
/* ************************************************ */
void coolerfan_PWMDuty(float fCoolerDuty);

/* ************************************************ */
/* Method name:        heater_PWMDuty	            */
/* Method description: set the heater power			*/
/* Input params:       fHeaterDuty how many 		*/
/* 					   percentage time the cooler 	*/
/* 					   will be in high				*/
/* Output params:      n/a                          */
/* ************************************************ */
void heater_PWMDuty(float fHeaterDuty);

#endif

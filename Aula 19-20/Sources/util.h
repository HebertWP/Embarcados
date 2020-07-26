/* ***************************************************************** */
/* File name:        util.h                                          */
/* File description: Header file containing the function/methods     */
/*                   prototypes of util.c                            */
/*                   Those delays were tested under the following:   */
/*                   core clock @ 40MHz                              */
/*                   bus clock @ 20MHz                               */
/* Author name:      dloubach/Hebert W/Caio V                        */
/* Creation date:    09jan2015                                       */
/* Revision date:    26jul2020                                       */
/* ***************************************************************** */

#ifndef UTIL_H
#define UTIL_H

/* ************************************************ */
/* Method name:        util_genDelay088us           */
/* Method description: generates ~ 088 micro sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay088us(void);


/* ************************************************ */
/* Method name:        util_genDelay250us           */
/* Method description: generates ~   250 micro sec  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay250us(void);


/* ************************************************ */
/* Method name:        util_genDelay1ms             */
/* Method description: generates ~   1 mili sec     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay1ms(void);


/* ************************************************ */
/* Method name:        util_genDelay10ms            */
/* Method description: generates ~   10 mili sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay10ms(void);

/* ************************************************ */
/* Method name:        util_genDelay10ms            */
/* Method description: generates ~   100 mili sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay100ms(void);

/* ************************************************ */
/* Method name:        setParam				        */
/* Method description: set the temperature or led in*/
/* 					   machine						*/
/* 					   uint8_t						*/
/* Input params:       ucParam type of parameter  to*/
/*					   be set						*/
/*					   ucByte array of information  */
/* Output params:      n/a	 				        */
/* ************************************************ */
void setParam(unsigned char ucParam, unsigned char *ucByte);

/* ************************************************ */
/* Method name:        answerParam			        */
/* Method description: return the corresponding     */
/*					   information 					*/
/* Input params:       ucParam type of parameter  to*/
/*					   be get 						*/
/* Output params:      n/a	 				        */
/* ************************************************ */
void answerParam(unsigned char ucParam);


#endif /* UTIL_H */

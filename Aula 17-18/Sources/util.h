/* ***************************************************************** */
/* File name:        util.h                                          */
/* File description: Header file containing the function/methods     */
/*                   prototypes of util.c                            */
/*                   responsible for intermediating the state machine*/
/*					 and hardware 									 */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    24/may/2020                                     */
/* Revision date:    24/may/2020                                     */
/* ***************************************************************** */

#ifndef UTIL_H
#define UTIL_H

/* ****************************************************/
/* Method name:        floatToUChar     		          */
/* Method description: converts 4 unsiged chars to 1  */
/* 					           float  		                    */
/* Input params:       ucValue array character to be  */
/*					           converted 					            */
/* Output params:      1 float                        */
/* ****************************************************/
float uCharToFloat(unsigned char* ucValue);

/* ****************************************************/
/* Method name:        floatToUChar     		          */
/* Method description: converts 1 float to 4 unsigned */
/* 					           chars  		                    */
/* Input params:       fValue character to be         */
/*					           converted 					            */
/* Output params:      4 unsigned char array          */
/* ****************************************************/
unsigned char* floatToUChar(int flag, float fReceived);

/* ************************************************ */
/* Method name:        setParam				              */
/* Method description: set the temperature or led in*/
/* 					           machine						          */
/* 					           						                  */
/* Input params:     ucParam -> type of parameter to*/
/*					         be set           						  */
/*					         ucByte -> array of information */
/* Output params:      n/a	 				                */
/* ************************************************ */
void setParam(unsigned char ucParam, unsigned char *ucByte);

/* ************************************************ */
/* Method name:        answerParam			            */
/* Method description: return the corresponding     */
/*					           information 					        */
/* Input params:       ucParam -> what parameter is */
/*					           to be returned               */
/* Output params:      n/a	 				                */
/* ************************************************ */
void answerParam(unsigned char ucParam);

/* ************************************************ */
/* Method name:        sendByteUART			            */
/* Method description: sends byte via UART          */
/* Input params:       ucByte -> Byte to be sent    */
/* Output params:      n/a	 				                */
/* ************************************************ */
void sendByteUART(unsigned char ucByte);


/* ************************************************ */
/* Method name:        getByteUART			            */
/* Method description: reads byte via UART          */
/* Input params:       n/a                          */
/* Output params:      read Byte  	                */
/* ************************************************ */
unsigned char getByteUART();




#endif

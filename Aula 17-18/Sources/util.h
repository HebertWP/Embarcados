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

#endif

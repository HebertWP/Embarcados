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

void processByteCommunication(unsigned char ucByte);
void answerParam(ucParam, ucByte);
#endif
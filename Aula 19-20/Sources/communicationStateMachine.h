/* ***************************************************************** */
/* File name:        communicationStateMachine.h                     */
/* File description: Implements the State machine, discribe in .pdf  */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    24/may/2020                                     */
/* Revision date:    24/may/2020                                     */
/* ***************************************************************** */
#ifndef COMMUNICATIONSTATEMACHINE_H_
#define COMMUNICATIONSTATEMACHINE_H_

/* ************************************************ */
/* Method name:        processByteCommunication     */
/* Method description: Handle what to do by 		*/
/* 					   corresponding byte and order */
/* Input params:       ucByte the byte received		*/
/* Output params:      n/a                          */
/* ************************************************ */
void processByteCommunication(unsigned char ucByte);


enum state{
    IDLE,
    READY,
    GET,
    SET,
    PARAM,
    FLOAT_VALUE,
    BUTTON_VALUE,
    SET_VALUE,
    ANSWER,
    TARGETTEMP,
    TARGETKD,
    TARGETKI,
    TARGETKP,
    GETDUTY
};

enum state getState();
#endif

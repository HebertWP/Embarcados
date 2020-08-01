/* ***************************************************************** */
/* File name:        communicationStateMachine.c                     */
/* File description: Implements the state machine using the util.h 	 */
/* 					 file to implements the responsive acts 		 */
/* 					 through UART interface    			             */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    24/may/2020                                     */
/* Revision date:    24/may/2020                                     */
/* ***************************************************************** */

/*my includes*/
#include "util.h"
#include "communicationStateMachine.h"
#include "board.h"

unsigned char ucUartState = IDLE;
unsigned char ucValueCount = 0;
int iCommaPos = 0, iAuxCommaPos = 0, iFlag = 0;
bool bPidConfig = false;

enum state esUartState = IDLE;
/* ************************************************ */
/* Method name:        processByteCommunication     */
/* Method description: Handle what to do by 		*/
/* 					   corresponding byte and order */
/* Input params:       ucByte the byte received		*/
/* Output params:      n/a                          */
/* ************************************************ */
void processByteCommunication(unsigned char ucByte)
{

    static unsigned char ucParam;
    static unsigned char ucValue[MAX_VALUE_LENGTH + 2];
    switch (esUartState)
    {
    case IDLE: /*wait for UART comand*/
        switch (ucByte)
        {
        case '#': /*UART Comand arive */
            esUartState = READY;
            break;
        case '@':/*progrming via Local interface*/
            esUartState = TARGETTEMP;
        }
        break;
    case TARGETTEMP:/*condiguring controled temperature*/
        switch (ucByte)
        {
        case '@':/*go to next menu*/
            esUartState = TARGETKP;
            break;
        case '>':/*going up*/
            setParam('T', "u");
            break;
        case '<':/*going dow*/
            setParam('T', "d");
            break;
        default:
            esUartState = IDLE;/*some one send comand via uart in same time, wi back idle state, before acet nem orders */
        }
        break;

    case TARGETKP:/*set KP*/
        switch (ucByte)
        {
        case '@':/*next menu */
            esUartState = TARGETKD;
            break;
        case '>':/*up*/
            setParam('P', "u");
            break;
        case '<':/*dow*/
            setParam('P', "d");
            break;
        default:
            esUartState = IDLE;/*some one send comand via uart in same time, wi back idle state, before acet nem orders */
        }
        break;

    case TARGETKD:/*same logic in here*/
        bPidConfig = true;
        switch (ucByte)
        {
        case '@':
            esUartState = TARGETKI;
            break;
        case '>':
            setParam('D', "u");
            break;
        case '<':
            setParam('D', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;
    case TARGETKI:
        switch (ucByte)
        {
        case '@':
            esUartState = DUTYHEATER;
            break;
        case '>':
            setParam('I', "u");
            break;
        case '<':
            setParam('I', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;

    case DUTYCOOLER:
        bPidConfig = false;
        switch (ucByte)
        {
        case '@':
            esUartState = DUTYHEATER;
            break;
        case '>':
            setParam('C', "u");
            break;
        case '<':
            setParam('C', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;

    case DUTYHEATER:
        esUartState = IDLE;
        break;

    case READY:
        switch (ucByte)
        {
        case 'g':/*get infamation */
            esUartState = GET;
            break;

        case 's':/*set varieble */
            esUartState = SET;
            break;
        case '@':
        case '<':
        case '>':/*case some on click on local inteface it will not interfere*/
            break;
        default:
            esUartState = IDLE;
        }
        break;

    case GET:
        switch (ucByte)
        {
        case 't':/* temperature now*/
        case 'c':/* cooler*/
        case 'a':/* resistor*/
        case 'i': /*ki*/
        case 'd': /*kd*/
        case 'p': /*kp*/
        case 'b': /*botaão*/
        case 's': /*temp to control*/
            ucParam = ucByte;
            esUartState = PARAM;
            break;
        case '@':
        case '<':
        case '>':/*case some on click on local inteface it will not interfere*/
            break;
        default:
            esUartState = IDLE;
            break;
        }
        break;

    case SET:
        switch (ucByte)
        {
        case 'c': /*cooler*/
        case 'i':/*ki*/
        case 'd':/*kd*/
        case 'p':/*Kp*/
        case 's':/*Temp to control*/
            ucParam = ucByte;
            ucValueCount = 0;
            esUartState = FLOAT_VALUE;
            break;
        case 'b':/*button*/
            ucParam = ucByte;
            iFlag = 0;
            esUartState = BUTTON_VALUE;
            break;
        case '@':
        case '<':
        case '>':
            break;
        default:
            esUartState = IDLE;
            break;
        }
        break;

    case PARAM:
        if (';' == ucByte)
            answerParam(ucParam);
        if (ucByte == '@' || ucByte == '<' || ucByte == '>')
            ;
        else
            esUartState = IDLE;
        break;

    case FLOAT_VALUE:
        switch (ucByte)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case ',':
            if (ucValueCount < MAX_VALUE_LENGTH)
            {
                ucValue[ucValueCount++] = ucByte;
                iAuxCommaPos++;
            }
            else
            {
                esUartState = IDLE;
            }
            break;
        case '@':
        case '<':
        case '>':
            break;
        case ';':
            ucValue[ucValueCount] = '\0';
            setParam(ucParam, ucValue);
            esUartState = IDLE;
            break;
        default:
            esUartState = IDLE;
            break;
        }
        break;

    case BUTTON_VALUE:
        if (iFlag == 0)
        {
            if ('0' == ucByte || '1' == ucByte)
            {
                iFlag++;
                ucValue[0] = ucByte;
            }
        }
        else
        {
            if (';' == ucByte)
                setParam(ucParam, ucValue);

            if (ucByte == '@' || ucByte == '<' || ucByte == '>')
                ;
            else
                esUartState = IDLE;
            break;
        }
    }
}

/* ************************************************ */
/* Method name:        getState                     */
/* Method description: Return in witch state the    */
/*                     state machine are            */
/* Input params:       n/a                  		*/
/* Output params:      enum state                   */
/* ************************************************ */
enum state getState(void)
{
    return esUartState;
}

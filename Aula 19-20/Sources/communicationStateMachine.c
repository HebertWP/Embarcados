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
#include "communicationStateMachine.h"
#include "util.h"

#define MAX_VALUE_LENGTH 3
enum state esUartState = IDLE;

unsigned char ucValueCount;

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
    static unsigned char ucValue[MAX_VALUE_LENGTH + 1];
    switch (esUartState)
    {
    case IDLE:
        switch (ucByte)
        {
        case '#':
            esUartState = READY;
            break;
        case '@':
            esUartState = TARGETTEMP;
        }
        break;
    case TARGETTEMP:
        switch (ucByte)
        {
        case '@':
            esUartState = TARGETKD;
            break;
        case '>':
            setParam('T', "u");
            break;
        case '<':
            setParam('T', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;
    case TARGETKD:
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
            esUartState = TARGETKP;
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
    case TARGETKP:
        switch (ucByte)
        {
        case '@':
            esUartState = DUTYHEATER;
            break;
        case '>':
            setParam('P', "u");
            break;
        case '<':
            setParam('P', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;
    case DUTYHEATER:
        switch (ucByte)
        {
        case '@':
            esUartState = DUTYCOOLER;
            break;
        case '>':
            setParam('H', "u");
            break;
        case '<':
            setParam('H', "d");
            break;
        default:
            esUartState = IDLE;
        }
        break;

    case DUTYCOOLER:
        esUartState = IDLE;
        break;

    case READY:
        switch (ucByte)
        {
        case 'g':
            esUartState = GET;
            break;

        case 's':
            esUartState = SET;
            break;

        default:
            esUartState = IDLE;
        }
        break;

    case GET:
        switch (ucByte)
        {
        case 't':
        case 'c':
        case 'a':
        case 'i':
        case 'k':
        case 'p':
        case 'b':
            ucParam = ucByte;
            esUartState = PARAM;
            break;
        default:
            esUartState = IDLE;
            break;
        }
        break;

    case SET:
        if ('a' == ucByte || 'i' == ucByte || 'p' == ucByte|| 'd' == ucByte || 's' == ucByte)
        {
            ucParam = ucByte;
            ucValueCount = 0;
            esUartState = FLOAT_VALUE;
        }
        else if ('b' == ucByte)
        {
            ucParam = ucByte;
            esUartState = BUTTON_VALUE;
        }
        else
            esUartState = IDLE;
        break;

    case PARAM:
        if (';' == ucByte)
            answerParam(ucParam);
        esUartState = IDLE;
        break;

    case FLOAT_VALUE:
        if (ucByte >= '0' && ucByte <= '9')
        {
            if (ucValueCount < MAX_VALUE_LENGTH)
                ucValue[ucValueCount++] = ucByte;
        }
        else
        {
            if (';' == ucByte)
            {
                ucValue[ucValueCount] = '\0';
                setParam(ucParam, ucValue);
            }
            esUartState = IDLE;
        }
        break;

    case BUTTON_VALUE:
        if ('0' == ucByte || '1' == ucByte)
        {
            ucValue[0] = ucByte;
        }
        else
        {
            if (';' == ucByte)
                setParam(ucParam, ucValue);
            esUartState = IDLE;
        }
        break;
    }
}

enum state getState(void)
{
    return esUartState;
}

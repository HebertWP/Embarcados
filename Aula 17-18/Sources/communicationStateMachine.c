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
#include "board.h"
/*        GLOBAL VARIABLES         */
/*  ucUartState == Current state   */
/*  ucValueCont == Position of     */
/*                 float input     */  
/*                 inside the      */
/*                 array           */
/*  iCommaPos == Position of comma */
/*              inside float array */
/*  iAuxCommaPos == Auxiliary      */
/*                  iterator       */
/***********************************/

unsigned char ucUartState = IDLE;
unsigned char ucValueCount = 0;
int iCommaPos = 0, iAuxCommaPos = 0, iFlag = 0;

/* ************************************************ */
/* Method name:        processByteCommunication     */
/* Method description: Handle what to do by 		*/
/* 					   corresponding byte and order */
/* Input params:       ucByte, received byte 		*/
/* Output params:      n/a                          */
/* ************************************************ */
void processByteCommunication(unsigned char ucByte)
{

    static unsigned char ucParam;
    static unsigned char ucValue[MAX_VALUE_LENGTH + 1];


    /*the following logic can be better understood through the adjacent
      pdf file*/


    /*starts implementation*/
    if ('#' == ucByte)
        ucUartState = READY;

    else if (IDLE != ucUartState)
        switch (ucUartState)
        {
        
        case READY:
            switch (ucByte)
            {
            case 'g':
                ucUartState = GET;
                break;

            case 's':
                ucUartState = SET;
                break;

            default:
                ucUartState = IDLE;
            }
            break;

        case GET:
            if ('t' == ucByte || 'c' == ucByte || 'a' == ucByte)
            {
                ucParam = ucByte;
                ucUartState = PARAM;
            }
            else
                ucUartState = IDLE;
            break;

        case SET:
            if ('t' == ucByte)
            {
                ucParam = ucByte;
                ucValueCount = 0;
                iCommaPos = 0;
                iAuxCommaPos = 0;
                ucUartState = FLOAT_VALUE;
            }
            else if ('b' == ucByte)
            {
                ucParam = ucByte;
                iFlag = 0;
                ucUartState = BUTTON_VALUE;
            }
            else
                ucUartState = IDLE;
            break;

        case PARAM:
            if (';' == ucByte)
                answerParam(ucParam);
            ucUartState = IDLE;
            break;

        case FLOAT_VALUE:
            if (ucByte >= '0' && ucByte <= '9')
            {
                if (ucValueCount < MAX_VALUE_LENGTH)
                {
                    ucValue[ucValueCount++] = ucByte;
                    iAuxCommaPos ++;
                }
            }
            else if (ucByte == ','){
                iCommaPos = iAuxCommaPos;
            }

            else          
            {
                if (';' == ucByte)
                {
                    ucValue[ucValueCount] = '\0';
                    setParam(ucParam, ucValue, iCommaPos);
                }
                ucUartState = IDLE;
            }
            break;

        case BUTTON_VALUE:
            if (iFlag == 0 ){
                if ('0' == ucByte || '1' == ucByte)
                {
                    iFlag++;
                    ucValue[0] = ucByte;
                }
            }
            else
            {
                if (';' == ucByte)
                    setParam(ucParam, ucValue, iCommaPos);
                
                ucUartState = IDLE;
            }
            break;
        }
}
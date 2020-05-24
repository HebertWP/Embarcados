/* ***************************************************************** */
/* File name:        util.c                                          */
/* File description: This file has a couple of useful functions to   */
/*                   make programming more productive                */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    24/may/2020                                     */
/* Revision date:    24/may/2020                                     */
/* ***************************************************************** */

/*system includes*/
#include "stdint.h"

/*my includes*/
#include "util.h"
#include "fsl_debug_console.h"

/*union variable used for converting unsigned chars/floats */
typedef union
{
  unsigned char ucBytes[4];
  float fReal;
}floatUCharType;


/* ****************************************************/
/* Method name:        floatToUChar     		          */
/* Method description: converts 4 unsiged chars to 1  */
/* 					           float  		                    */
/* Input params:       ucValue array character to be  */
/*					           converted 					            */
/* Output params:      1 float                        */
/* ****************************************************/

float uCharToFloat(unsigned char* ucValue){
  floatUCharType varFloatUChar;

  varFloatUChar.ucBytes = ucValue;
  return(varFloatUChar.fReal);
}


/* ****************************************************/
/* Method name:        floatToUChar     		          */
/* Method description: converts 1 float to 4 unsigned */
/* 					           chars  		                    */
/* Input params:       fValue character to be         */
/*					           converted 					            */
/* Output params:      4 unsigned char array          */
/* ****************************************************/

unsigned char* floatToUChar(int flag, float fReceived){
  floatUCharType varFloatUChar;
  unsigned char ucSendChar[4];
  int iCount;

  varFloatUChar.fReal = fReceived;
  return(varFloatUChar.ucBytes);

}

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
void setParam(unsigned char ucParam, unsigned char *ucByte)
{
    if ('b' == ucParam)
    {
        if ('0' == ucByte[0])
        {
            /*turn off button*/
            /*test was supposed to use the debug mode with a break point in here*/
        }
        else
        {
            /*test was supposed to use the debug mode with a break point in here*/
            /*turn on button*/
        }
    }

    if ('v' == ucParam)
    {


    }
}

/* ************************************************ */
/* Method name:        answerParam			            */
/* Method description: return the corresponding     */
/*					           information 					        */
/* Input params:       ucParam -> what parameter is */
/*					           to be returned               */
/* Output params:      n/a	 				                */
/* ************************************************ */

void answerParam(unsigned char ucParam)
{
    float fTemp;
    float fCy;
    switch (ucParam)
    {
    case 't':
        /* return the temperature*/
        fTemp = 23.37;

        break;

    case 'c':
        /* return the cooler duty cycle*/
        fCy = 0.1;

        break;

    case 'a':
        /*return  the header duty cycle*/
        fCy = 1;

        break;
    };
}

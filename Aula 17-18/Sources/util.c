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
#include "math.h" 
#include "util.h"
#include "board.h"
#include "fsl_debug_console.h"

#define HASHTAG 0b00100011
#define LETRA_A 0b01100001
#define PONTO_VIRGULA 0b00111011

/*union variable used for converting unsigned chars/floats */
typedef union {
    unsigned char ucBytes[4];
    int iReal;
} floatUCharType;

/* ************************************************** */
/* Method name:        floatToUChar     		      */
/* Method description: converts 4 unsiged chars to 1  */
/* 					           float  		          */
/* Input params:       ucValue array character to be  */
/*					           converted 			  */
/* Output params:      1 float                        */
/* ****************************************************/
float uCharToFloat(unsigned char *ucValue, int iCommaPos)
{
    float fFloat;

    floatUCharType varFloatUChar;
    int iI;
    for (iI = 0; iI < 4; iI++)
    {
        varFloatUChar.ucBytes[iI] = ucValue[iI];
    }

    fFLoat = varFloatUChar.iReal / pow(10, 4 - iCommaPos)
    return (fFloat);
}

/* ************************************************** */
/* Method name:        floatToUChar     		      */
/* Method description: converts 1 float to 4 unsigned */
/* 					           chars  		          */
/* Input params:       fValue character to be         */
/*					           converted 			  */
/* Output params:      4 unsigned char array          */
/* ************************************************** */
floatUCharType varFloatUChar;
unsigned char *floatToUChar(float fReceived)
{
    varFloatUChar.fReal = fReceived;
    return (varFloatUChar.ucBytes);
}

/* ******************************************************** */
/* Method name:        setParam                             */
/* Method description: set the temperature or led in        */
/* 					           machine				        */
/* 					           						        */
/* Input params:    ucParam -> type of parameter to be set  */
/*					         ucByte -> array of information */
/*                           iCommaPos -> position of comma */
/*                           in float values.               */
/* Output params:      n/a	 				                */
/* **********************************************************/
void setParam(unsigned char ucParam, unsigned char *ucByte, int iCommaPos)
{
    float fTemp;

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

    if ('t' == ucParam)
    {
        fTemp = uCharToFloat(ucByte, iCommaPos);
        /*setTemperature(fTemp)*/
        /*ainda nao temos essa funcao*/
    }
    /*sending "#a;" to corfirm*/
    debug_putchar(HASHTAG);
    debug_putchar(LETRA_A);
    debug_putchar(PONTO_VIRGULA);
}

/* ************************************************ */
/* Method name:        answerParam			        */
/* Method description: return the corresponding     */
/*					           information 			*/
/* Input params:       ucParam -> what parameter is */
/*					           to be returned       */
/* Output params:      n/a	 				        */
/* ************************************************ */

void answerParam(unsigned char ucParam)
{
    float fTemp;
    float fCy;
    unsigned char *ucValue = malloc(4 * sizeof(unsigned char));
    int iI;

    debug_putchar(HASHTAG);
    debug_putchar(LETRA_A);

    switch (ucParam)
    {
    case 't':
        /* return the temperature*/
        /* fTemp = getTemp()*/
        fTemp = 23.37;

        ucValue = floatToUChar(fTemp);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;

    case 'c':
        /* return the cooler duty cycle*/
        /* fCy = getCoolerDutyCycle()*/
        fCy = 0.1;
        ucValue = floatToUChar(fCy);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;

    case 'a':
        /*return  the heater duty cycle*/
        /* fCy = getHeaterDutyCycle()*/
        fCy = 1.2;
        ucValue = floatToUChar(fCy);

        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;
    };
    free(ucValue);
    debug_putchar(PONTO_VIRGULA);
}

/* ***************************************************************** */
/* File name:        util.c                                          */
/* File description: This file has a couple of useful functions to   */
/*                   make programming more productive                */
/*                                                                   */
/*                   Remarks: The soft delays consider               */
/*                   core clock @ 40MHz                              */
/*                   bus clock @ 20MHz                               */
/*                                                                   */
/* Author name:      dloubach                                        */
/* Creation date:    09jan2015                                       */
/* Revision date:    21mar2016                                       */
/* ***************************************************************** */

/*system includes*/
#include "stdint.h"

/*my includes*/
#include "util.h"
#include "fsl_debug_console.h"


#include "util.h"
#include "aquecedorECooler.h"
float fColler=0;
float fHeader=0;
/* ************************************************ */
/* Method name:        util_genDelay088us           */
/* Method description: generates ~ 088 micro sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay088us(void)
{
    char i;
    for(i=0; i<120; i++)
    {
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
    }
}



/* ************************************************ */
/* Method name:        util_genDelay250us           */
/* Method description: generates ~   250 micro sec  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay250us(void)
{
    char i;
    for(i=0; i<120; i++)
    {
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
        __asm("NOP");
    }
    util_genDelay088us();
    util_genDelay088us();
}



/* ************************************************ */
/* Method name:        util_genDelay1ms             */
/* Method description: generates ~   1 mili sec     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay1ms(void)
{
    util_genDelay250us();
    util_genDelay250us();
    util_genDelay250us();
    util_genDelay250us();
}


/* ************************************************ */
/* Method name:        util_genDelay10ms            */
/* Method description: generates ~   10 mili sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay10ms(void)
{
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
    util_genDelay1ms();
}



/* ************************************************ */
/* Method name:        util_genDelay100ms           */
/* Method description: generates ~   100 mili sec   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay100ms(void)
{
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
    util_genDelay10ms();
}

#define HASHTAG 0b00100011
#define LETRA_A 0b01100001
#define PONTO_VIRGULA 0b00111011

/*union variable used for converting unsigned chars/floats */
typedef union {
    unsigned char ucBytes[4];
    float fReal;
} floatUCharType;

/* ************************************************** */
/* Method name:        floatToUChar     		      */
/* Method description: converts 4 unsiged chars to 1  */
/* 					           float  		          */
/* Input params:       ucValue array character to be  */
/*					           converted 			  */
/* Output params:      1 float                        */
/* ****************************************************/
float uCharToFloat(unsigned char *ucValue)
{
    floatUCharType varFloatUChar;
    int iI;
    for (iI = 0; iI < 4; iI++)
    {
        varFloatUChar.ucBytes[iI] = ucValue[iI];
    }
    return (varFloatUChar.fReal);
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
/* Input params:     ucParam -> type of parameter to be set */
/*					         ucByte -> array of information */
/* Output params:      n/a	 				                */
/* ************************************************ */
void setParam(unsigned char ucParam, unsigned char *ucByte)
{
    float fTemp;
    switch (ucParam){
    case 'b':
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
        break;
    case 't':
        fTemp = uCharToFloat(ucByte);
        /*setTemperature(fTemp)*/
        /*ainda nao temos essa funcao*/
        break;
    case 'c':
        /*set coller speed*/
        fColler = uCharToFloat(ucByte);
        fColler=(fColler>0.5)? 0.5: fColler;
        coolerfan_PWMDuty(fColler);
        
    	break;
    case 'a':
        /*set resitor power*/
        fHeader = uCharToFloat(ucByte);
    	fHeader=(fHeader>0.5)? 0.5: fHeader;
        heater_PWMDuty(fHeader);
        break;
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
        ucValue = floatToUChar(fColler);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;

    case 'a':
        /*return  the heater duty cycle*/
        /* fCy = getHeaterDutyCycle()*/
        ucValue = floatToUChar(fHeader);

        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;
    };
    free(ucValue);
    debug_putchar(PONTO_VIRGULA);
}

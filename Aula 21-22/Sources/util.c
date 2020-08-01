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
#include "communicationStateMachine.h"
#include "lcd.h"
#include "pid.h"

/*union variable used for converting unsigned chars/floats */
typedef union {
    unsigned char ucBytes[4];
    int iReal;
} floatUCharType;

unsigned char ucTempNow = 't';
floatUCharType varFloatUChar;

/* ************************************************ */
/* Method name:        util_genDelay088us           */
/* Method description: generates ~ 088 micro sec    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void util_genDelay088us(void)
{
    char i;
    for (i = 0; i < 120; i++)
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
    for (i = 0; i < 120; i++)
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


/* ************************************************** */
/* Method name:        floatToUChar     		      */
/* Method description: converts 6 unsiged chars to 1  */
/* 					           float  		          */
/* Input params:       ucValue array character to be  */
/*					           converted 			  */
/*                     frec high decimal unity        */
/* Output params:      1 float                        */
/* ****************************************************/
float uCharToFloat(unsigned char *ucValue, float frec)
{
    if (*ucValue == '\0')
        return 0;
    if (*ucValue == ',')
        return uCharToFloat(&(ucValue[1]), frec);
    return frec * ((float)((int)*ucValue - 48)) + uCharToFloat(&(ucValue[1]), frec / 10);
}

/* ************************************************** */
/* Method name:        floatToUChar     		      */
/* Method description: converts 1 float to 4 unsigned */
/* 					           chars  		          */
/* Input params:       fValue character to be         */
/*					           converted 			  */
/* Output params:      4 unsigned char array          */
/* ************************************************** */
unsigned char *floatToUChar(float fReceived)
{

    varFloatUChar.iReal = fReceived;
    return (varFloatUChar.ucBytes);
}

bool bLock = false; /* auv varible to look the keys */

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
    static float fCooler = 0;
    static float fHeater = 0;

    switch (ucParam)
    {
    case 'b':
        if ('0' == ucByte[0])
        {
            /*turn off button*/
            bLock = false;
        }
        else
        {
            /*turn on button*/
            bLock = true;
        }
        break;
    case 'c':
        /*set resitor power*/
        fCooler = uCharToFloat(ucByte, 100);
        fCooler = (fCooler > 50) ? 0.5 : fCooler / 100;
        coolerfan_PWMDuty(fCooler);
        break;
    case 'i':
        /*set Ki in PID*/
        pid_setKi(uCharToFloat(ucByte, 100));
        break;
    case 'p':
        /*set Kp in PID*/
        pid_setKi(uCharToFloat(ucByte, 100));
        break;
    case 'd':
        /*set Kd in PID*/
        pid_setKi(uCharToFloat(ucByte, 100));
        break;
    case 's':
        /*set target temperature */
        pid_setSetValue(uCharToFloat(ucByte, 100));

    case 'C':
        if (!bLock)
            switch (ucByte[0])
            {
            case 'u':
                coolerfan_PWMDuty(getCoolerDuty() + 0.05);
                break;
            case 'd':
                coolerfan_PWMDuty(getCoolerDuty() - 0.05);
                break;
            }
        break;

    case 'T':
        if (!bLock)
            switch (ucByte[0])
            {
            case 'u':
                pid_setSetValue(pid_getSetValue() + 1);
                break;
            case 'd':
                pid_setSetValue(pid_getSetValue() - 1);
                break;
            }
        break;
    case 'D':
        if (!bLock)
            switch (ucByte[0])
            {
            case 'u':
                pid_setKd(pid_getKd() + 2);
                break;
            case 'd':
                pid_setKd(pid_getKd() - 2);
                break;
            }
        break;
    case 'I':
        if (!bLock)
            switch (ucByte[0])
            {
            case 'u':
                pid_setKi(pid_getKi() + 2);
                break;
            case 'd':
                pid_setKi(pid_getKi() - 2);
                break;
            }
        break;
    case 'P':
        if (!bLock)

            switch (ucByte[0])
            {
            case 'u':
                pid_setKp(pid_getKp() + 2);
                break;
            case 'd':
                pid_setKp(pid_getKp() - 2);
                break;
            }
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
    static float fTempNow = 0;
    static float fTempReq = 0;
    static float fKd = 0;
    static float fKi = 0;
    static float fKp = 0;
    static float fHeater = 0;
    static float fCooler = 0;

    unsigned char *ucValue = malloc(4 * sizeof(unsigned char));
    int iI;

    debug_putchar(HASHTAG);
    debug_putchar(LETRA_A);

    switch (ucParam)
    {
    case 't':
        /* return actual temperature*/
        fTempNow = getTemp();

        ucValue = floatToUChar(fTempNow);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;

    case 'c':
        /* return the cooler duty cycle*/
        fCooler = getCoolerDuty();
        ucValue = floatToUChar(fCooler);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);

        break;

    case 'a':
        /*return  the heater duty cycle*/
        fHeater = getHeaterDuty();
        ucValue = floatToUChar(fHeater);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;
    case 'i':
        /*return  the Ki param of PID*/
        fKi = pid_getKi();
        ucValue = floatToUChar(fKi);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;
    case 'd':
        /*return  the Kd param of PID*/
        fKd = pid_getKd();
        ucValue = floatToUChar(fKd);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;
    case 'p':
        /*return  the Kp param of PID*/
        fKp = pid_getKp();
        ucValue = floatToUChar(fKp);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;
    case 's':
        /*return  target temperature*/
        fTempReq = pid_getSetValue();
        ucValue = floatToUChar(fTempReq);
        for (iI = 0; iI < 4; iI++)
            debug_putchar(ucValue[iI]);
        break;

    case 'b':
        if (bLock)
            debug_putchar('1');
        else
            debug_putchar('0');
        break;
    };

    free(ucValue);
    debug_putchar(PONTO_VIRGULA);
}

/* ************************************************ */
/* Method name:        setScreen			        */
/* Method description: print on lcd the current 	*/
/*					   state  of the equipament     */
/* Input params:       n/a							*/
/* Output params:      n/a	 				        */
/* ************************************************ */
void setScreen()
{
    static int iSendTemp = 0;
    if (iSendTemp == 10)
    {
        iSendTemp = 0;
        answerParam(ucTempNow);
    }
    else
    {
        iSendTemp++;
    }

    enum state esState = getState();
    static float fTempNow = 0;
    static float fTempReq = 0;
    static float fKd = 0;
    static float fKi = 0;
    static float fKp = 0;
    static float fHeater = 0;
    static float fCooler = 0;

    static unsigned char ucAux[16];
    if (bLock)
        lcd_writeText(1, "TEC. DESBLOQ");
    else
        lcd_writeText(1, "TEC. BLOQUEADO");
    switch (esState)
        {
        case TARGETTEMP:
            ucAux[0] = 'S';
            ucAux[1] = 'E';
            ucAux[2] = 'T';
            ucAux[3] = ' ';
            ucAux[4] = 'T';
            ucAux[5] = 'E';
            ucAux[6] = 'M';
            ucAux[7] = 'P';
            ucAux[8] = ':';

            fTempReq = pid_getSetValue();
            ucAux[10] = (((int)fTempReq) % 10) + 48;
            fTempReq = ((int)fTempReq) / 10;
            ucAux[9] = (((int)fTempReq) % 10) + 48;

            ucAux[11] = '^';
            ucAux[12] = 'C';
            ucAux[13] = '\0';

            lcd_writeText(0, ucAux);
            break;
        case TARGETKD:
            ucAux[0] = 'K';
            ucAux[1] = 'D';
            ucAux[2] = ':';
            ucAux[3] = ' ';

            fKd = pid_getKd();

            fKd = fKd * 1000;
            ucAux[9] = (((int)fKd) % 10) + 48;

            fKd = ((int)fKd) / 10;
            ucAux[8] = (((int)fKd) % 10) + 48;

            ucAux[7] = '.';

            fKd = ((int)fKd) / 10;
            ucAux[6] = (((int)fKd) % 10) + 48;

            fKd = ((int)fKd) / 10;
            ucAux[5] = (((int)fKd) % 10) + 48;

            fKd = ((int)fKd) / 10;
            ucAux[4] = (((int)fKd) % 10) + 48;

            ucAux[10] = '\0';
            lcd_writeText(0, ucAux);
            break;
        case TARGETKI:
            ucAux[0] = 'K';
            ucAux[1] = 'I';
            ucAux[2] = ':';
            ucAux[3] = ' ';

            fKi = pid_getKi();

            fKi = fKi * 1000;
            ucAux[9] = (((int)fKi) % 10) + 48;

            fKi = ((int)fKi) / 10;
            ucAux[8] = (((int)fKi) % 10) + 48;

            ucAux[7] = '.';

            fKi = ((int)fKi) / 10;
            ucAux[6] = (((int)fKi) % 10) + 48;

            fKi = ((int)fKi) / 10;
            ucAux[5] = (((int)fKi) % 10) + 48;

            fKi = ((int)fKi) / 10;
            ucAux[4] = (((int)fKi) % 10) + 48;

            ucAux[10] = '\0';
            lcd_writeText(0, ucAux);
            break;

        case TARGETKP:
            ucAux[0] = 'K';
            ucAux[1] = 'P';
            ucAux[2] = ':';
            ucAux[3] = ' ';

            fKp = pid_getKp();
            fKp = fKp * 100;

            ucAux[8] = (((int)fKp) % 10) + 48;
            fKp = ((int)fKp) / 10;
            ucAux[7] = (((int)fKp) % 10) + 48;
            ucAux[6] = '.';
            ucAux[5] = (((int)fKp) % 10) + 48;
            fKp = ((int)fKp) / 10;
            ucAux[4] = (((int)fKp) % 10) + 48;

            ucAux[9] = '\0';
            lcd_writeText(0, ucAux);
            break;
        case DUTYHEATER:
            ucAux[0] = 'R';
            ucAux[1] = 'E';
            ucAux[2] = 'S';
            ucAux[3] = 'I';
            ucAux[4] = 'S';
            ucAux[5] = 'T';
            ucAux[6] = 'O';
            ucAux[7] = 'R';
            ucAux[8] = ':';
            ucAux[9] = ' ';

            fHeater = getHeaterDuty();
            fHeater = fHeater * 100;

            ucAux[12] = (((int)fHeater) % 10) + 48;
            fHeater = ((int)fHeater) / 10;
            ucAux[11] = (((int)fHeater) % 10) + 48;
            fHeater = ((int)fHeater) / 10;
            ucAux[10] = (((int)fHeater) % 10) + 48;

            ucAux[13] = ' ';
            ucAux[14] = '%';
            ucAux[15] = '\0';
            lcd_writeText(0, ucAux);
            break;

        case DUTYCOOLER:
            ucAux[0] = 'F';
            ucAux[1] = 'A';
            ucAux[2] = 'N';
            ucAux[3] = ' ';
            ucAux[4] = 'E';
            ucAux[5] = 'M';
            ucAux[6] = ' ';

            fCooler = getCoolerDuty();
            fCooler = fCooler * 100;

            ucAux[9] = (((int)fCooler) % 10) + 48;
            fCooler = ((int)fCooler) / 10;
            ucAux[8] = (((int)fCooler) % 10) + 48;
            fCooler = ((int)fCooler) / 10;
            ucAux[7] = (((int)fCooler) % 10) + 48;

            ucAux[10] = ' ';
            ucAux[11] = '%';
            ucAux[12] = '\0';
            lcd_writeText(0, ucAux);
            break;

        default:
            ucAux[0] = 'T';
            ucAux[1] = 'E';
            ucAux[2] = 'M';
            ucAux[3] = 'P';
            ucAux[4] = ' ';
            ucAux[5] = 'A';
            ucAux[6] = 'T';
            ucAux[7] = 'U';
            ucAux[8] = 'A';
            ucAux[9] = 'L';
            ucAux[10] = ':';

            /*print Temperature*/
            fTempNow = getTemp();
            ucAux[12] = (((int)fTempNow) % 10) + 48;
            fTempNow = fTempNow / 10;
            ucAux[11] = (((int)fTempNow) % 10) + 48;

            ucAux[13] = '^';
            ucAux[14] = 'C';
            ucAux[15] = '\0';

            lcd_writeText(0, ucAux);
            break;
        }
}

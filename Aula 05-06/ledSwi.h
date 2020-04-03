/* ***************************************************************** */
/* File name:        ledSwi.c                                        */
/* File description: Header file containing the functions needed to  */
/*                   initialize, switch in between and operate red   */
/*                   leds and buttons                                */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    02apr2020                                       */
/* ***************************************************************** */

#ifndef LEDSWI_H

void initLedButton(int *iPinsLed, int iTamLed,int *iPinsButton, int iTamButton);

int readButton(int iPin);

void ligaLed(int iPin);

void desligaLed(int iPin);

void toggleLed(int iPin);

void writeLed(int iPin, int iNivel);

#define LEDSWI_H












#endif

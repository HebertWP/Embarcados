/* ***************************************************************** */
/* File name:        ledSwi.h                                        */
/* File description: Header file containing the functions needed to  */
/*                   initialize, switch in between and operate RGB   */
/*                   leds and buttons                                */
/*                                                                   */
/* Author name:      Caio Villela/ Hebert Wandick                    */
/* Creation date:    02apr2020                                       */
/* Revision date:    02apr2020                                       */
/* ***************************************************************** */

#ifndef LEDSWI_H
#define LEDSWI_H

/* **********************************************************/
/* Methodname:         initLedButton                        */
/* Method description: Esse metodoso realiza a inicializacao*/
/*                     dos Led e Botoes blugados no comtrole*/
/* Inputparams:        iPinsLed- Um vetor contendo o numero */
/*                     leds e utilizados                    */
/*                     iTamLed- Quantidade de led a serem   */
/*                     incializados                         */
/*                     iPinsButton- Um vetor contendo o     */
/*                     numero botoesutilizados              */
/*                     iTamButton- Quantidade de botoes     */
/*                     a serem incializados                 */
/* Outputparams:       n/a                                  */
/************************************************************/
void initLedButton(int *iPinsLed, int iTamLed,int *iPinsButton, int iTamButton);

/* **********************************************************/
/* Methodname:         readButton                           */
/* Method description: Esse metodo realiza a leitura de um  */
/*                     botao em especifico                  */
/* Inputparams:        iPin- Numero do botao a ser lido     */
/* Outputparams:       0 caso seja lido nivel logico baixo  */
/*                     1 caso seja lido nivel logico alto   */
/************************************************************/
int readButton(int iPin);

/* **********************************************************/
/* Methodname:         ligaLed                              */
/* Method description: Liga un led                          */
/* Inputparams:        iPin- Numero do led a ser ligado     */
/* Outputparams:       n/a                                  */
/************************************************************/
void ligaLed(int iPin);

/* **********************************************************/
/* Methodname:         desligaLed                           */
/* Method description: Desliga led                          */
/* Inputparams:        iPin- Numero do led a ser desligado  */
/* Outputparams:       n/a                                  */
/************************************************************/
void desligaLed(int iPin);

/* **********************************************************/
/* Methodname:         toggleLed                            */
/* Method description: Deixa o pino puglado o led           */
/*                     desconetado do circtuto eletrico     */
/*                     externo                              */
/* Inputparams:        iPin- Numero do led a ser desconetado*/
/*                     do controlador                       */
/* Outputparams:       n/a                                  */
/************************************************************/
void toggleLed(int iPin);

/* **********************************************************/
/* Methodname:         writeLed                             */
/* Method description: Congifura o nivel logic do pino      */
/*                     ligado o led para nivel alto ou baixo*/
/*                     externo                              */
/* Inputparams:        iPin- Numero do pino a ter o nivel   */
/*                     logico alterado                      */
/*                     iNivel- nivel logico a ser aplicado  */
/* Outputparams:       n/a                                  */
/************************************************************/
void writeLed(int iPin, int iNivel);

#endif

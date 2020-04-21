/* ***************************************************************** */
/* File name:        lcd.c                                           */
/* File description: file containing the implementation of functions */
/*                   used to control the LCD display                 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    10/apr/2020                                     */
/* Revision date:    10/apr/2020                                     */
/* ***************************************************************** */


#ifndef SOURCES_DISPLAY7SEG_H_
#define SOURCES_DISPLAY7SEG_H_



/* ************************************************ */
/* Method name:        display7seg_init             */
/* Method description: Initializes the 7 seg display*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_init(void);



/* ******************************************************** */
/* Method name:        display7seg_writeSymbol              */
/* Method description: Writes a symbol on a 7seg display    */
/* Input params:       ucDisplay is a value ranging from    */
/*     1 to 4, relative to the display we are to write on   */
/*                     ucValue ranging from 0 to 22,        */
/*       indicates what symbol is to be shown on the display*/
/* Output params:      n/a                                  */
/* ******************************************************** */
void display7seg_writeSymbol(unsigned char ucDisplay,unsigned char ucValue);

/* ******************************************************** */
/* Method name:        display7seg_writeNumber              */
/* Method description: write numbers on  7seg displays	    */
/* Input params:       iNum number to be print at displays  */
/* Output params:      n/a                                  */
/* ******************************************************** */
void display7seg_writeNumber(int num);
#endif /* SOURCES_DISPLAY7SEG_H_ */

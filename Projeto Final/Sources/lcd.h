/* ***************************************************************** */
/* File name:        lcd.h                                           */
/* File description: file containing the description of functions    */
/*                   used to control the LCD display                 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    09/apr/2020                                     */
/* Revision date:    10/apr/2020                                     */
/* ***************************************************************** */


#ifndef SOURCES_LCD_H_
#define SOURCES_LCD_H_

/* lcd basic commands list */
#define CMD_INIT_LCD        0x0F
#define CMD_CLEAR           0x01
#define CMD_NO_CURSOR       0x0C
#define CMD_CURSOR2R        0x06 /* cursor to right */
#define CMD_NO_CUR_NO_BLINK 0x38 /* no cursor, no blink */


/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_initLcd(void);


/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData);


/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd);


/* ************************************************ */
/* Method name:        lcd_WriteString              */
/* Method description: Write string to be displayed */
/* Input params:       cBuffer => string to be      */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cBuffer);


/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       cLine = LINE0..LINE1         */
/*                     cColumn = COLUMN0..MAX_COLUMN*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn);


/* ************************************************ */
/* Method name:        lcd_dummyText                */
/* Method description: Write a dummy hard coded text*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_dummyText(void);

/* ************************************************ */
/* Method name:        lcd_writeText                */
/* Method description: Write text sent by user, on  */
/*                     especified line              */
/* Input params:       int iL, line // chr* cString */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeText(int iL, char* cString );

#endif /* SOURCES_LCD_H_ */
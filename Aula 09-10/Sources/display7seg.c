/* ***************************************************************** */
/* File name:        lcd.c                                           */
/* File description: file containing the implementation of functions */
/*                   used to control the LCD display                 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    10/apr/2020                                     */
/* Revision date:    10/apr/2020                                     */
/* ***************************************************************** */



extern unsigned char ucDisplays[4];

/* ************************************************ */
/* Method name:        display7seg_init             */
/* Method description: Initializes the 7 seg display*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_init(void){

  /* pins configured as outputs */

  /*un-gateport C clock*/
  SIM_SCGC5|=0x0800;

  /*set pins as gpio*/
  PORTC_PCR0|= 0x100; /*A*/
  PORTC_PCR1|= 0x100; /*B*/
  PORTC_PCR2|= 0x100; /*C*/
  PORTC_PCR3|= 0x100; /*D*/
  PORTC_PCR4|= 0x100; /*E*/
  PORTC_PCR5|= 0x100; /*F*/
  PORTC_PCR6|= 0x100; /*G*/
  PORTC_PCR7|= 0x100; /*DP*/
  PORTC_PCR13|= 0x100; /*D1*/
  PORTC_PCR12|= 0x100; /*D2*/
  PORTC_PCR11|= 0x100; /*D3*/
  PORTC_PCR10|= 0x100; /*D4*/


  /* set pins as digital output */
  GPIOC_PDDR |= DISPLAY_A_DIR;
  GPIOC_PDDR |= DISPLAY_B_DIR;
  GPIOC_PDDR |= DISPLAY_C_DIR;
  GPIOC_PDDR |= DISPLAY_D_DIR;
  GPIOC_PDDR |= DISPLAY_E_DIR;
  GPIOC_PDDR |= DISPLAY_F_DIR;
  GPIOC_PDDR |= DISPLAY_G_DIR;
  GPIOC_PDDR |= DISPLAY_DP_DIR;
  GPIOC_PDDR |= DISPLAY_D1_DIR;
  GPIOC_PDDR |= DISPLAY_D2_DIR;
  GPIOC_PDDR |= DISPLAY_D3_DIR;
  GPIOC_PDDR |= DISPLAY_D4_DIR;


}


/* ******************************************************** */
/* Method name:        display7seg_writeSymbol              */
/* Method description: Writes a symbol on a 7seg display    */
/* Input params:       ucDisplay is a value ranging from    */
/*     1 to 4, relative to the display we are to write on   */
/*                     ucValue ranging from 0 to 22,        */
/*       indicates what symbol is to be shown on the display*/
/* Output params:      n/a                                  */
/* ******************************************************** */
void display7seg_writeSymbol(unsigned char ucDisplay,unsigned char ucValue)
{
    unsigned char uc7seg;

    /*disable all displays*/
    GPIOC_PCOR |= DISPLAY_D1_DIR;
    GPIOC_PCOR |= DISPLAY_D2_DIR;
    GPIOC_PCOR |= DISPLAY_D3_DIR;
    GPIOC_PCOR |= DISPLAY_D4_DIR;

    /*turn off all data pins*/
    GPIOC_PCOR |= DISPLAY_A_DIR;
    GPIOC_PCOR |= DISPLAY_B_DIR;
    GPIOC_PCOR |= DISPLAY_C_DIR;
    GPIOC_PCOR |= DISPLAY_D_DIR;
    GPIOC_PCOR |= DISPLAY_E_DIR;
    GPIOC_PCOR |= DISPLAY_F_DIR;
    GPIOC_PCOR |= DISPLAY_G_DIR;
    GPIOC_PCOR |= DISPLAY_DP_DIR;

    /*write data on siplay BUS*/
    /*didnt use karnaugh approach for debugging purposes*/
    switch(ucValue){
      case 0:
        uc7seg = 0x3F;
        GPIOC_PSOR |= 0x3F;
        break;

      case 1:
        uc7seg = 0x06;
        GPIOC_PSOR |= 0x06;
        break;

      case 2:
        uc7seg = 0x5B;
        GPIOC_PSOR |= 0x5B;
        break;

      case 3:
         uc7seg = 0x4F;
         GPIOC_PSOR |= 0x4F;
         break;

      case 4:
         uc7seg = 0x66;
         GPIOC_PSOR |= 0x66;
         break;

      case 5:
         uc7seg = 0x6D;
         GPIOC_PSOR |= 0x6D;
         break;

      case 6:
         uc7seg = 0x7D;
         GPIOC_PSOR |= 0x7D;
         break;

      case 7:
         uc7seg = 0x07;
         GPIOC_PSOR |= 0X07;
      break;

      case 8:
         uc7seg = 0x7F;
         GPIOC_PSOR |= 0x7F;
      break;

      case 9:
         uc7seg = 0x6F;
         GPIOC_PSOR |= 0x6F;
      break;

      case 10:
         uc7seg = 0xBF;
         GPIOC_PSOR |= 0xBF;
      break;

      case 11:
         uc7seg = 0x86;
         GPIOC_PSOR |= 0x86;
      break;

      case 12:
         uc7seg = 0xDB;
         GPIOC_PSOR |= 0xDB;
      break;

      case 13:
         uc7seg = 0xCF;
         GPIOC_PSOR |= 0xCF;
      break;

      case 14:
         uc7seg = 0xE6;
         GPIOC_PSOR |= 0xE6;
      break;

      case 15:
         uc7seg = 0xED;
         GPIOC_PSOR |= 0xED;
      break;

      case 16:
         uc7seg = 0xFD;
         GPIOC_PSOR |= 0xFD;
      break;

      case 17:
         uc7seg = 0x87;
         GPIOC_PSOR |= 0x87;
      break;

      case 18:
         uc7seg = 0xFF;
         GPIOC_PSOR |= 0xFF;
      break;

      case 19:
         uc7seg = 0xEF;
         GPIOC_PSOR |= 0xEF;
      break;

      case 20:
        uc7seg = 0x80;
        GPIOC_PSOR |= 0x80;
        break;

      case 21:
        uc7seg = 0x00;
        break;

      case 22:
        uc7seg = 0xFF;
        GPIOC_PSOR |= 0x80;
        break;

    }

    /*enable writing on a display*/
    switch(ucDisplay){
       case 1:
            GPIOC_PSOR |= DISPLAY_D1_DIR;
            ucDisplays[0] = uc7seg;
            break;

       case 2:
            GPIOC_PSOR |= DISPLAY_D2_DIR;
            ucDisplays[1] = uc7seg;
            break;

       case 3:
            GPIOC_PSOR |= DISPLAY_D3_DIR;
            ucDisplays[2] = uc7seg;
            break;

       case 4:
            GPIOC_PSOR |= DISPLAY_D4_DIR;
            ucDisplays[3] = uc7seg;
            break;
    }

}

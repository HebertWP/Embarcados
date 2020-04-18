/* ***************************************************************** */
/* File name:        lcd.c                                           */
/* File description: file containing the implementation of functions */
/*                   used to control the LCD display                 */
/* Author name:      Caio Villela, Hebert Wandick                    */
/* Creation date:    10/apr/2020                                     */
/* Revision date:    10/apr/2020                                     */
/* ***************************************************************** */


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

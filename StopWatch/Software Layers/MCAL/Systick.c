/*
 * Systick.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Kareem Hani
 */
#include "Software Layers/MCAL/Systick.h"
#include "Software Layers/LIB/BITWISE_OPERATIONS.h"

void Systick_Init()
{
    // Enabling the System Clock
    SETBIT(NVIC_ST_CTRL_R,2);

    // Enabling Systick Interrupt
    SETBIT(NVIC_ST_CTRL_R,1);

    // Systick Enable bit
    SETBIT(NVIC_ST_CTRL_R,0);

    // Placing a value of 1 Second in the reload register
    NVIC_ST_RELOAD_R=0x00F42400-1;
}

void display()
{
   static int counter=0;
   //static int sec=0;
   char Save_string[50]={};



    // Incrementing the counter
    counter++;

    // Convert integer to string
    ltoa(counter,Save_string);

    // Printing the string on the LCD
    SEND_STRING(Save_string);




}

void Stop()
{

    CLEARBIT(NVIC_ST_CTRL_R,0);

}


/*  // In case we are using polling
void display()
{
   static int counter=0;
   static int sec=0;
   char Save_string[50]={};

   //Checks if the count flag is equal to 1
   if(CHECKBIT(NVIC_ST_CTRL_R,16)==1)
   {
       // Incrementing the counter
       counter++;

       // Convert integer to string
       ltoa(counter,Save_string);

       // Printing the string on the LCD
       SEND_STRING(Save_string);

   }


}
*/

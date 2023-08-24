/*
 * Systick_Application.c
 *
 *  Created on: Aug 24, 2023
 *      Author: EUI-Support
 */
#include "Systick.h"
#include "LCD.h"
#include "DIO.h"

#define PUSHBUTTON0  0
#define PUSHBUTTON1  4
int flag=0;

void main()
{
 // Initializing PORTF
    DIO_INIT(PORTF,0,0b00010001);

 // Initializing LCD
    LCD_INIT();

 // Enabling interrupt on Push Buttons
    interrupt_init(PORTF,0);
    interrupt_init(PORTF,4);
    while(1)
    {
        if(flag==1)
        {
            // Initializing Systic Timer
            Systick_Init();

        }
        else if (flag==0)
        {
            Stop();
        }
        else;

    }
}

void Polling_ISR()
{
 SETBIT(GPIO_PORTF_ICR_R, 0);

 if(CHECKBIT(GPIO_PORTF_DATA_R,0))
 {
     flag=1;
 }
 else if(CHECKBIT(GPIO_PORTF_DATA_R,4))
 {
     flag=0;
 }
 else;
 delay_ms(10);
 SETBIT(GPIO_PORTF_ICR_R, 0);
 SETBIT(GPIO_PORTF_ICR_R, 4);
 SETBIT(NVIC_UNPEND0_R, 30);
}

void Systic_ISR()
{
    display();
}
// In Case of polling
/*
 *     while(1)
    {
        if(flag)
        {
            // Initializing Systic Timer
            Systick_Init();
            // Displaying the value on LCD
            while(flag)
            {
                display();
            }
        }
        else
        {
            Stop();
        }

    }
 *
 */

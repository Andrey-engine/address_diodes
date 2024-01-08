/*
 * app_main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Андрей
 */
#include "app_main.h"
#include "Inc/main.h"
#include "ARGB.h"
void app_main(void)
{
	 ARGB_Init();  // Initialization

	 ARGB_Clear(); // Clear stirp
	 while (ARGB_Show() != ARGB_OK); // Update - Option 1

	 int i = 0;
	 while(i<1000)
	 {
	    ARGB_SetBrightness(40);  // Set global brightness to 40%


	    //ARGB_FillRGB(60,60,60);
	    ARGB_SetRGB(0, 60, 60, 60); // Set LED №3 with 255 Green
	    //ARGB_SetRGB(1, 60, 60, 60); // Set LED №3 with 255 Green
	    ARGB_SetRGB(2, 0, 0, 60); // Set LED №3 with 255 Green
	    //ARGB_SetRGB(3, 60, 60, 60); // Set LED №3 with 255 Green
	    ARGB_SetRGB(4, 60, 60, 60); // Set LED №3 with 255 Green
	    //ARGB_SetRGB(5, 60, 60, 60); // Set LED №3 with 255 Green
	    ARGB_SetRGB(6, 60, 60, 60); // Set LED №3 with 255 Green
	    while (!ARGB_Show());  // Update - Option 2

	    HAL_Delay(500);
	    i=i+1;

	 }
	    //ARGB_FillRGB(200, 0, 0); // Fill all the strip with Red
	    //    while (!ARGB_Show());


	    /*
	    int numb_diode = 0;
	    while(1)
	    {

	    ARGB_SetHSV(numb_diode, 0, 255, 0); // Set LED №1 with green
	    while (!ARGB_Ready()); // Update - Option 3
	    ARGB_Show();

	    HAL_Delay(1000);
	    numb_diode++;
	    if(numb_diode > 59)
	    	numb_diode = 0;
	    }*/

	/*while(1)
	{
	  HAL_Delay(500);
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}*/
}

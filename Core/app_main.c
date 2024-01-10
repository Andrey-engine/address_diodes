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

	 /*int i = 0;
	 while(i<1000)
	 {
	    ARGB_SetBrightness(10);  // Set global brightness to 40%


	    ARGB_FillRGB(60,60,60);
	    //ARGB_SetRGB(0, 60, 60, 60); // 1 diod R and G
	    //ARGB_SetRGB(1, 60, 60, 60); // null
	    //ARGB_SetRGB(2, 60, 60, 60); // 1 diod B and 2 diod R and G
	    while (!ARGB_Show());  // Update - Option 2

	    HAL_Delay(1000);
	    i=i+1;

	 }*/


	    int numb_diode = 0;
	    while(1)
	    {
		ARGB_Clear(); // Clear stirp
		ARGB_SetRGB(numb_diode, 5, 0, 0); // Set LED №1 with green
	    while (!ARGB_Show()); // Update - Option 3

	    HAL_Delay(1000);
	    numb_diode++;
	    if(numb_diode > 2)
	    	numb_diode = 0;
	    }

	/*while(1)
	{
	  HAL_Delay(500);
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}*/
}

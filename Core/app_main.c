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
	 	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	 	/*ARGB_Clear(); // Clear stirp
	 	ARGB_SetBrightness(10);  // Set global brightness to 40%
	 	ARGB_FillRGB(39,250,176);
	 	while (!ARGB_Show()); // Update - Option 3
		*/
	 	int Brightness = 1;
	 	int flag_up = 1;
	 	while(1)
	 	{
	 		HAL_Delay(100);
	 		if (flag_up)
				{
				if(Brightness >= 50)
					flag_up=0;

				ARGB_SetBrightness(Brightness);  // Set global brightness to 40%
				ARGB_FillRGB(39,250,176);
				while (!ARGB_Show()); // Update - Option 3

				Brightness++;
				}
	 		else
	 		{
	 			if(Brightness <= 1)
					flag_up=1;

				ARGB_SetBrightness(Brightness);  // Set global brightness to 40%
				ARGB_FillRGB(39,250,176);

				while (!ARGB_Show()); // Update - Option 3

				Brightness--;
	 		}
	 	}
	 	/*
	    int numb_diode = 0;
	    while(1)
	    {

		if(numb_diode >= NUM_PIXELS)
			numb_diode = 0;

		ARGB_Clear(); // Clear stirp
		//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		ARGB_SetRGB(numb_diode, 39, 250, 176); // Set LED №1 with green
		ARGB_SetRGB(numb_diode+1, 39, 250, 176); // Set LED №1
		ARGB_SetRGB(numb_diode+2, 39, 250, 176); // Set LED №1 with green
		ARGB_SetRGB(numb_diode+3, 39, 250, 176); // Set LED №1
		ARGB_SetRGB(numb_diode+4, 39, 250, 176); // Set LED №1 with green
	    while (!ARGB_Show()); // Update - Option 3

	    HAL_Delay(50);
	    numb_diode++;

	    }
	 	 */
	/*while(1)
	{
	  HAL_Delay(500);
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}*/
}

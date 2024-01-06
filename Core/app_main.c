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

	    ARGB_SetBrightness(100);  // Set global brightness to 40%

	    ARGB_SetHSV(0, 0, 255, 255); // Set LED №1 with Red
	    while (!ARGB_Ready()); // Update - Option 3
	    ARGB_Show();

	/*while(1)
	{
	  HAL_Delay(500);
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	}*/
}

/*
 * app_main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Андрей
 */
#include "app_main.h"

// Сохраненные цвета
color_s MINT = {39, 250, 176};

// Массив состояния светодиодной ленты
color_s LED_strip [NUM_PIXELS] = {0};
/*
// Инициализация значений массива ленты
for(int i =0; i < NUM_PIXELS; i++)
	LED_strip[i].r = LED_strip[i].g = LED_strip[i].b = 0;
*/

void app_main(void)
{
	ARGB_Init();  // Initialization
	ARGB_Clear(); // Clear stirp
	while (ARGB_Show() != ARGB_OK); // Update

}

void set_led_mas(color_s mas[], uint8_t size){
	for(int i = 0; i < size; i++)
		ARGB_SetRGB(i, mas[i].r, mas[i].g, mas[i].b);
	while (ARGB_Show() != ARGB_OK); // Update
}// set_led_mas


// Функция создаёт непрерывное мерцание (увеличение/снижение яркости)
void blink_light (color_s color){

	int Brightness = 1;
	int flag_up = 1;
	while(1)
	{

		HAL_Delay(100);
		if (flag_up){

			if(Brightness >= 50)
				flag_up=0;

			ARGB_SetBrightness(Brightness);
			ARGB_FillRGB(color.r, color.g, color.b);
			while (!ARGB_Show()); // Update - Option 3

			Brightness++;

		}else{

			if(Brightness <= 1)
				flag_up=1;

			ARGB_SetBrightness(Brightness);
			ARGB_FillRGB(color.r, color.g, color.b);

			while (!ARGB_Show()); // Update - Option 3

			Brightness--;
		}
	}

}//blink_light


// Функция отвечает за бегущие светодиоды
void run_light (color_s mas[], uint8_t size, uint8_t shift){
// двигаем массив на 1 в право, 0 элемент зануляем
	for(uint8_t i = 0; i < shift; i++){
		for(uint8_t j = size - 1; j > 0; j-- )
			mas[j] = mas [j-1];
		mas[0].r = mas[0].g = mas[0].b = 0;
	}
}//run_light

// включение светодиода под номером 0
void add_first_light(color_s mas[], color_s color){ mas[0] = color;} // add_light

// Обработка прерывания переполнения таймера
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if (htim->Instance == TIM2){ // рерывание от второго таймера
    	set_led_mas(LED_strip, NUM_PIXELS);
    	run_light(LED_strip, NUM_PIXELS, 1);
    }
}//HAL_TIM_PeriodElapsedCallback

// Обработка прерывания уровня напряжения ножки
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	// датчик звука дискретный
   if(GPIO_Pin == GPIO_PIN_11){ // если прерывание поступило от ножки PВ11
	   add_first_light(LED_strip, MINT);
	   HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
   }
}//HAL_GPIO_EXTI_Callback



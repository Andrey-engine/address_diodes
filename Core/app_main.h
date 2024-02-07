/*
 * app.main.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Андрей
 */

#ifndef LIB_APP_MAIN_H_
#define LIB_APP_MAIN_H_

// глобальные переменные
#include "Inc/main.h"
// светодиодная лента
#include "ARGB.h"

typedef struct {
	int r;
	int g;
	int b;
}color_s;

void app_main(void);

// Функция осуществляет сдвиг массива в право на shift
void run_light (color_s mas[], uint8_t size, uint8_t shift);

// мерцание: увеличение и уменьшение яркости
void blink_light (color_s color);


#endif /* LIB_APP_MAIN_H_ */

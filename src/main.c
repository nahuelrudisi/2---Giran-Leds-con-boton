/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint16_t delay);

#define LED_NARANJA GPIO_PIN_13
#define LED_VERDE GPIO_PIN_12
#define LED_ROJO GPIO_PIN_14
#define LED_AZUL GPIO_PIN_15
#define BOTON GPIO_PIN_0

#define LEDS_PORT GPIOD
#define BOTON_PORT GPIOA

int main(void) {

	__GPIOA_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_Init;
	GPIO_InitTypeDef GPIO_Init1;

	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FAST;

	GPIO_Init1.Mode = GPIO_MODE_INPUT;
	GPIO_Init1.Pull = GPIO_PULLDOWN;	// Pull Down visto en la hoja de datos
	GPIO_Init1.Speed = GPIO_SPEED_FAST;

	GPIO_Init.Pin = LED_AZUL | LED_ROJO | LED_NARANJA | LED_VERDE;
	GPIO_Init1.Pin = BOTON;

	HAL_GPIO_Init(LEDS_PORT, &GPIO_Init);
	HAL_GPIO_Init(BOTON_PORT, &GPIO_Init1);

	while (1) {

		while(HAL_GPIO_ReadPin(BOTON_PORT, BOTON)==1)
		{
			// Sentido Antihorario
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
			delay(0xFFFF);
			HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);
			delay(0xFFFF);
		}

		// Sentido Horario
		HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
		delay(0xFFFF);
		HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
		delay(0xFFFF);
		HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_RESET);
		delay(0xFFFF);
		HAL_GPIO_WritePin(LEDS_PORT, LED_AZUL, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_ROJO, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_NARANJA, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDS_PORT, LED_VERDE, GPIO_PIN_SET);
		delay(0xFFFF);
	}
}

void delay(uint16_t delay) {
	uint16_t i = 0xFFFF;
	while (i) {
		while (delay)
			delay--;
		i--;
	}
}

/**
 ******************************************************************************
 * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_3A_modularizacion/API/Src/API_delay.c
 * @author  Mendoza, Dante.
 * @brief   Practica sobre modularizacion.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "API_delay.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
// Esta función sirve para inicializar la estructura que maneja	el delay no bloqueante.
void delayInit(delay_t *delay, tick_t duration) {
	delay->duration = duration;
	delay->running = false;
}

/*
 *	Esta función se utiliza para consultar si el delay
 *	ha completado la duración requerida. En caso afirmativo,
 *	devuelve Verdadero, caso contrario devuelve Falso.
 *	Si es la primera vez que se llama a la función,
 *  se pone delay->running = Verdadero.
 */
bool_t delayRead(delay_t *delay) {
	if (!delay->running) {
		// Tomar marca de tiempo
		delay->startTime = HAL_GetTick();
		// Cambiar el flag a 'true'
		delay->running = true;
		return false;
	}

	if (delay->duration <= (HAL_GetTick() - delay->startTime)) {
		delay->running = false;
		return true;  // El tiempo se cumplió.
	}

	return false;  // El tiempo no se ha cumplido.
}

// Esta función se utiliza para cambiar la duración de un delay ya inicializado.
void delayWrite(delay_t *delay, tick_t duration) {
	delay->duration = duration;
}


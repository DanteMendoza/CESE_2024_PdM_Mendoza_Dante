/**
 ******************************************************************************
 * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_4A_debounce_MEF/API/Inc/API_debounce.c
 * @author  Mendoza, Dante.
 * @brief   Practica sobre debounce MEF.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "API_debounce.h"
#include "API_delay.h"

/* Private typedef -----------------------------------------------------------*/
/**
 * Enum para almacenar los estados que puede
 * tomar el botón.
 */
typedef enum {
	BUTTON_UP, BUTTON_FALLING, BUTTON_DOWN, BUTTON_RAISING,
} debounceState_t;

/* Private define ------------------------------------------------------------*/
static debounceState_t debounceState = BUTTON_UP; //variable de estado global.
static delay_t debounceDelay; //estructura utilizada para llevar a cabo el delay no bloqueante para eliminar rebotes.
static const uint8_t DELAY_TIME = 40; //constante para el tiempo de anti-rebote
static bool_t isButtonPressed = false; //variable que indica si el botón fue presionado

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void buttonPressed(Led_TypeDef led) {
	// Lógica para encender el LED
	isButtonPressed = true;
	BSP_LED_On(led);
}

void buttonReleased(Led_TypeDef led) {
	// Lógica para apagar el LED
	isButtonPressed = false;
	BSP_LED_Off(led);
}

/**
 * Lee el estado de la variable isButtonPressed,
 * y luego la pone como falso.
 */
bool_t readKey() {
	if (isButtonPressed) {
		isButtonPressed = false;

		return true;
	}

	return false;
}

void debounceFSM_init() {
	debounceState = BUTTON_UP;
	delayInit(&debounceDelay, DELAY_TIME);
}

/**
 * Lee la entrada y actualiza el estado
 * actuando en consecuencia.
 * Cuando se detecta que se ha presionado el botón
 * llama a la función buttonPressed.
 */
void debounceFSM_update() {
	switch (debounceState) {
	case BUTTON_UP:
		isButtonPressed = readKey();

		if (isButtonPressed) {
			debounceState = BUTTON_FALLING;
		}
		break;

	case BUTTON_FALLING:
		if (delayRead(&debounceDelay)) {
			isButtonPressed = readKey();
			if (isButtonPressed) {
				//buttonPressed();			//llamo a la función buttonPressed
				debounceState = BUTTON_DOWN;
			} else {
				debounceState = BUTTON_UP;
			}
		}
		break;

	case BUTTON_DOWN:
		isButtonPressed = readKey();

		if (!isButtonPressed) {
			debounceState = BUTTON_RAISING;
		}
		break;

	case BUTTON_RAISING:
		if (delayRead(&debounceDelay)) {
			isButtonPressed = readKey();
			if (!isButtonPressed) {
				debounceState = BUTTON_UP;
			} else {
				debounceState = BUTTON_DOWN;
			}
		}
		break;

	default:
		debounceFSM_init();
		break;
	}
}


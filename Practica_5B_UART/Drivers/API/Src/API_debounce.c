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
#include "API_uart.h"

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
static Led_TypeDef ledUser;
static Button_TypeDef buttonUser;

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Initialize BSP PB for BUTTON_USER */
/* UART handler declaration */
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void buttonPressed() {
	// Lógica para encender el LED
	isButtonPressed = true;
	BSP_LED_On(ledUser);
	uartSendString((uint8_t*) "El boton ha sido presionado\r\n");
}

void buttonReleased() {
	// Lógica para apagar el LED
	isButtonPressed = false;
	BSP_LED_Off(ledUser);
	uartSendString((uint8_t*) "El boton ha sido soltado\r\n");
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

// Funcion que recibe el LED y el boton de usuario.
void debounceConfig(Led_TypeDef led, Button_TypeDef button) {
	ledUser = led; // LED azul por defecto de la placa.
	buttonUser = button; // Boton azul de usuario de la placa.
}

void debounceFSM_init() {
	uartInit();
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
	isButtonPressed = (bool_t) BSP_PB_GetState(buttonUser);

	// Leer las entradas y actualizar la MEF
	switch (debounceState) {
	case BUTTON_UP:
		// Lógica para detectar flanco descendente
		if (isButtonPressed) {
			debounceState = BUTTON_FALLING;
			delayInit(&debounceDelay, DELAY_TIME);
		}
		break;
	case BUTTON_FALLING:
		// Lógica para detectar transición a BUTTON_DOWN
		if (delayRead(&debounceDelay)) {
			if (isButtonPressed) {
				buttonPressed();
				isButtonPressed = true;
				debounceState = BUTTON_DOWN;
			} else {
				// Lógica para volver a BUTTON_UP si no se detecta la transición
				debounceState = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		// Lógica para detectar flanco ascendente
		if (!isButtonPressed) {
			debounceState = BUTTON_RAISING;
			delayInit(&debounceDelay, DELAY_TIME);
		}
		break;
	case BUTTON_RAISING:
		// Lógica para detectar transición a BUTTON_UP
		if (delayRead(&debounceDelay)) {
			debounceState = BUTTON_UP;
			buttonReleased(); // Evento de Button Released

			if (!isButtonPressed) /* Button released event */
			{
				buttonReleased();
				debounceState = BUTTON_UP;
			} else {
				debounceState = BUTTON_DOWN;
			}
		}
		break;
	default:
		// Manejar cualquier otro estado no definido
		debounceFSM_init();
		break;
	}
}


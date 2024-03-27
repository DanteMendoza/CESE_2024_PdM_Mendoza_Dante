/**
 ******************************************************************************
 * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_4A_debounce_MEF/API/Inc/API_debounce.h
 * @author  Mendoza, Dante.
 * @brief   Practica sobre debounce MEF.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "stm32f4xx_nucleo_144.h"

/* Exported types ------------------------------------------------------------*/
typedef bool bool_t; // <stdbool.h>

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/**
 * Esta función inicializa la máquina de estados
 * que se encarga de leer el estado del botón.
 */
void debounceFSM_init();

/**
 * Esta función se debe llamar periodicamente
 * para que la máquina de estados actualize el
 * estado del botón.
 */
void debounceFSM_update();

// Accion ejecutada al presionar un boton.
void buttonPressed();

// Accion ejecutada al soltar un boton.
void buttonReleased();

/**
 * La función readKey devuelve true o false
 * si la tecla fue presionada.
 */
bool_t readKey();

// Funcion que recibe el LED y el boton de usuario.
void debounceConfig(Led_TypeDef led, Button_TypeDef button);

#endif /* API_INC_API_DEBOUNCE_H_ */


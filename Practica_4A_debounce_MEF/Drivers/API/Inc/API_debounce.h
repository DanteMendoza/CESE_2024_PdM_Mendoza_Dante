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
void buttonPressed(Led_TypeDef led);

// Accion ejecutada al soltar un boton.
void buttonReleased(Led_TypeDef led);

/**
 * La función readKey devuelve true o false
 * si la tecla fue presionada.
 */
bool_t readKey();

#endif /* API_INC_API_DEBOUNCE_H_ */


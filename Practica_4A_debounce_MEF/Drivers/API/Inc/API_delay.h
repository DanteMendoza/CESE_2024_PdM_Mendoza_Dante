/**
 ******************************************************************************
 * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_3A_modularizacion/API/Inc/API_delay.h
 * @author  Mendoza, Dante.
 * @brief   Practica sobre modularizacion.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "stm32f4xx_nucleo_144.h" 	/* <- BSP include */
#include <stdint.h>
#include <stdbool.h>

/* Exported types ------------------------------------------------------------*/
typedef uint32_t tick_t; // <stdint.h>
typedef bool bool_t; // <stdbool.h>

typedef struct {
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;

/* Exported constants --------------------------------------------------------*/

/* User can use this section to tailor USARTx/UARTx instance used and associated
 resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_8
#define USARTx_TX_GPIO_PORT              GPIOD
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void delayInit(delay_t *delay, tick_t duration);
bool_t delayRead(delay_t *delay);
void delayWrite(delay_t *delay, tick_t duration);

#endif /* API_INC_API_DELAY_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

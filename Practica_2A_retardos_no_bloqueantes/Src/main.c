 /**
  ******************************************************************************
  * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_2A_retardos_no_bloqueantes/Src/main.c
  * @author  Mendoza, Dante.
  * @brief   Practica sobre retardos no bloqueantes.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"  // Necesario para usar HAL_GetTick()

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
UART_HandleTypeDef UartHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  HAL_Init();

  void delayInit(delay_t *delay, tick_t duration) {
      delay->duration = duration;
      delay->running = false;
  }

  bool_t delayRead(delay_t *delay) {
      if (!delay->running) {
          // Tomar marca de tiempo
          delay->startTime = HAL_GetTick();
          // Cambiar el flag a 'true'
          delay->running = true;
          return false;
      } else {
          // Calcular el tiempo transcurrido
          tick_t currentTime = HAL_GetTick();
          tick_t elapsedTime = currentTime - delay->startTime;

          // Verificar si se ha cumplido el tiempo del retardo
          if (elapsedTime >= delay->duration) {
              // Cambiar el flag a 'false'
              delay->running = false;
              return true;  // El tiempo se cumplió
          } else {
              return false;  // El tiempo no se ha cumplido
          }
      }
  }

  void delayWrite(delay_t *delay, tick_t duration) {
      delay->duration = duration;
  }

  /* Initialize BSP Led for LEDS */
  BSP_LED_Init(LED1); // Verde.
  BSP_LED_Init(LED2); // Azul.
  BSP_LED_Init(LED3); // Rojo.

  // Apagamos todos los leds previamente.
  BSP_LED_Off(LED1);
  BSP_LED_Off(LED2);
  BSP_LED_Off(LED3);

  /* Infinite loop */
  while (1)
  {




  }
}


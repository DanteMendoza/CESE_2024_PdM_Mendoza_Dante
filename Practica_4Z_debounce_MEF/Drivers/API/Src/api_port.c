
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include "api_port.h"

/* Private defines -----------------------------------------------------------*/
#define USER_BUTTON_Pin GPIO_PIN_9
#define USER_BUTTON_GPIO_Port GPIOA

/**
  * @brief  Catch falling edge event on button.
  * @retval bool_t
  */
bool_t read_button(void)
{
    return (bool_t)HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin);
}

/**
  * @brief  Get systick.
  * @retval tick_t
  */
tick_t get_systick(void)
{
    return (tick_t)HAL_GetTick();
}

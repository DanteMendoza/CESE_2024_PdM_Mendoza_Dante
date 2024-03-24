
/* Private includes ----------------------------------------------------------*/
#include "api_types.h"
#include "api_port.h"
#include "api_debounce.h"
#include "api_delay.h"

/* Private defines -----------------------------------------------------------*/
#define DEBOUNCE_TIME_MS 40

/* Private typedef -----------------------------------------------------------*/
typedef enum {
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RISING,
} debounce_state_t;

/* Private variables ---------------------------------------------------------*/
static debounce_state_t button_fsm_state;
static delay_t debounce_delay;
static bool_t falling_edge_event;

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize button debounce FSM.
  * @retval None
  */
void debounce_fsm_init(void)
{
    button_fsm_state = BUTTON_UP;
    falling_edge_event = false;
    delay_init(&debounce_delay, DEBOUNCE_TIME_MS);
}

void debounce_fsm_update(void)
{
    bool_t button_state = read_button();

    switch (button_fsm_state)
    {
    case BUTTON_UP:
        if (button_state)
        {
            button_fsm_state = BUTTON_FALLING;
            delay_init(&debounce_delay, DEBOUNCE_TIME_MS);
        }
        break;
    case BUTTON_FALLING:
        if (delay_read(&debounce_delay))
        {
            if (button_state) /* Button pressed event */
            {
                button_pressed();
                falling_edge_event = true;
                button_fsm_state = BUTTON_DOWN;
            } else {
                button_fsm_state = BUTTON_UP;
            } 
        }
        break;
    case BUTTON_DOWN:
        if (!button_state)
        {
            button_fsm_state = BUTTON_RISING;
            delay_init(&debounce_delay, DEBOUNCE_TIME_MS);
        }
        break;
    case BUTTON_RISING:
        if (delay_read(&debounce_delay))
        {
            if (!button_state) /* Button released event */
            {
                button_released();
                button_fsm_state = BUTTON_UP;
            } else {
                button_fsm_state = BUTTON_DOWN;
            }
        }
    default:
        /* The program shouldn't reach this point */
        debounce_error_handler();
        break;
    }
}

/**
 * @brief Read and clear button falling edge event.
 * @retval bool_t
*/
bool_t read_key(void)
{
    if (falling_edge_event)
    {
        falling_edge_event = false;
        return true;
    }
    return false;
}

/**
  * @brief  Button pressed callback.
  * @retval None
  */
__attribute__((weak)) void button_pressed(void)
{
    /* NOTE: Button pressed callback. Should be implemented by the user */
}

/**
  * @brief  Button released callback.
  * @retval None
  */
__attribute__((weak)) void button_released(void)
{
    /* NOTE: Button pressed callback. Should be implemented by the user */
}

/**
  * @brief  Module error handling callback.
  * @retval None
  */
__attribute__((weak)) void debounce_error_handler(void)
{
    /* NOTE: Debounce error handling. Should be implemented by the user */
}
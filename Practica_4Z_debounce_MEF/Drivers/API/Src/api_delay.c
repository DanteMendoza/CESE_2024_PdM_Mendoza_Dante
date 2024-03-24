
#include <assert.h>
#include "api_port.h"
#include "api_delay.h"

/**
  * @brief  Initialize delay data structure.
  * @param delay: pointer to delay data structure
  * @param duration: delay duration in miliseconds
  * @retval None
  */
void delay_init(delay_t* delay, tick_t duration)
{
  assert(delay);

  delay->duration = duration;
  delay->running = false;
}

/**
  * @brief  Check if delay reached duration (start it if not running).
  * @param delay: pointer to delay data structure
  * @retval bool
  */
bool_t delay_read(delay_t* delay)
{
  assert(delay);

  if (!delay->running)
  {
    delay->start_time = get_systick();
    delay->running = true;
    return false;
  }

  if (delay->duration <= (get_systick() - delay->start_time))
  {
    delay->running = false;
    return true;
  }

  return false;
}

/**
  * @brief  Change delay data structure duration.
  * @param delay: pointer to delay data structure
  * @param duration: duration in miliseconds to set
  * @retval None
  */
void delay_write(delay_t* delay, tick_t duration)
{
  assert(delay);

  delay->duration = duration;
}
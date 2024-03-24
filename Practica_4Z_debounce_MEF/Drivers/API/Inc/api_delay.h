
#ifndef __API_DELAY_H
#define __API_DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "api_types.h"

/* Exported types ------------------------------------------------------------*/
typedef struct {
  tick_t start_time;
  tick_t duration;
  bool_t running;
} delay_t;

/* Exported functions prototypes ---------------------------------------------*/
void delay_init(delay_t* delay, tick_t duration);
bool_t delay_read(delay_t* delay);
void delay_write(delay_t* delay, tick_t duration);

#ifdef __cplusplus
}
#endif

#endif /* __API_DELAY_H */
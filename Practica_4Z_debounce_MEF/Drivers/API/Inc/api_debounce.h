
#ifndef __API_DEBOUNCE_H
#define __API_DEBOUNCE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "api_types.h"

/* Exported functions prototypes ---------------------------------------------*/
void debounce_fsm_init(void);
void debounce_fsm_update(void);
bool_t read_key(void);
void button_pressed(void);
void button_released(void);
void debounce_error_handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __API_DEBOUNCE_H */
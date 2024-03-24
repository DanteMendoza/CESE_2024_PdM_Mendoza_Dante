#ifndef __API_PORT_H
#define __API_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "api_types.h"

/* Exported functions prototypes ---------------------------------------------*/
tick_t get_systick(void);
bool_t read_button(void);

#ifdef __cplusplus
}
#endif

#endif /* __API_PORT_H */
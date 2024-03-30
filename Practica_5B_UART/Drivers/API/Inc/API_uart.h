/**
 ******************************************************************************
 * @file    API_uart.h
 * @author  Mendoza, Dante.
 * @brief   UART Modulo.
 ******************************************************************************
 */

#ifndef API_UART_H_
#define API_UART_H_

#include "API_types.h"

bool_t uartInit();
void uartSendString(uint8_t *pstring);
void uartSendStringSize(uint8_t *pstring, uint16_t size);
void uartReceiveStringSize(uint8_t *pstring, uint16_t size);

#endif /* API_UART_H_ */

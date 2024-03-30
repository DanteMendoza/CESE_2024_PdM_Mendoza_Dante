/**
 ******************************************************************************
 * @file    API_uart.h
 * @author  Mendoza, Dante.
 * @brief   UART Modulo.
 ******************************************************************************
 */

#include "API_uart.h"
#include "stm32f4xx_hal.h" // Asegúrate de incluir la biblioteca HAL correspondiente
#include <assert.h>
#include "main.h"

UART_HandleTypeDef huart;

bool_t uartInit() {
    // Configurar los parámetros de la UART (baudrate, etc.)
    huart.Instance = USARTx; // Definido en main.h
    huart.Init.BaudRate = 115200;
    huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE; // "handshaking"
    huart.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart) != HAL_OK) {
        // Manejar error de inicialización
        return false;
    }

    // Imprimir mensaje con los parámetros de configuración
    char config_msg[] =
            "UART CONFIGURATION:\r\n"
            "Baud Rate: 115200\r\n"
            "Parity: None\r\n"
            "Bits: 8\r\n"
            "Stopbits: 1\r\n"
            "Flow control: None\r\n"; // "handshaking"
    //printf("UART initialized with baudrate: %lu\r\n", huart.Init.BaudRate);
    HAL_UART_Transmit(&huart, (uint8_t*)config_msg, sizeof(config_msg), HAL_MAX_DELAY);

    return true;
}

void uartSendString(uint8_t *pstring) {
    // Implementación de la función para enviar el string completo
	assert(pstring);
	uint8_t i = 0;
	while (pstring[i] != '\0') i++;
	uartSendStringSize(pstring, i);
}

void uartSendStringSize(uint8_t *pstring, uint16_t size) {
    // Implementación de la función para enviar el string con tamaño específico
	assert(pstring);
	HAL_UART_Transmit(&huart, pstring, size, HAL_MAX_DELAY);
}

void uartReceiveStringSize(uint8_t *pstring, uint16_t size) {
    // Implementación de la función para recibir un string con tamaño específico
	assert(pstring);
	HAL_UART_Receive(&huart, pstring, size, HAL_MAX_DELAY);
}

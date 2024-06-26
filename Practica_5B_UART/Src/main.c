/**
 ******************************************************************************
 * @file    Proyectos\STM32CubeIDE\CESE_2024_PdM_Mendoza_Dante/Practica_4A_debounce_MEF/Src/main.c
 * @author  Mendoza, Dante.
 * @brief   Practica sobre debounce MEF.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BLINK_MAX_PERIOD  500
#define BLINK_STEP_PERIOD 100

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
//UART_HandleTypeDef UartHandle;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
	/* Configure the system clock to 180 MHz */
	SystemClock_Config();
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	debounceFSM_init();

	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

	// Inicializar LEDs usando BSP
	BSP_LED_Init(LED2); // Azul.

	// Apagamos todos los leds previamente.
	BSP_LED_Off(LED2);

	debounceConfig(LED2, BUTTON_USER);

	tick_t period_led2 = BLINK_STEP_PERIOD;
	delay_t delay_led2;
	delayInit(&delay_led2, period_led2);

	/* Infinite loop */
	while (1) {

		debounceFSM_update();

		if (delayRead(&delay_led2))
			BSP_LED_Toggle(LED2);
		if (readKey()) {
			period_led2 = (period_led2 + BLINK_STEP_PERIOD) % BLINK_MAX_PERIOD;
			delayWrite(&delay_led2, period_led2);
		}
	}
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 180000000
 *            HCLK(Hz)                       = 180000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 360
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
	 clocked below the maximum system frequency, to update the voltage scaling value
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 360;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		/* Initialization Error */
		Error_Handler();
	}

	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		/* Initialization Error */
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		/* Initialization Error */
		Error_Handler();
	}
}
/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* Turn LED2 on */
	BSP_LED_On(LED2);
	while (1) {
	}
}


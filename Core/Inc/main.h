/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ULTRASOUND_TRIG_Pin GPIO_PIN_6
#define ULTRASOUND_TRIG_GPIO_Port GPIOE
#define HUMAN_SENSOR_Pin GPIO_PIN_2
#define HUMAN_SENSOR_GPIO_Port GPIOA
#define BEEP_Pin GPIO_PIN_5
#define BEEP_GPIO_Port GPIOA
#define ULTRASOUND_ECHO_Pin GPIO_PIN_6
#define ULTRASOUND_ECHO_GPIO_Port GPIOA
#define SERVO_Pin GPIO_PIN_10
#define SERVO_GPIO_Port GPIOB
#define KEY3_Pin GPIO_PIN_4
#define KEY3_GPIO_Port GPIOG
#define KEY4_Pin GPIO_PIN_5
#define KEY4_GPIO_Port GPIOG
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOG
#define LED4_Pin GPIO_PIN_11
#define LED4_GPIO_Port GPIOG
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOG
#define LED1_Pin GPIO_PIN_14
#define LED1_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */
#define bool_t uint8_t
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

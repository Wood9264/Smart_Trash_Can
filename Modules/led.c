#include "led.h"

void led_on(uint8_t led)
{
    switch (led)
    {
        case 1:
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void led_off(uint8_t led)
{
    switch (led)
    {
        case 1:
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
            break;
        default:
            break;
    }
}

void led_toggle(uint8_t led)
{
    switch (led)
    {
        case 1:
            HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
            break;
        case 2:
            HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
            break;
        case 3:
            HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
            break;
        case 4:
            HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
            break;
        default:
            break;
    }
}

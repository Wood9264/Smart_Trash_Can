#include "communication.h"

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);

    return ch;
}

uint8_t rx_data;

void communication_init(void)
{
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&rx_data, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        HAL_UART_Receive_IT(&huart1, &rx_data, 1);

        if (rx_data == '1')
        {
            set_idel_mode((led_idle_mode_e)LED_IDLE_MODE_BREATHING);
        }
        else if (rx_data == '2')
        {
            set_idel_mode((led_idle_mode_e)LED_IDLE_MODE_RUNNING);
        }
        else if (rx_data == '3')
        {
            set_idel_mode((led_idle_mode_e)LED_IDLE_MODE_WATER);
        }
    }
}

// #include <stdint.h>
#include <stm32l4p5xx.h>
#define DELAY_COUNT 100000

int main(void)
{
    volatile int i = 0;
    /* Enable the PWR clock */
    RCC->APB1ENR1 = (RCC->APB1ENR1 & ~RCC_APB1ENR1_PWREN_Msk) | RCC_APB1ENR1_PWREN;

    /* Set IOSV in PWR_CR2 */
    PWR->CR2 = (PWR->CR2 & ~PWR_CR2_IOSV_Msk) | PWR_CR2_IOSV; 
    
    /* Enable the GPIO Clk */
    RCC->AHB2ENR = (RCC->AHB2ENR & ~RCC_AHB2ENR_GPIOGEN_Msk) | RCC_AHB2ENR_GPIOGEN;
    /* Reading the register because the RM0432 suggests it, after enabling the clock */
    (void)RCC->AHB2ENR;

    /* Clear and Set the MODER for pin 13 */
    GPIOG->MODER = (GPIOG->MODER & ~GPIO_MODER_MODE13_Msk) | GPIO_MODER_MODE13_0;

    while (1) {
        /* Pin 13 Low (LED ON)*/
        GPIOG->BSRR = GPIO_BSRR_BR13;

        /* Delay */
        for(i = 0; i < DELAY_COUNT; i++);
        
        /* Pin 13 High (LED OFF)*/
        GPIOG->BSRR = GPIO_BSRR_BS13;
        
        /* Delay */
        for(i = 0; i < DELAY_COUNT; i++);
    }
}
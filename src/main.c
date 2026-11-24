#include <stdint.h>

uint32_t counter_init = 0x12345678;   /* lives in .data */
uint32_t counter_zero;                /* lives in .bss  */

int main(void)
{
    while (1) {
        counter_zero++;
    }
}
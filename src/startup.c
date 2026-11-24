#include <stdint.h>

extern uint32_t _estack;          /* symbol from linker.ld */

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss; 

void Reset_Handler(void);
int main (void);

__attribute__((section(".isr_vector"), used))
const uint32_t vector_table[] = {
    (uint32_t)&_estack,           /* word 0: initial stack pointer */
    (uint32_t)Reset_Handler,      /* word 1: reset handler address */
};

void Reset_Handler(void)
{
    /* Copy .data from the flash (_sidata) to the RAM (_sdata ... _edata) */
    uint32_t *src = &_sidata;
    uint32_t *dest = &_sdata;
    uint32_t *bss_ptr = &_sbss;
    
    while(dest < &_edata)
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    /* Zero .bss (_sbss .. _ebss) */
    while(bss_ptr < &_ebss)
    {
        *bss_ptr = 0U;
        bss_ptr++;
    }

    /* Call main() */
    main();

    while (1) { }
}

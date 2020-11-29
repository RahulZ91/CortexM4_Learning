/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#include<stdio.h>

#define IRQ_n	39

int main(void)
{
	// IRQ for USART3 is 39 , Hence ISPR1 is used
	// 1. Pend the interrupt in the ISPR
	uint32_t *pISPR1=(uint32_t *)(0xE000E204);// ISPR0 + offset --> ISPR1
	// Set the bit for IRQ 39
	*pISPR1 |= (1<<(IRQ_n % 32)); // bit position 7 of the ISPR1 set

	// 2. Enable the interrupt
	uint32_t *pISER1=(uint32_t *)(0xE000E104);
	// set the bit for IRQ 39
	*pISER1 |= (1<<(IRQ_n % 32)); // bit position 7 of the ISER1 set
//	for(;;);
}

void USART3_IRQHandler(void)
{
	printf("USART3 ISR\n");
}

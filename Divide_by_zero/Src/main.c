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

#include<stdio.h>
#include<stdint.h>

int div_test(int x,int y);
int main(void)
{
	// access the SCB and then the SHSCR for the cortex M4 processor
	uint32_t *pSHCRS=(uint32_t *)0xE000ED24; // pointer that points to a memory location at 0xE000ED24

	// enable the bits for mem manage,bus fault and usage fault
	*pSHCRS |= (1<<16);
	*pSHCRS |= (1<<17);
	*pSHCRS |= (1<<18);

	// enable the divide by zero trap - control and configuration regsiter
	uint32_t *pDivZero=(uint32_t *)0xE000ED14; // pointer to base address of ccr
	*pDivZero |= (1<<4);

	// call a function to test
	div_test(5,0);

}

void BusFault_Handler()
{
	printf("Exception: Bus fault");
	while(1);
}

void MemManage_Handler()
{
	printf("Exception: Mem manage");
	while(1);
}

// the value of the MSP is required to analyse the contents of the stack
// we write a function in assembly to directly store the value of MSP in ro
// code in assembly avoids the epilogue and the prologue to the function

__attribute__((naked)) void UsageFault_Handler(void)
{
	// this function contains code in only assembly
	__asm("MRS r0,MSP");
	__asm("B UsageFault_Handler_c"); // branches to UsageFault_Handler_c function pBaseStack contains the value of r0 which is the base address of the MSP
}

void UsageFault_Handler_c(uint32_t *pBaseStack)
{
	uint32_t *pUFSR=(uint32_t *)0xE000ED2A;
	printf("Exception: Usage fault");
	printf("Status register for Usage fault = %lx\n",((*pUFSR)&0xFFFF));
	printf("MSP value = %p\n",pBaseStack);
	printf("Value of r0 = %lx\n",pBaseStack[0]);
	printf("Value of r1 = %lx\n",pBaseStack[1]);
	printf("Value of r2 = %lx\n",pBaseStack[2]);
	printf("Value of r3 = %lx\n",pBaseStack[3]);
	printf("Value of r12 = %lx\n",pBaseStack[4]);
	printf("Value of LR = %lx\n",pBaseStack[5]);
	printf("Value of PC = %lx\n",pBaseStack[6]);
	printf("Value of XPSR = %lx\n",pBaseStack[7]);

	while(1);
}

void HardFault_Handler()
{
	printf("Exception: Hard fault");
	while(1);
}

int div_test(int x,int y)
{
	return x/y;
}




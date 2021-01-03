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
int main(void)
{
	// access the SCB and then the SHSCR for the cortex M4 processor
	uint32_t *pSHCRS=(uint32_t *)0xE000ED24; // pointer that points to a memory location at 0xE000ED24

	// enable the bits for mem manage,bus fault and usage fault
	*pSHCRS |= (1<<16);
	*pSHCRS |= (1<<17);
	*pSHCRS |= (1<<18);

	// execute an invalid function to evoke the fault handlers
	uint32_t *pSRAM=(uint32_t *)0x20010000;  // points to a memory location 0x200010000
	*pSRAM=0xFFFFFFFF; // stores an invalid OPCODE at the location 0x200010000

	void (*addr) (void);
	addr=(void *)0x20010001; // the last bit of the address has to be 1 since the Thumb bit is required to 1 if 0 then that is the ARM state- ARM instruction set is not supported and hence we get an error
	addr();


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



#include "User_IT.h"

uint32_t TimingDelay;

void SysTick_Handler(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

void DelayUs(uint32_t TimeDelay)
{
	TimingDelay = TimeDelay;
	while(TimingDelay);
}

#include "User_Time.h"

// Init for systick, config for 1us
void Delay_Config(uint32_t Divide)
{
	SysTick_Config(SystemCoreClock/Divide);
}


#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO;
	GPIO.GPIO_Pin = GPIO_Pin_13;
	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	
	while (1)
	{
		DelayUs(1000000);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
	}
}

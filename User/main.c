#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_SysTick();
	Init_Timer();
	Init_Interrupt();

	
		//test
//	GPIO_InitTypeDef GPIO;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
//	GPIO.GPIO_Pin = GPIO_Pin_13;
//	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOC, &GPIO);
	
	
	while (1)
	{
		if (StartPos(270))
		{
			DisplayWord("A");
		}
		DisplayLine(0,0,0,0,0);
		
	}
	
}

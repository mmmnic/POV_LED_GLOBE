#include <Function.h>

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	
//	GPIO_InitTypeDef GPIO;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	
//	GPIO.GPIO_Pin = GPIO_Pin_13;
//	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOC, &GPIO);
	
//	TimingPos=0;
	while (1)
	{
		if (StartPos(270))
		{
			DisplayChar('B');
		}
	}
	
}

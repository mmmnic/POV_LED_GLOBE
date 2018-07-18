#include <Function.h>


int main(void)
{
	Init_GPIO();
	Init_Delay();
	
	while (1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction) (1^GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)));
		DelayUs(100000);
	}
}

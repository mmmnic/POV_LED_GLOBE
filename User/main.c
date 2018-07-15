#include <User_GPIO.h>
#include <User_Time.h>
#include <User_IT.h>

int main(void)
{
	Init_GPIO();
	Delay_Config(1000000);
	
	while (1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction) (1^GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)));
		DelayUs(1000000);
	}
}

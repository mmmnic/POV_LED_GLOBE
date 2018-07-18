#include <Init.h>


// Global para
uint32_t TimingDelay;


/**
  * @brief  Config Pin A1, A2, A3, A4 as Ouput, B9 as input
  * @param  None
  * @retval None
  */
void Init_GPIO(void)
{
	GPIO_InitTypeDef		GPIO_InitStructure;
	
	// Enable clock for GPIOA and GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// Config GPIOA, Pin: 1,2,3,4 as output
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// Config GPIOB, Pin 9 as input
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// Set Pin A1 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	// Set Pin A2 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	// Set Pin A3 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	// Set Pin A4 High
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

/**
  * @brief  Config Systick
  * @param  Divide for divde system code clock
  * @retval None
  */
void Init_Delay(void)
{
	SysTick_Config(SystemCoreClock/1000000);
}


/**
  * @brief  Handler interrupt of Systick
  * @param  Global para TimingDelay
  * @retval None
  */
void SysTick_Handler(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

/**
  * @brief  Delay at us
  * @param  Global para TimingDelay, private para TimeDelay for counting
  * @retval None
  */
void DelayUs(uint32_t TimeDelay)
{
	TimingDelay = TimeDelay;
	while(TimingDelay);
}

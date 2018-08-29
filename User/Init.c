#include <Init.h>

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
	
	// Config GPIOB, Pin 9 as input, Pull up
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// Set Pin A1 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	// Set Pin A2 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	// Set Pin A3 Low
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	// Set Pin A4 High
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}

/**
  * @brief  Config for TIM2
  * @param  None
  * @retval None
  */
void Init_Timer(void)
{
	TIM_TimeBaseInitTypeDef 	TIM_TimeBaseStructure;
	NVIC_InitTypeDef 					NVIC_Structure;
	
	// Enable clock
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	// Configure TIM2
	// prescaler = 1,  Period = 35 for 0.000,001(s)
	// prescaler = 9,  Period = 71 for 0.000,01	(s)
	// prescaler = 24, Period = 71 for 0.000,025(s)
	// prescaler = 49, Period = 71 for 0.000,05	(s)
	
	TIM_TimeBaseStructure.TIM_Prescaler = 9;
	TIM_TimeBaseStructure.TIM_Period = 71;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	// Configure Interrupt for TIM2
	NVIC_Structure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_Structure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Structure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Structure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Structure);
	// Enable TIM2
	TIM_Cmd(TIM2, ENABLE);
}

/**
  * @brief  Init for Interrupt
  * @param  None
  * @retval None
  */
void Init_Interrupt(void)
{
	EXTI_InitTypeDef	EXTI_Structure;
	NVIC_InitTypeDef	NVIC_Structure;
	
	// Open clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	// Mapping
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource9);
	// Clear pending
	EXTI_ClearITPendingBit(EXTI_Line9);
	// EXTI LINE Config
	EXTI_Structure.EXTI_Line = EXTI_Line9;
	EXTI_Structure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Structure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Structure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_Structure);
	
	//NVIC Config
	NVIC_Structure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_Structure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Structure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Structure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Structure);
}

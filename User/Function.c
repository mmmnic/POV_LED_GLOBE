// Include
#include <Function.h>

uint8_t C[5][5] = 
{
	{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111},
	{0b11111111,0b11111111,0b11111100,0b11110000,0b11000000},
	{0b11111111,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b11111111,0b00111111,0b00001111,0b00000011},
	{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111},
};

uint8_t E[5][5] = 
{
	{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111},
	{0b11111111,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111},
	{0b11111111,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b11111111,0b11111111,0b11111111,0b11111111},
};



/**
  * @brief  Clear data for all LED
  * @param  none
  * @retval None
  */
void ClearData(void)
{
	// Make sure Pin A4 is High to set LOW
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	// RESET Pin A4 to clear Data
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	// Send Data
	SendData();
}	

/**
  * @brief  Clear data for all LED
  * @param  
  * @retval None
  */
void ShiftLED(void)
{
	// Make sure Pin A2 is LOW to set HIGH
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	// SET Pin A3 to send Data
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

/**
  * @brief  InputData for LED
  * @param  none
  * @retval None
  */
void SendData(void)
{
	// Make sure Pin A3 is LOW to set HIGH
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	// SET Pin A3 to send Data
	GPIO_SetBits(GPIOA, GPIO_Pin_3);
}

/**
  * @brief  InputData for LED
  * @param  none
  * @retval None
  */
void InputData(uint8_t Bit)
{
	if (Bit)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

/**
  * @brief  Filter data to send data and shift each bit
  * @param  none
  * @retval None
  */
void DisplayOneIC(uint8_t Data)
{
	if (Data & 0b10000000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b01000000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00100000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	
	if (Data & 0b00010000)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00001000)			InputData(1);
	else												InputData(0);
	ShiftLED();

	if (Data & 0b00000100)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00000010)			InputData(1);
	else												InputData(0);
	ShiftLED();
	
	if (Data & 0b00000001)			InputData(1);
	else												InputData(0);
	ShiftLED();
}

void DisplayLine(uint8_t U5, uint8_t U4, uint8_t U3, uint8_t U2, uint8_t U1)
{
	DisplayOneIC(U5);
	DisplayOneIC(U4);
	DisplayOneIC(U3);
	DisplayOneIC(U2);
	DisplayOneIC(U1);
	SendData();
}

void DisplayChar(char c)
{
	uint8_t i;
	if (c=='C')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(C[1][i],C[2][i],C[3][i],C[4][i],C[5][i]);
			DelayUs(500000);
		}
	}
}

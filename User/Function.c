// Include
#include <Function.h>

uint8_t A[5][10] =
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b01111111,0b10010000,0b10010000,0b10010000,0b01111111},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

uint8_t B[5][5]=
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b10011001,0b10011001,0b10011001,0b01100110},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

uint8_t C[5][5] = 
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b01111110,0b10000001,0b10000001,0b10000001,0b01000010},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};



uint8_t E[5][5] = 
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b10011001,0b10011001,0b10011001,0b10000001},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

uint8_t N[5][5] =
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111111,0b01100000,0b00110000,0b00001100,0b11111111},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

uint8_t O[5][5] =
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b01111110,0b10000001,0b10000001,0b10000001,0b01111110},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

	

uint8_t Q[5][5] = 
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b01111110,0b10000001,0b10000101,0b10000011,0b01111111},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
};

uint8_t U[5][5] = 
{
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b11111110,0b00000001,0b00000001,0b00000001,0b11111110},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
	{0b00000000,0b00000000,0b00000000,0b00000000,0b00000000},
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
	if (Data & 0b10000000)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	if (Data & 0b01000000)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	if (Data & 0b00100000)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	
	if (Data & 0b00010000)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	if (Data & 0b00001000)			InputData(0);
	else												InputData(1);
	ShiftLED();

	if (Data & 0b00000100)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	if (Data & 0b00000010)			InputData(0);
	else												InputData(1);
	ShiftLED();
	
	if (Data & 0b00000001)			InputData(0);
	else												InputData(1);
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
	if (c=='A')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(A[0][i],A[1][i],A[2][i],A[3][i],A[4][i]);
			DelayUs(10000);
		}
	}
	if (c=='B')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(B[0][i],B[1][i],B[2][i],B[3][i],B[4][i]);
			DelayUs(10000);
		}
	}
	if (c=='C')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(C[0][i],C[1][i],C[2][i],C[3][i],C[4][i]);
			DelayUs(500000);
		}
	}
	if (c=='E')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(E[0][i],E[1][i],E[2][i],E[3][i],E[4][i]);
			DelayUs(500000);
		}
	}
	if (c=='N')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(N[0][i],N[1][i],N[2][i],N[3][i],N[4][i]);
			DelayUs(10000);
		}
	}
	if (c=='O')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(O[0][i],O[1][i],O[2][i],O[3][i],O[4][i]);
			DelayUs(10000);
		}
	}
	if (c=='Q')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(Q[0][i],Q[1][i],Q[2][i],Q[3][i],Q[4][i]);
			DelayUs(10000);
		}
	}
	if (c=='U')
	{
		for (i=0; i<5; i++)
		{
			DisplayLine(U[0][i],U[1][i],U[2][i],U[3][i],U[4][i]);
			DelayUs(10000);
		}
	}
}

void DisplayWord(char *s)
{
	uint8_t i=0;
	while (s[i]!='\n')
	{
		DisplayChar(s[i]);
		i++;
	}
}

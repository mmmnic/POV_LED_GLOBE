// Include
#include <Function.h>

/* Private variables ---------------------------------------------------------*/
uint16_t PreviousPos=0;


/**
  * @brief  InputData for IC
  * @param  Input Binary 1 or 0, 1 is set to High, 0 is set to low
  * @retval None
  */
void InputData(uint8_t Bit)
{
	if (Bit)
	{
		// Set Pin A1 to high
		GPIOA->BSRR = 0x0002;
	}
	else
	{
		// Set Pin A1 to Low
		GPIOA->BRR  = 0x0002;
	}
}

/**
  * @brief  Shift bit of IC
  * @param  None
  * @retval None
  */
void ShiftLED(void)
{
	// Set Pin A2 to LOW for getting ready to shift bit
	GPIOA->BRR =  0x0004;
	// Set Pin A2 to HIGH to shift bit
	GPIOA->BSRR = 0x0004;
}

/**
  * @brief  Send data to IC
  * @param  none
  * @retval None
  */
void SendData(void)
{
	// Set Pin A3 to LOW for getting ready to send data
	GPIOA->BRR =  0x0008;
	// Set Pin A3 to HIGH to send data
	GPIOA->BSRR = 0x0008;
}

/**
  * @brief  Clear Data on all IC (LED is shining)
  * @param  none
  * @retval None
  */
void ClearData(void)
{
	// Set Pin A4 to LOW for enable clear data
	GPIOA->BRR =  0x0010;
	// Send Data
	SendData();
	// Set Pin A4 back to high to disable clear data
	GPIOA->BSRR = 0x0010;
}	

/**
  * @brief  Delay at us
  * @param  Global para TimingDelay, private para TimeDelay for input delay time
  * @retval None
  */
void Delay(uint32_t TimeDelay)
{
	TimingDelay = TimeDelay;
	while(TimingDelay);
}

/**
  * @brief  Check position of hall sensor
  * @param  Pos for input user's position, StandardError amount of reality and theory,  
  * @retval 1 (true) or 0 (false)
  */
uint8_t StartPos(uint16_t Pos)
{ 
	uint16_t PosTemp;
	if (Pos-PreviousPos<=0)
	{
		PreviousPos=0;
	}
	else
	{
		PosTemp=(Pos-PreviousPos)*TimePerAngle;
	}
	Delay(PosTemp);
	PreviousPos=Pos;
}

/**
  * @brief  Filter data to send data and shift each bit
  * @param  Input in binary. 1 is On, 0 is off
  * @retval None
  */
void DisplayOneIC(uint8_t Data)
{
	uint8_t i,Bit=0b10000000;
	for (i=0; i<8; i++)
	{
		if (Data & Bit)			GPIOA->BSRR = 0x0002; // Set Pin A1 to high
		else								GPIOA->BRR  = 0x0002;	// Set Pin A1 to Low

		//ShiftLED();
		// Set Pin A2 to LOW for getting ready to shift bit
		GPIOA->BRR =  0x0004;
		// Set Pin A2 to HIGH to shift bit
		GPIOA->BSRR = 0x0004;
		
		// Shift left para "Bit" for getting ready to compare the next data
		Bit=Bit>>1;
	}
}

/**
  * @brief  Config All LED to display
  * @param  5 params input in binary. 1 is On, 0 is off
  * @retval None
  */
void DisplayLine(uint8_t U5, uint8_t U4, uint8_t U3, uint8_t U2, uint8_t U1)
{
	DisplayOneIC(U5);
	DisplayOneIC(U4);
	DisplayOneIC(U3);
	DisplayOneIC(U2);
	DisplayOneIC(U1);
	//SendData();
	// Set Pin A3 to LOW for getting ready to send data
	GPIOA->BRR =  0x0008;
	// Set Pin A3 to HIGH to send data
	GPIOA->BSRR = 0x0008;
}

/**
  * @brief  Filter charater, and line position
  * @param  input char and columns
  * @retval Data of a Char depend on column
	*/
uint8_t CharCVT(char c, uint8_t times)
{
	switch (c)
	{
		case 'A':
		{
			uint8_t A[5]={0b01111110,0b10010000,0b10010000,0b10010000,0b01111110};
			return A[times];
		}
		case 'B':
		{
			uint8_t B[5]={0b11111110,0b10010010,0b10010010,0b10010010,0b01101100};
			return B[times];
		}
		case 'C':
		{
			uint8_t C[5]={0b01111100,0b10000010,0b10000010,0b10000010,0b01000100};
			return C[times];
		}
		case 'D':
		{
			uint8_t D[5]={0b11111110,0b10000010,0b10000010,0b10000010,0b01111100};
			return D[times];
		}
		case 'E':
		{
			uint8_t E[5]={0b11111110,0b10010010,0b10010010,0b10010010,0b10000010};
			return E[times];
		}
		case 'F':
		{
			uint8_t F[5]={0b11111110,0b10010000,0b10010000,0b10010000,0b10000000};
			return F[times];
		}
		case 'G':
		{
			uint8_t G[5]={0b01111100,0b10000010,0b10010010,0b10010010,0b10011100};
			return G[times];
		}
		case 'H':
		{
			uint8_t H[5]={0b11111110,0b00010000,0b00010000,0b00010000,0b11111110};
			return H[times];
		}
		case 'I':
		{
			uint8_t I[5]={0b10000010,0b10000010,0b11111110,0b10000010,0b10000010};
			return I[times];
		}
		case 'J':
		{
			uint8_t J[5]={0b00001100,0b00000010,0b00000010,0b11111100,0b00000000};
			return J[times];
		}
		case 'K':
		{
			uint8_t K[5]={0b11111110,0b00010000,0b00101000,0b01000100,0b10000010};
			return K[times];
		}
		case 'L':
		{
			uint8_t L[5]={0b11111110,0b00000010,0b00000010,0b00000010,0b00000010};
			return L[times];
		}
		case 'M':
		{
			uint8_t M[5]={0b11111110,0b01000000,0b00110000,0b01000000,0b11111110};
			return M[times];
		}
		case 'N':
		{
			uint8_t N[5]={0b11111110,0b00100000,0b00010000,0b00001000,0b11111110};
			return N[times];
		}
		case 'O':
		{
			uint8_t O[5]={0b01111100,0b10000010,0b10000010,0b10000010,0b01111100};
			return O[times];
		}
		case 'P':
		{
			uint8_t P[5]={0b11111110,0b10010000,0b10010000,0b10010000,0b01100000};
			return P[times];
		}
		case 'Q':
		{
			uint8_t Q[5]={0b01111100,0b10000010,0b10001010,0b10000110,0b01111110};
			return Q[times];
		}
		case 'R':
		{
			uint8_t R[5]={0b11111110,0b10010000,0b10011000,0b10010100,0b01100010};
			return R[times];
		}
		case 'S':
		{
			uint8_t S[5]={0b01110010,0b10010010,0b10010010,0b10010010,0b10001100};
			return S[times];
		}
		case 'T':
		{
			uint8_t T[5]={0b10000000,0b10000000,0b11111110,0b10000000,0b10000000};
			return T[times];
		}
		case 'U':
		{
			uint8_t U[5]={0b11111100,0b00000010,0b00000010,0b00000010,0b11111100};
			return U[times];
		}
		case 'V':
		{
			uint8_t V[5]={0b11111000,0b00000100,0b00000010,0b00000100,0b11111000};
			return V[times];
		}
		case 'W':
		{
			uint8_t W[5]={0b11111110,0b00000100,0b00011000,0b00000100,0b11111110};
			return W[times];
		}
		case 'X':
		{
			uint8_t X[5]={0b11000110,0b00101000,0b00010000,0b00101000,0b11000110};
			return X[times];
		}
		case 'Y':
		{
			uint8_t Y[5]={0b11000000,0b00100000,0b00011110,0b00100000,0b11000000};
			return Y[times];
		}
		case 'Z':
		{
			uint8_t Z[5]={0b10000110,0b10001010,0b10010010,0b10100010,0b11000010};
			return Z[times];
		}
		case ' ':
		{
			uint8_t Space[5]={0,0,0,0,0};
			return Space[times];
		}
	}
	
	return 0;
}

/**
  * @brief  Globe is divided into 5 rows, Display any word on any row 
  * @param  Input Start position, char for each row
  * @retval None
	*/
void DisplayWordGlobe(uint16_t Pos, char *s0, char *s1, char *s2, char *s3, char *s4)
{
	if (StartPos(Pos))
	{
		// Find longest word
		uint8_t i, max,Data[5], ArrStrLen[5] = {strlen(s0), strlen(s1), strlen(s2), strlen(s3), strlen(s4)};
		max = ArrStrLen[0];
		for (i=1; i<5; i++)
		{
			if (ArrStrLen[i]>max)
			{
				max = ArrStrLen[i];
			}
		}
		
		// Input data
		uint8_t j;
		for (i=0; i<max; i++)
		{
			for (j=0; j<5; j++)
			{
				// First row
				if (ArrStrLen[0] < i)
				{
					Data[0]=0;
				}
				else
				{
					Data[0]=CharCVT(s0[i],j);
				}
				// Second row
				if (ArrStrLen[1] < i)
				{
					Data[1]=0;
				}
				else
				{
					Data[1]=CharCVT(s1[i],j);
				}
				// Third row
				if (ArrStrLen[2] < i)
				{
					Data[2]=0;
				}
				else
				{
					Data[2]=CharCVT(s2[i],j);
				}
				// Fourth row
				if (ArrStrLen[3] < i)
				{
					Data[3]=0;
				}
				else
				{
					Data[3]=CharCVT(s3[i],j);
				}
				// fifth row
				if (ArrStrLen[4] < i)
				{
					Data[4]=0;
				}
				else
				{
					Data[4]=CharCVT(s4[i],j);
				}
				
				//Display
				DisplayLine(Data[0], Data[1], Data[2], Data[3], Data[4]);
				Delay(TimePerAngle*3);
			}
			ClearData();
			Delay(TimePerAngle*5);
		}
	}		
}

void DisplayEarth(uint16_t Pos)
{
	if (StartPos(Pos))
	{
		DisplayLine(0,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b01100000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11100000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11100000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b11100000,0,0,0);
		Delay(TimePerAngle*3);
		
		
		// 10x2
		DisplayLine(0,0b11100000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11110000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,0b11111000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,255,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b000000001,255,0b10000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11110000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11111000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11111100,0,0);
		Delay(TimePerAngle*3);
		
		
		//10x3
		DisplayLine(0,255,0b11110100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b11001111,0b11100100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b10001111,0b11100110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00001111,0b11100010,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00000111,0b11000001,0b00110000,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00000111,0b11000001,0b11111000,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00111111,0b10000000,0b11111100,0b00111110);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00111111,0,255,0b11111100);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00011110,0,255,0b11110000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00100000,0b00011010,0,0b01111111,0b11100000);
		Delay(TimePerAngle*3);
		

		//10x4
		DisplayLine(0b00110000,0b00001000,0,0b01111111,0b11000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b01110000,0b00001000,0,0b01111111,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b01111001,0b00000100,0,0b00011111,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(255,0b10000000,0,0b00011110,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(255,0b11000000,0,0b00011110,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b01111111,0b11000000,0,0b00011100,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b01111111,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00111110,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00011100,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001000,0,0,0,0);
		Delay(TimePerAngle*3);
		
		
		//10x5
		DisplayLine(0,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0,0b00011000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0,0b00111100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00000011,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b01100010,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00111110,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b00001100,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0b10011101,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000001,0b10011000,255,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000001,0b11011000,0b01111111,0b10010000,0);
		Delay(TimePerAngle*3);
		
		
		//10x6
		DisplayLine(0b00000011,0b10011000,0b01111111,0b11111110,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0b00011100,0b01111111,255,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000110,0b10111100,0b01111111,0b11111110,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b11111100,0b01111111,0b11111110,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000101,0b11111010,0b01111111,0b11111100,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0b11111010,0b01011111,0b11110000,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0b11111011,0b11001111,0b11110000,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,255,0b11100111,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000001,255,0b11111010,0b00001100,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,0b11111001,0b10111010,0b00011000,0);
		Delay(TimePerAngle*3);
		
		
		//10x7
		DisplayLine(0b00000011,0b11111000,0b11010000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,255,0b11010000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,255,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,255,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,255,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001101,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,255,0b11110000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000101,255,0b11111100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,255,0b11110000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		
		//10x8
		DisplayLine(0b00001111,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00011111,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00011111,255,0b11110000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00011111,255,0b11111000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00111111,255,0b11111100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00111111,255,0b11111110,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00011111,255,0b11100100,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,255,0b11100000,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,0b11111110,0b11000000,0,0);
		Delay(TimePerAngle*3);
		
		
		//10x9
		DisplayLine(0b00001111,0b11111110,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,255,0,0b00000011,0b11000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b11111100,0,0b00000011,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b11111100,0,0b00000111,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b11011000,0,0b00000111,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b10000000,0,0b00001111,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00001111,0b10000000,0,0b00001111,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b10000000,0,0b00000111,0b10000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b10000000,0,0b00000111,0b11000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000111,0b10000000,0,0b00001111,0b11000000);
		Delay(TimePerAngle*3);
		
		
		//10x10
		DisplayLine(0b00000111,0b01100000,0,0b00000111,0b11010000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,0b01000000,0,0b00000001,0b11000000);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,0b10000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,0b10000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000011,0b10000000,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0b00000010,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0,0,0,0);
		Delay(TimePerAngle*3);
		
		DisplayLine(0,0,0,0,0);
		Delay(TimePerAngle*3);
	}
}



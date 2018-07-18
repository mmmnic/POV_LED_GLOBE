// Include
#include <Function.h>

/**
  * @brief  Clear data for all LED
  * @param  none
  * @retval None
  */
void ClearData(void)
{
	// To ClearData Pin A4 at RESET
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == SET) // Check if Pin A4 is SET or RESET
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);								 //	If Pin A4 is SET switch to RESET to ClearData
	}
 
	// To send signal Pin A3 is changed from RESET to SET 
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == RESET) // Check if Pin A3 is RESET
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_3);										 // If true switch to SET to send signal
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);									// Else switch to RESET
		GPIO_SetBits(GPIOA, GPIO_Pin_3);										// Change to SET again to send signal
	}
	
	// Return to first state;
	GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
}	

/**
  * @brief  Clear data for all LED
  * @param  none
  * @retval None
  */
void ShiftLED(void)
{
	// To shift LED Pin A2 is changed from RESET to SET 
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == RESET) // Check if Pin A2 is RESET
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);										 // If true switch to SET to send signal
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);									// Else switch to RESET
		GPIO_SetBits(GPIOA, GPIO_Pin_2);										// Change to SET again to send signal
	}
	
	// Return to first state
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}



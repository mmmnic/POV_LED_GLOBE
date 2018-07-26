// Include
#include <Init.h>

void InputData(uint8_t Bit);
void ShiftLED(void);
void SendData(void);
void ClearData(void);
void DisplayOneIC(uint8_t Data);
void DisplayLine(uint8_t U1, uint8_t U2, uint8_t U3, uint8_t U4, uint8_t U5); 
void DisplayChar(char c);
void DisplayWord(char *s);
void Timer_On(TIM_TypeDef* TIMx, uint8_t Bit);
void DelayUs(uint32_t TimeDelay);

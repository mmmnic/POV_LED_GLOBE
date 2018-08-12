// Include
#include <Init.h>

extern uint32_t TimingDelay;
extern uint32_t	TimingPos;
extern uint8_t	TimePerAngle;


void InputData(uint8_t Bit);
void ShiftLED(void);
void SendData(void);
void ClearData(void);
void DisplayOneIC(uint8_t Data);
void DisplayLine(uint8_t U1, uint8_t U2, uint8_t U3, uint8_t U4, uint8_t U5); 
void DisplayChar(char c);
void DisplayWord(char *s);
void DelayUs(uint32_t TimeDelay);
uint8_t StartPos(uint16_t Pos);

// Include
#include <Init.h>
#include <string.h>

extern uint32_t Timing;
extern uint32_t TimingDelay;
extern uint32_t	TimingPos;
extern uint32_t	TimePerAngle;

void InputData(uint8_t Bit);
void ShiftLED(void);
void SendData(void);
void ClearData(void);
void Delay(uint32_t TimeDelay);
uint8_t StartPos(uint16_t Pos);
void DisplayOneIC(uint8_t Data);
void DisplayLine(uint8_t U1, uint8_t U2, uint8_t U3, uint8_t U4, uint8_t U5);
uint8_t CharCVT(char c, uint8_t times);
uint8_t *convertToInt(uint8_t data[40][17], uint8_t column);
void DisplayWordsGlobe(uint16_t Pos, char *s1, char *s2, char *s3, char *s4, char *s5);
void DisplayWordsMove(int32_t speed, char *s1, char *s2, char *s3, char *s4, char *s5);
void DisplayEarth(uint16_t Pos);
void DisplayHeart(uint16_t Pos);
void DisplayUITHSVLogo(uint16_t Pos);
void DisplayCityHSVLogo(uint16_t Pos);
void DisplayLogoVNU(uint16_t Pos);
void DisplayLogoUIT(uint16_t Pos);
void DisplayLightBulb(uint16_t Pos);
void DisplayLogoFIRA(uint16_t Pos);

#include <Function.h>


int main(void)
{
	Init_GPIO();
	Init_Delay();


	
	while (1)
	{
		DisplayWord("CEEC");
	}
}

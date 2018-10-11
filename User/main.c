#include <Function.h>

void MiniDelay(uint16_t Time);

int main(void)
{
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

//	if (StartPos(0))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(90))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(180))
//		DisplayLine(255,255,255,255,255);
//	if (StartPos(270))
//		DisplayLine(255,255,255,255,255);
//	ClearData();
	uint32_t time,i;
	uint8_t loop;
	
	while (1)
	{
		DisplayWordGlobe(300,"","CHAO MUNG","DAI HOI IV","","");
		MiniDelay(500);
		for (loop=0; loop<2; loop++)
		{
			for (i=300; i!=301; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,"","CHAO MUNG","DAI HOI IV","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
		DisplayWordGlobe(270,"","DAI HOI IV","HOI SINH VIEN VIET NAM","","");
		MiniDelay(500);
		for (loop=0; loop<2; loop++)
		{
			for (i=270; i!=271; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,"","DAI HOI IV","HOI SINH VIEN VIET NAM","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
		DisplayWordGlobe(270,"","      DAI HOC      ","CONG NGHE THONG TIN","","");
		MiniDelay(500);
		for (loop=0; loop<2; loop++)
		{
			for (i=270; i!=271; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,"","      DAI HOC      ","CONG NGHE THONG TIN","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
		
		DisplayWordGlobe(300,"","DAI HOI IV","2018 - 2020","","");
		MiniDelay(500);
		for (loop=0; loop<2; loop++)
		{
			for (i=300; i!=301; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,"","DAI HOI IV","2018 - 2020","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
		DisplayHSVLogo(280);
		MiniDelay(500);
		DisplayWordGlobe(300,"","   UIT   ","WE ARE ONE","","");
		for (loop=0; loop<2; loop++)
		{
			for (i=300; i!=301; i--)
			{
				time=2000;
				while(time<=2000)
				{
					DisplayWordGlobe(i,"","   UIT   ","WE ARE ONE","","");
					time--;
				}
				if (i==1)
				{
					i=355;
				}
			}
		}
	}
}

void MiniDelay(uint16_t Time)
{
	for(uint16_t i=0; i<Time; i++)
	{
		for(uint16_t j=0; j<6500; j++);
	}
}

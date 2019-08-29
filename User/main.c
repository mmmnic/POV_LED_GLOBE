#include <Function.h>

int main(void)
{
	//-------------------- INIT --------------------
	Init_GPIO();
	Init_Timer();
	Init_Interrupt();

	uint8_t loop;
//	uint16_t TempPos=0;
	uint32_t time,i;
	char  string1[50],string2[120], string3[50] = "";
	
	//wait to get enough speed before entering infinity loop
	time=75000;
	while (time>=5)
	{
		DisplayLine(255,255,255,255,255);
		time--;
	}
	while (1)
	{
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		for (i=305; i!=306; i--)
		{
			time=4000;
			while(time<=4000)
			{
				DisplayLogoFIRA(i);
				time--;
			}
			if (i<=1)
				i=362;
		}
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		strcpy(string1,"   FIRA - WELCOME");
		strcpy(string2,"CHAO MUNG NAM HOC MOI");
		DisplayWordsMove(10000,"",string1,string2,string3,"");
		
		
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		for (i=305; i!=306; i--)
		{
			time=4000;
			while(time<=4000)
			{
				DisplayLogoFIRA(i);
				time--;
			}
			if (i<=1)
				i=362;
		}
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		strcpy(string1,"       FIRA - WELCOME");
		strcpy(string2,"CHAO MUNG CAC BAN TAN SINH VIEN");
		DisplayWordsMove(10000,"",string1,string2,string3,"");
		
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		for (i=305; i!=306; i--)
		{
			time=4000;
			while(time<=4000)
			{
				DisplayLogoFIRA(i);
				time--;
			}
			if (i<=1)
				i=362;
		}
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		strcpy(string2,"FIRA MANG DEN GIA TRI CONG DAN TOAN CAU: LUON LAM TRON TRACH NHIEM VOI BAN THAN - GIA DINH - XA HOI - THIEN NHIEN");
		DisplayWordsMove(8000,"",string1,string2,string3,"");
		time=500000;
		while (time>=5)
		{
			DisplayLogoFIRA(305);
			time--;
		}
		for (loop=0; loop<2; loop++)
		{
			for (i=305; i!=306; i--)
			{
				time=8000;
				while(time<=8000)
				{
					DisplayLogoFIRA(i);
					time--;
				}
				if (i<=1)
				i=362;
			}
		}
	}
}
//KHOA CONG NGHE THONG TIN - ROBOT VA TRI TUE NHAN TAO
//CHAO MUNG CAC BAN TAN SINH VIEN
//CHAO MUNG NAM HOC MOI
//FIRA MANG DEN GIA TRI CONG DAN TOAN CAU: "LUON LAM TRON TRACH NHIEM VOI BAN THAN - GIA DINH - XA HOI - THIEN NHIEN

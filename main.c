#include <REGX52.H>

#include"Timer0.h"

#include"LCD1602.h"

unsigned char sec=0,min=0,hour=0;


void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock");
	LCD_ShowString(2,1,"  :  :  ");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
		
	}
}
void Timer0_Routine() interrupt 1
{
	static int Counter0;
	TH0 = 0xFC;
	TL0 = 0X18;
	Counter0++;
	if(Counter0 == 1000)
	{
		Counter0 = 0;
		sec++;
		if(sec == 60)
		{
			sec = 0;
			min++;
			if(min == 60)
			{
				min = 0;
				hour++;
				if(hour == 24)
				{
					hour = 0;
				}
			}
		}
	}
//	P2 = 0;
//	P2_7 = 1;
}
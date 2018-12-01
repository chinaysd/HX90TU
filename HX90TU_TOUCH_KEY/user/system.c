#include "system.h"

unsigned int My_KeyValue;
LINE_PARA_T Line_Para_t[LINE_NUM];
TIMEOUT_PARA TimeOut_Para[2];

void System_Init(void)
{
	static unsigned char i;
    TimeOutDet_Init();
	TouchKeyInit();
	for(i = 0;i < LINE_NUM;i ++)
	{
		Line_Para_t[i].ID = i;
		Line_App_Init(&Line_Para_t[i]);
	}
	Line_Status(Line2,Line2_Hight);
    Timer_Init();
}

void System_Handle(void)
{
    static unsigned int Cnt;
	if(SOCAPI_TouchKeyStatus&0x80)
	{
		SOCAPI_TouchKeyStatus &=0x7f;  // ��Ҫ����  3:  �����־λ�� ��Ҫ�ⲿ�����
        My_KeyValue = TouchKeyScan();
		switch (My_KeyValue)
		{
			case 0x0002:
			              Line_Status(Line2,Line2_Low);
				          break;
			case 0x0040:  
				          Line_Status(Line2,Line2_Low);
				          break;
			default:
				          Line_Status(Line2,Line2_Hight);
				          break;
		}
		TouchKeyRestart();
	}
	if(TimeOutDet_Check(&TimeOut_Para[0]))
    {
        TimeOut_Record(&TimeOut_Para[0],1000);
        ++ Cnt;
        if(Cnt & 0x01)
        {
            Line_Status(Line1,Line1_Hight);
        }
        else
        {
            Line_Status(Line1,Line1_Low);
        }
    }
}

/**************************************************
*�������ƣ�void timer0/1/2() interrupt 1/3/5
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
**************************************************/
void timer0() interrupt 1
{
    TL0 = (65536 - 16000)%256;
	TH0 = (65536 - 16000)/256;
	TimeOutDet_DecHandle();	
}

void timer1() interrupt 3
{
	
}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //�������
   
}



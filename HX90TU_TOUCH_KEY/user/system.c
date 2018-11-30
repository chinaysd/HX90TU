#include "system.h"

unsigned int My_KeyValue;
LINE_PARA_T Line_Para_t[LINE_NUM];

void System_Init(void)
{
	static unsigned char i;
	TouchKeyInit();
	for(i = 0;i < LINE_NUM;i ++)
	{
		Line_Para_t[i].ID = i;
		Line_App_Init(&Line_Para_t[i]);
	}
	Line_Status(Line2,Line2_Hight);
}

void System_Handle(void)
{
	if(SOCAPI_TouchKeyStatus&0x80)
	{
		SOCAPI_TouchKeyStatus &=0x7f;  // 重要步骤  3:  清除标志位， 需要外部清除。
    My_KeyValue = TouchKeyScan();
		switch (My_KeyValue)
		{
			case 0x0002:
				          //Line_Status(Line1,Line1_Hight);
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
	
}



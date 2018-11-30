#include "bsp_line.h"

unsigned char Line_Init(unsigned char ID)
{
	if(ID == 0)
	{
		P1CON |= 0X08;
		P1PH  &= ~0X08;
	}
	else if(ID == 1)
	{
		P2CON |= 0X02;
		P2PH  &= ~0X02;
	}
	else
	{
		return 0;
	}
	return 1;
}

unsigned char Line_App_Init(LINE_PARA_T *p)
{
	unsigned char Line_Init(unsigned char ID);
	return Line_Init(p->ID);
}

unsigned char Line_Status(unsigned char ID,unsigned char status)
{
	if(ID == 0)
	{
		if(status == 0)
		{
			Line1_Set(status);
		}
		else if(status == 1)
		{
			Line1_Set(status);
		}
		return 0;
	}
	else if(ID == 1)
	{
		if(status == 0)
		{
			Line2_Set(status);
		}
		else if(status == 1)
		{
			Line2_Set(status);
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

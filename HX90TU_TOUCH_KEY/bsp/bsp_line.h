#ifndef _BSP_LINE_H_
#define _BSP_LINE_H_

#include "sc92f827x_c.h"

#define   LINE_NUM      2

#define   Line1         0
#define   Line2         1

#define   Line1_Hight   1
#define   Line1_Low     0
#define   Line2_Hight   1
#define   Line2_Low     0

#define LINE_ENABLE     1
#define LINE_DISABLE    0

typedef struct
{
	unsigned char ID;
}
LINE_PARA_T;

#if LINE_ENABLE
#define LINE1_PORT      P1
#define LINE1_PIN       P13
#define Line1_Set(x)    ((x)?(LINE1_PIN = 1):(LINE1_PIN = 0))

#define LINE2_PORT      P2
#define LINE2_PIN       P21
#define Line2_Set(x)    ((x)?(LINE2_PIN = 1):(LINE2_PIN = 0))
#endif


unsigned char Line_App_Init(LINE_PARA_T *p);
unsigned char Line_Status(unsigned char ID,unsigned char status);



#endif


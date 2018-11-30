//*************************************************************************************************
//  Copyright (c) 	��������Ԫ΢�������޹�˾
//	�ļ�����	:  S_TouchKeyCFG.h
//	����		: 
//	ģ�鹦��	:  ���ؼ������ļ�
// 	�汾		:
// 	���ļ�¼	:
//	ע������	:  �û������ļ����û����޸�
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__

//==========================================================================
//���ذ����������ò��֣��û����޸�
//���ذ����Ĵ�������
//==========================================================================
//TKCFG1:
// bit[4] =    PRS             ��Ƶ����
// bit[3:0] =  Not define      δ����
//TKCFG2:
// bit[5:4] =  CMPFLTS         �˲�����
// bit[3:0] =  CTIME           ��ŵ�Ƶ��
//TKCFG3:
// bit[6:4] =  SVSS            �����ѹԴ��ѹ
// bit[3:0] =  VREF            �ο���ѹ
//-----------------------------------------------------------------------
#define			SOCAPI_SET_TKCFG1						    0x00 	//Ĭ�����ã�0x00//SFR:TKCFG1���ã�bit7-bit4(PRS);bit3-bit0(NULL)					
#define			SOCAPI_SET_TKCFG2							0x15    //Ĭ�����ã�0x15//SFR:TKCFG2����: bit7-bit4(CMPFLTS);bit3-bit0(CTIME)		
#define			SOCAPI_SET_TKCFG3							0x36    //Ĭ�����ã�0x36//SFR:TKCFG3����: bit7-bit4(SVSS);bit3-bit0(VREF)	
//---------------------------------------------------------------------------

//���ذ����ĸ�����ͨ�����ã�ÿbit����һ��ͨ��
#define		    SOCAPI_SET_TOUCHKEY_TOTAL					2		//�û�ʵ��ʹ�õİ���ͨ��������,���û�ʹ��TK8~TK15��8����,ֻ��8�� 
#define			SOCAPI_SET_TOUCHKEY_CHANNEL					0x0042  //bit15~bit0��ӦTK15~TK0;  ��ӦΪ��1��ΪTK����Ӧλ��0��ΪIO

//���ذ����ĳ�����ȷ�ϴ���
#define			SOCAPI_SET_TOUCHKEY_CONFIRM_CNT				8 	 	//ȷ�ϰ�������(4~30֮�䣬������Խ�󣬷�ӦԽ��)

//���ذ���������ֵ
#define			SOCAPI_SET_NOISE_THRESHOLD					30		//����������ֵ��Χ:16~40

//ÿһ·ͨ�����ذ�������ָ��ֵ����Χ0~65535����Ϊ��Ч��ֵ=��baseline-Finger��*0.6����ֵԽ��������Խ�ͣ���֮��Ȼ��
//baselineΪ��ָû���µ�rawdataֵ,FingerΪ��ָ���º��rawdataֵ
//����0.6��������������Ϊÿ���˵���ָ�Ӵ������һ��,�û�Ҳ�ɸ��ݴ���Ч���ʵ������ӻ��С��
//�û�ֻ��Ҫ����ʵ��ʹ�õ�ͨ����ָ��ֵ������û�õ���ͨ�����������; 

#define			SOCAPI_KEY0_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY1_FINGER_THRESHOLD				100//300//100
#define			SOCAPI_KEY2_FINGER_THRESHOLD				300
#define			SOCAPI_KEY3_FINGER_THRESHOLD				350

#define			SOCAPI_KEY4_FINGER_THRESHOLD				300 
#define			SOCAPI_KEY5_FINGER_THRESHOLD				300
#define			SOCAPI_KEY6_FINGER_THRESHOLD			    100              //350	//300 
#define			SOCAPI_KEY7_FINGER_THRESHOLD				1000

#define			SOCAPI_KEY8_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY9_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY10_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY11_FINGER_THRESHOLD				1000

#define			SOCAPI_KEY12_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY13_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY14_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY15_FINGER_THRESHOLD				1000


//=0 ��ʾ����, = 1 ��ʾ˫�����߻���	 2014-11-28
#define 		SOCAPI_SET_SLIDE_KEY_FUNCTION				0		//0:��ʾ����, 1:��ʾ���˫�����߻���

//---------------------------------------------------------------------------
//-------------------���²����������û��޸�----------------------------------
#define 		SOCAPI_SET_UPDATE_SPEED						120		//�������»��߸����ٶ�,���÷�Χ0~255.Ĭ��120
#define			SOCAPI_SET_KEY_CONTI_TIME					5000	//������Ч������ʱ��,���÷�Χ0~5000��Ĭ��1000�����ʱ��= 1000*��λÿ��ɨ��ʱ�䣨��10ms��=10S
#define			SOCAPI_SET_SYNC_UPDATE						450		//��̬���»��ߵ�ʱ��,���÷�Χ0~1000��Ĭ��450
#define			SOCAPI_INIT_AUTO_UPDATE_TIME				48		//��ʼ���Զ�У׼���������÷�Χ0--100��Ĭ��48
#define			SOCAPI_AUTO_UPDATE_TIME						2		//���ǿ�ƻ��߸�λ�ٶȣ����÷�Χ2-5��Ĭ��2	�縴λʱ��=2*8*ÿ��ɨ��ʱ�䣨10ms��=80ms
#define			SOCAPI_MAX_KEY_NUM_INVALID					3		//ǿ�Ƹ��»��߰������Ƹ�����Ĭ��3
#define			SOCAPI_INHIBITION_ZONE					    7		//�������䣬���÷�Χ5-10��Ĭ��7,����7*10��%=70% ����ˮʱ�Ӵ�ò���
#define  		SOCAPI_FINGER_MAX_VALUE						2000	//����������������Ĭ��2000
#define			SOCAPI_SET_CS_FUNCTION						1		//0:��ʾ������CS����,1: ��ʾ����CS����,Ĭ��0
#define			SOCAPI_MAX_KEY_MUTIPLE						300		//������ż������ﵽ����ֵ���»��ߣ�Ĭ��300*��λÿ��ɨ��ʱ�䣨��10ms��=1.5S

#endif //__S_TOUCHKEYCFG_H__
//===========================================================================


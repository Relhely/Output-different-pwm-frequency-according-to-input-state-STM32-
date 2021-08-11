#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

int main(void)
{

  int qwe;
  int asd;
  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;



  delay_init();        //��ʱ������ʼ��
  //LED_Init();       //��ʼ����LED���ӵ�Ӳ���ӿ�
	input_test();
	
  TIM1_PWM_Init(719, 0); //����Ƶ��PWMƵ��=72000/(899+1)=80Khz
  TIM_SetCompare1(TIM1, 360);
	
  while (1)
  {
    if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)) {
      A = 2;
    }
    else {
      A = 0;
    }
    if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)) {
      B = 1;
    }
    else {
      B = 0;
    }

    C = A + B;

    if (D == C) {
      continue;
    }


    switch (C) {
      case 0: //100k Hz
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        delay_ms(5);
        TIM1->ARR = 719; 
        TIM1->CCR1 = 360; 
        TIM_ARRPreloadConfig(TIM1, ENABLE);
        TIM_Cmd(TIM1, ENABLE);
        delay_ms(500);
        D = 0;
        break;
			
      case 1: //200k Hz
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        delay_ms(5);
        TIM1->ARR = 359; //������10000�ڹ������¼���
        TIM1->CCR1 = 180; //����ռ�ձ�Ϊ50%
        TIM_ARRPreloadConfig(TIM1, ENABLE);
        TIM_Cmd(TIM1, ENABLE);
        delay_ms(500);
        D = 1;
        break;
			
      case 2: //400k Hz
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        delay_ms(5);
        TIM1->ARR = 179; //������10000�ڹ������¼���
        TIM1->CCR1 = 90; //����ռ�ձ�Ϊ50%
        TIM_ARRPreloadConfig(TIM1, ENABLE);
        TIM_Cmd(TIM1, ENABLE);
        delay_ms(500);
        D = 2;
        break;
			
      case 3: //200k Hz
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        TIM_Cmd(TIM1, DISABLE);
        TIM_ARRPreloadConfig(TIM1, DISABLE);
        delay_ms(5);
        TIM1->ARR = 89; //������10000�ڹ������¼���
        TIM1->CCR1 = 45; //����ռ�ձ�Ϊ50%
        TIM_ARRPreloadConfig(TIM1, ENABLE);
        TIM_Cmd(TIM1, ENABLE);
        delay_ms(500);
        D = 3;
        break;
    }
  }
}


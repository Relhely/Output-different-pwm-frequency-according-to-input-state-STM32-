#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

int main(void)
{

  int qwe;
  int asd;
  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;



  delay_init();        //延时函数初始化
  //LED_Init();       //初始化与LED连接的硬件接口
	input_test();
	
  TIM1_PWM_Init(719, 0); //不分频。PWM频率=72000/(899+1)=80Khz
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
        TIM1->ARR = 359; //计数到10000在归零重新计数
        TIM1->CCR1 = 180; //保持占空比为50%
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
        TIM1->ARR = 179; //计数到10000在归零重新计数
        TIM1->CCR1 = 90; //保持占空比为50%
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
        TIM1->ARR = 89; //计数到10000在归零重新计数
        TIM1->CCR1 = 45; //保持占空比为50%
        TIM_ARRPreloadConfig(TIM1, ENABLE);
        TIM_Cmd(TIM1, ENABLE);
        delay_ms(500);
        D = 3;
        break;
    }
  }
}


#ifndef __PWM_H
#define __PWM_H
#include "sys.h"



void TIM1_PWM_Init(u16 arr,u16 psc);
void pwm_set(u16 arr);

#endif

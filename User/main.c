/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.6.0
  * @date    20-September-2021
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2011 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#include <stdio.h>
#include "Delay.h"
#include "KEY.h"
#include "LED.h"

int main (void)
{
	Key_Init(); //初始化按键
	LED_Init();

	while(1)
	{
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		Delay_ms(500);
		
		if(Key_GetNum() == 1)
		{
			LED_Turn();
		}
	}
}


#include "stm32f10x.h"


void LED_Init(void)
{
	//	RCC里面的APB2外设时钟控制函数
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
//	配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽输出
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_11;  //多引脚初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
//	GPIO_SetBits(GPIOC,GPIO_Pin_13);  //设置高电平
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);//设置低电平
//	GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);  //设置Bit_RESET：低电平  Bit_SET：高电平
}

void LED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) == 0)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
	}
	else
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	}
}









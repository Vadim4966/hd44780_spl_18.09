#include "lcd_hd44780_spl.h"


void hd44780_init()
{
	RCC_APB2PeriphClockCmd(e_rcc, ENABLE);
	RCC_APB2PeriphClockCmd(rs_rcc, ENABLE);
	RCC_APB2PeriphClockCmd(dat_rcc, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.GPIO_Pin = e_pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(e_port, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = rs_pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(rs_port, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = dat_1st_pin|dat_1st_pin << 1|dat_1st_pin << 2|dat_1st_pin << 3;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(dat_port, &GPIO_InitStruct);
	
	
	
}

void hd44780_WriteNibble(unsigned char dat)
{
	GPIO_SetBits(dat_port,  (dat & 0x0F) << dat_1st_pin);
	
}



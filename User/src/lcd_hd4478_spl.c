#include "lcd_hd44780_spl.h"


const unsigned char hd44780_addLUT[4] = {0x80, 0xC0, 0x94, 0xD4};
unsigned char hd44780_addr, hd44780_line;


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
	
	e_res();
	rs_res();
	hd44780_delay(5000);
	hd44780_WriteNibble(0x33);
	hd44780_WriteNibble(0x33);
	hd44780_WriteNibble(0x33);
	hd44780_WriteNibble(0x22);
	hd44780_WriteByte(0x28);
	hd44780_WriteByte(0x01);
	hd44780_WriteByte(0x10);
	hd44780_WriteByte(0x06);
	hd44780_WriteByte(0x0C);
	for(char i=0x40; i<0x5F; i++)
	{
		hd44780_delay(1000);
		rs_res();;
		hd44780_WriteByte(i);
		hd44780_delay(1000);
		hd44780_ShowChar(0);
	}
	rs_set();;
	hd44780_ClearLCD();
	
}

void hd44780_WriteNibble(unsigned char dat)
{
	GPIO_SetBits(dat_port,  (dat & 0x0F) << dat_1st_pin);
	hd44780_delay(200);
	e_set();
	hd44780_delay(100);
	e_res();
	GPIO_ResetBits(dat_port, 0x0F << dat_1st_pin);
}

void hd44780_WriteByte(unsigned char dat)
{
	hd44780_WriteNibble(dat >> 4);
	hd44780_WriteNibble(dat & 0x0F);
}

void hd44780_GoToLine(char LineNum)
{
	rs_res();
	hd44780_addr = hd44780_addLUT[LineNum-1];
	hd44780_WriteByte(hd44780_addr);
	rs_set();
	hd44780_addr = 0;
	hd44780_line = LineNum;
}

void hd44780_ClearLCD(void)
{
	rs_res();
	hd44780_WriteByte(0x01);
	hd44780_delay(1000);
	rs_set();
	hd44780_GoToLine(1);
}

void hd44780_ShowChar(unsigned char c)
{
	rs_set();
	hd44780_WriteByte(c);
	hd44780_addr++;
	switch (hd44780_addr)
	{
		case 20: hd44780_GoToLine(2); break;
		case 40: hd44780_GoToLine(3); break;
		case 60: hd44780_GoToLine(4); break;
		case 80: hd44780_GoToLine(1); break;
	}
}









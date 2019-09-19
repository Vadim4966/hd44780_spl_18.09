#ifndef LCD_HD44780_SPL_H
#define LCD_HD44780_SPL_H

#include "stm32f10x.h"

//User should define all involved pins
#define e_port			GPIOB
#define e_pin				GPIO_Pin_10
#define rs_port			GPIOB
#define rs_pin			GPIO_Pin_11
#define dat_port		GPIOA
//While defining data pins, user can choose two cases
//First one: 	- Take more resourses 
//						- Give possibility to choose pins not only in a row
//Second one: - Take less resourses
//						- User need to choose 4 pins in a row
/*
#define dat4_pin		GPIO_Pin_4
#define dat5_pin		GPIO_Pin_5
#define dat6_pin		GPIO_Pin_6
#define dat7_pin		GPIO_Pin_7
*/
//////////////
#define dat_1st_pin GPIO_Pin_4


#define e_rcc				RCC_APB2Periph_GPIOB
#define rs_rcc			RCC_APB2Periph_GPIOB
#define dat_rcc			RCC_APB2Periph_GPIOA


//Defines for internal library needs
#define e_set() GPIO_SetBits(e_port, e_pin);
#define e_res() GPIO_ResetBits(e_port, e_pin);
#define rs_set() GPIO_SetBits(rs_port, rs_pin);
#define rs_res() GPIO_ResetBits(rs_port, rs_pin);






void hd44780_WriteNibble(unsigned char);
void hd44780_WriteByte(unsigned char);
void hd44780_init();


void hd44780_ClearLCD(void);
void hd44780_GoToLine(char);
void hd44780_ShowChar(unsigned char);































#endif /*LCD_HD44780_SPL_H*/
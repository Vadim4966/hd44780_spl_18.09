#ifndef LCD_HD44780_SPL_H
#define LCD_HD44780_SPL_H

#include "stm32f10x.h"

//User should define all involved pins
#define e_port			GPIOB
#define e_pin				GPIO_Pin_10
#define rs_port			GPIOB
#define rs_pin			GPIO_Pin_11
#define dat_port		GPIOA
#define dat4_pin		GPIO_Pin_4
#define dat5_pin		GPIO_Pin_5
#define dat6_pin		GPIO_Pin_6
#define dat7_pin		GPIO_Pin_7

#define e_rcc				RCC_APB2Periph_GPIOB
#define rs_rcc			RCC_APB2Periph_GPIOB
#define dat_rcc			RCC_APB2Periph_GPIOA


//Defines for internal library needs
#define e_set() GPIO_SetBits(e_port, e_pin);
#define e_res() GPIO_ResetBits(e_port, e_pin);
#define rs_set() GPIO_SetBits(rs_port, rs_pin);
#define rs_res() GPIO_ResetBits(rs_port, rs_pin);


#define



































#endif /*LCD_HD44780_SPL_H*/
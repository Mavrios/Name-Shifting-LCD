/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/04- CLCD/CLCD_interface.h"

#define LCD_COLS 			16
#define ZERO				0
#define EN_String_Length	11
#define AR_String_Length	8

void voidDisplayArName(void);

int main(void) {
	CLCD_voidInit();
	CLCD_voidSendExtraChar();
	CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
	u8 LOC_u8String[] = "Ahmed Kishk";
	u8 LOC_u8Iterator1 = 0;
	s8 LOC_u8Iterator2 = 0;
	u8 LOC_u8Counter = 0;
	u8 LOC_u8flag = 0;
	while (1) {
		LOC_u8flag = 0;
		for (LOC_u8Iterator1 = 1, LOC_u8Iterator2 = 16;
				LOC_u8Iterator1 <= LCD_COLS && LOC_u8Iterator2 >= ZERO;
				LOC_u8Iterator1++, LOC_u8Iterator2--) {

			CLCD_voidSetPosition(CLCD_ROW_1, LOC_u8Iterator1);
			CLCD_voidMoveDirection(CLCD_LEFT_RIGHT);
			CLCD_voidSendString(LOC_u8String);
			CLCD_voidSetPosition(CLCD_ROW_2, LOC_u8Iterator2);
			CLCD_voidMoveDirection(CLCD_RIGHT_LEFT);
			voidDisplayArName();
			_delay_ms(800);
			CLCD_voidSetPosition(CLCD_ROW_1, LOC_u8Iterator1);
			CLCD_voidSendString((u8 *) " ");
			CLCD_voidSetPosition(CLCD_ROW_2, LOC_u8Iterator2);
			CLCD_voidSendString((u8 *) " ");

			if (LOC_u8Iterator1 > LCD_COLS - EN_String_Length) {

				CLCD_voidMoveDirection(CLCD_LEFT_RIGHT);
				CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
				for (LOC_u8Counter = LCD_COLS - LOC_u8Iterator1;
						LOC_u8Counter < EN_String_Length; LOC_u8Counter++) {
					CLCD_voidSendData(LOC_u8String[LOC_u8Counter]);

				}

				CLCD_voidMoveDirection(CLCD_RIGHT_LEFT);
				CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_16);
				for (LOC_u8Counter = LCD_COLS - LOC_u8Iterator1;
						LOC_u8Counter < AR_String_Length; LOC_u8Counter++) {

					CLCD_voidSendData(LOC_u8Counter);

				}

			}
		}
	}
}

void voidDisplayArName(void) {
	for (u8 LOC_u8Iterator = 0; LOC_u8Iterator < AR_String_Length;
			LOC_u8Iterator++) {
		CLCD_voidSendData(LOC_u8Iterator);
	}

}

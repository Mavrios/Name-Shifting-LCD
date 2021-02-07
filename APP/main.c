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

/*	Function Prototype	*/
void voidDisplayArName(void);

int main(void) {
	CLCD_voidInit();																//INITIALIZE LCD
	CLCD_voidSendExtraChar();														//STORING SPECIAL CHARACTER (ARABIC) TO CGRAM
	CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);									//INITIALIZE CURSOR POSTION
	u8 LOC_u8String[] = "Ahmed Kishk";												//DEFINE MY NAME IN ENGLISH
	u8 LOC_u8Iterator1 = 0;															//DEFINE ITERATOR
	s8 LOC_u8Iterator2 = 0;															//DEFINE ITERATOR
	u8 LOC_u8Counter = 0;															//DEFINE ITERATOR
	while (1) {
		for (LOC_u8Iterator1 = CLCD_COL_1, LOC_u8Iterator2 = CLCD_COL_16;
				LOC_u8Iterator1 <= LCD_COLS && LOC_u8Iterator2 >= ZERO;
				LOC_u8Iterator1++, LOC_u8Iterator2--) {

			CLCD_voidSetPosition(CLCD_ROW_1, LOC_u8Iterator1);						//SET CURSOR POSITION
			CLCD_voidMoveDirection(CLCD_LEFT_RIGHT);								//SET CURSOR MOVING DIRECTION
			CLCD_voidSendString(LOC_u8String);										//PRINT MY NAME IN THE LCD
			CLCD_voidSetPosition(CLCD_ROW_2, LOC_u8Iterator2);						//SET CURSOR POSITION
			CLCD_voidMoveDirection(CLCD_RIGHT_LEFT);								//SET CURSOR MOVING DIRECTION
			voidDisplayArName();													//PRINT MY ARABIC NAME
			_delay_ms(800);															//DELAY
			CLCD_voidSetPosition(CLCD_ROW_1, LOC_u8Iterator1);						//SET CURSOR POSITION
			CLCD_voidSendString((u8 *) " ");										//CLEAR THE FIRST CHARACTER IN MY ENGLISH NAME TO SHIFT
			CLCD_voidSetPosition(CLCD_ROW_2, LOC_u8Iterator2);						//SET CURSOR POSITION
			CLCD_voidSendString((u8 *) " ");										//CLEAR THE FIRST CHARACTER IN MY ARABIC NAME TO SHIFT

			if (LOC_u8Iterator1 > LCD_COLS - EN_String_Length) {					//CHECK IF THE LAST CHARACTER ON MY NAME ARRIVED TO THE LAST COL
				CLCD_voidMoveDirection(CLCD_LEFT_RIGHT);							//SET CURSOR MOVING DIRECTION LEFT TO RIGHT
				CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);						//SET CURSOR POSITION TO THE FIRST COL IN THE FIRST ROW
				for (LOC_u8Counter = LCD_COLS - LOC_u8Iterator1;					//LOOP TO PRINT THE LAST CHARACTER FIRST ON MY NAME
						LOC_u8Counter < EN_String_Length; LOC_u8Counter++) {
					CLCD_voidSendData(LOC_u8String[LOC_u8Counter]);					//PRINT CHARACTERS IN THE LCD

				}

				CLCD_voidMoveDirection(CLCD_RIGHT_LEFT);							//SET CURSOR MOVING DIRECTION RIGHT TO LEFT
				CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_16);						//SET CURSOR POSITION TO THE LAST COL IN SECOND ROW
				for (LOC_u8Counter = LCD_COLS - LOC_u8Iterator1;
						LOC_u8Counter < AR_String_Length; LOC_u8Counter++) {		//LOOP TO PRINT THE LAST CHARACTER FIRST ON MY NAME

					CLCD_voidSendData(LOC_u8Counter);								//PRINT CHARACTER IN LCD

				}

			}
		}
	}
}



/*	FUNCTION PROTOTYPE	*/
void voidDisplayArName(void) {
	for (u8 LOC_u8Iterator = 0; LOC_u8Iterator < AR_String_Length;
			LOC_u8Iterator++) {
		CLCD_voidSendData(LOC_u8Iterator);
	}

}

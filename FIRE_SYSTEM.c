
#include "StdTypes.h"
#include "LCD_int.h"
#include "DIO_int.h"
#include "Motor_int.h"

#include "FIRE_SYSTEM.h"



void NormalState_Runnable(u16 temp){
	    MOTOR_Stop(M1);
		DIO_WritePin(Buzzer,LOW); //Buzzer OFF
		DIO_WritePin(Green,HIGH);
		DIO_WritePin(Yellow,LOW);
		DIO_WritePin(RED,LOW);
		LCD_SetCursor(line_1,5);
		LCD_WriteString((u8*)"Normal");
		LCD_SetCursor(line_2,0);
		LCD_WriteString((u8*)"Temp=");
		LCD_WriteNumber(temp);
		LCD_WriteString((u8*)"       ");
}
void HeatState_Runnable(u16 temp ,u16 smoke){
	        MOTOR_Stop(M1);
			DIO_WritePin(Buzzer,LOW); //Buzzer OFF
			DIO_WritePin(Green,LOW);
			DIO_WritePin(Yellow,HIGH);
			DIO_WritePin(RED,LOW);
			LCD_SetCursor(line_1,6);
			LCD_WriteString((u8*)"HEAT");
			LCD_SetCursor(line_2,0);
			LCD_WriteString((u8*)"T=");
			LCD_WriteNumber(temp);
			LCD_WriteString((u8*)" ");
			LCD_SetCursor(line_2,7);
			LCD_WriteString((u8*)"Smoke=");
			LCD_WriteNumber(smoke);
			LCD_WriteString((u8*)"  ");
}
void FIREState_Runnable(){
		    MOTOR_CW(M1);
			DIO_WritePin(Buzzer,HIGH); //Buzzer ON
			DIO_WritePin(Green,LOW);
			DIO_WritePin(Yellow,LOW);
			DIO_WritePin(RED,HIGH);
			LCD_SetCursor(line_1,5);
			LCD_WriteString((u8*)"Fire!!");
			LCD_SetCursor(line_2,0);
			LCD_WriteString((u8*)"PassWord=");
}
	

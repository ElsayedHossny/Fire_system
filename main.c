#include "MemMap.h"
#include "StdTypes.h"

#include "MCAL/DIO_int.h"
#include "MCAL/DIO_private.h"
#include "MCAL/ADC_int.h"

#include "Motor_int.h"
#include "LCD_int.h"
#include "Keypad_int.h"
#include "Sensors_int.h"

#include "TempFilter.h"

#define  F_CPU 16000000
#include "util/delay.h"

#include "App/Fire_System/FIRE_SYSTEM.h"

int main(void)
{

	DIO_Init();
	LCD_Init();
 	KEYPAD_Init();
 	ACD_Init();
    FILTER_Init();
	

u16 Temp =0 ,Smoke=0;
u8 ClearLCDNormal=0 , ClearLCDHeat=0 ,  ClearLCDFire=0 ;
u8 NoEnterHeat=0,NoEnterNormal=0 ,NoEnterFire=0;
u8 k=No_KEY, pass=0 ,password=123,passwordCheck=0;


while(1)
{
	     k = KEYPAD_GetKey();
		Temp=LM35_GetRead();
		Smoke=POT_GetRead();
		
		// Normal_State
		if(Temp<=450 && NoEnterNormal==0 &&passwordCheck==0){
			if(ClearLCDNormal==0){
				LCD_Clear();
				ClearLCDNormal=1;
			}
			NormalState_Runnable(Temp);
			NoEnterFire=0;
			ClearLCDHeat=0;
			ClearLCDFire=0;
			NoEnterHeat=0;
		}
		
		// Fire_State
		else if(Smoke>=60 && Temp>=500 &&  NoEnterFire==0 &&passwordCheck==0){
			NoEnterHeat=1; //no enter Heat State
			NoEnterNormal=1; //no enter Normal State
			if(ClearLCDFire==0){
				LCD_Clear();
				ClearLCDFire=1;
			    FIREState_Runnable();
			}
			passwordCheck=1;
			  
		}
		
		// Heat_State
		else if(Temp>=500 && NoEnterHeat==0 && passwordCheck==0){
			if(ClearLCDHeat==0){
				LCD_Clear();
				ClearLCDHeat=1;
			}			
			HeatState_Runnable(Temp,Smoke);
			NoEnterNormal=0;
			ClearLCDNormal=0;
			ClearLCDFire=0;
			NoEnterFire=0;	
		}
		else{
			// No_Action
		}
		// Password_Check
		if(passwordCheck==1){
			  if (k>='0' && k<='9'){
				  LCD_WriteChar(k);
				  pass= pass*10 +k - '0';
			  }
			  else if(k=='='){
				  if(pass==password){
					  NoEnterFire=1;
					  NoEnterHeat=0; //no enter Heat State
					  NoEnterNormal=0; //no enter Normal State
					  ClearLCDHeat=0;
					  ClearLCDNormal=0;
					  Smoke=0;
					  Temp=0;
					  passwordCheck=0;
					  k=No_KEY;
					  }else{
					  passwordCheck=1;	  
					  pass=0;
					  NoEnterFire=0;
					  ClearLCDFire=0;
					  LCD_Clear();
					  LCD_SetCursor(line_1,5);
					  LCD_WriteString((u8*)"Fire!!");
					  LCD_SetCursor(line_2,0);
					  LCD_WriteString((u8*)"PassWord=");
				  }
			  }else{
				  pass=pass;
			  }
			  
		}else{
			// No_Action
		}
		
		}
}



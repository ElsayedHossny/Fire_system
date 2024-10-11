
#ifndef FIRE_SYSTEM_H_
#define FIRE_SYSTEM_H_

#define Buzzer PINC5

typedef enum{
	Green=PINC1,
	Yellow=PINC2,
	RED=PINC0
}LED_NAME;


void NormalState_Runnable(u16 temp);
void HeatState_Runnable(u16 temp ,u16 smoke);
void FIREState_Runnable();


#endif /* FIRE_SYSTEM_H_ */
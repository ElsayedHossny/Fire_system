# Fire_system
Fire_system By Use(MCU->Atmega32) , Embedded C
my project content of 3-State : 
1) NORMAL_STATE : iF(Temp<=450)
Sensor_Temp : ON
LED_Green : ON
Sensor_Smoke : OFF
MOTOR : OFF
2) HEAT_STATE : iF(Temp>=500 && Smoke<=55%)
Sensor_Temp : ON
Sensor_Smoke : ON
LED_Yellow : ON
MOTOR : OFF 
3) FIRE_STATE :  iF(Temp>=500 && Smoke>=60%)
Sensor_Temp : ON
Sensor_Smoke : ON
LED_Red : ON
MOTOR : ON
Buzzer :On
#IF the system In fire Enter passWord to return another State

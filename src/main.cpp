#include <Arduino.h>

#define LED1_ON digitalWrite(led1, HIGH)
#define LED2_ON digitalWrite(led2, HIGH)
#define LED3_ON digitalWrite(led3, HIGH)
#define LED4_ON digitalWrite(led4, HIGH)
#define LED5_ON digitalWrite(led5, HIGH)

#define LED1_OFF digitalWrite(led1, LOW)
#define LED2_OFF digitalWrite(led2, LOW)
#define LED3_OFF digitalWrite(led3, LOW)
#define LED4_OFF digitalWrite(led4, LOW)
#define LED5_OFF digitalWrite(led5, LOW)

#define M1  100
#define M2  200
#define M3  300
#define M4  400

int trigPin = 11; //trigger
int echoPin = 12; //echo

//led pins

int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;

int cm = 0;
int duration = 0;
int counter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  LED1_OFF;
  LED2_OFF;
  LED3_OFF;
  LED4_OFF;

}

void loop() {
  //the sensor is triggered by HIGH pulse of 10 or more microseconds.
//give a short LOW pulse before to ensure clean HIGH pulse.
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

//Read the signal from the sensor: a HIGH pulse whose
//duration is the time (in microseconds) from the sending
//of the ping to the reception of its echo off an object.

duration = pulseIn(echoPin, HIGH); // counts time to go LOW on echoPin

//convert the time into a distance

cm = (duration/2) / 29.1; //Divide by 29.1 or multiply by 0.0343-> 343 meter per second
Serial.println(cm);


  if (cm <= M1 && cm < M2){
    LED1_ON;
    LED2_ON;
    LED3_ON;
    LED4_ON;
    counter = 0;
  }

  else if (cm >= M2 && cm < M3){
    LED1_ON;
    LED2_ON;
    LED3_ON;
    LED4_OFF;
    counter = 0;
  }

  else if (cm >= M3 && cm < M4){				//kun input on true 2 ylöspäin
    LED1_ON;
    LED2_ON;			//kun input = 2 menee nämäkin päälle ja pois
    LED3_OFF;
    LED4_OFF;
    counter = 0;
  }

  else if (cm <= M4 && cm > M1)	{				//kun input = 1 menee nämä päälle ja pois
			LED1_ON;
			LED2_OFF;
			LED3_OFF;
			LED4_OFF;
      counter = 0;
    }

else if (counter == 10){
      	LED1_OFF;
				LED2_OFF;
				LED3_OFF;
				LED4_OFF;
      }
      counter++;
      delay(1000);
}

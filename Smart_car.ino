//CRATUS MK7
//SMART CAR
//BY PRADEEP RAJ(M.P.R)
//MAY 15 2020
//          ------THIS CODE IS OPEN SOURCE FOR OUR SUBSCRIBERS------
//                         ------ THE FAUCETER ------

#include<AFMotor.h>
#include<NewPing.h>

#define left A1
#define right A0
#define trig A2
#define echo A3
#define MAX_DISTANCE 100

NewPing sonar(trig,echo,MAX_DISTANCE);

AF_DCMotor motor1(1,MOTOR12_1KHZ);
AF_DCMotor motor2(2,MOTOR12_1KHZ);
AF_DCMotor motor3(3,MOTOR34_1KHZ);
AF_DCMotor motor4(4,MOTOR34_1KHZ);

void setup() {
  // put your setup code here, to run once:
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = sonar.ping_cm();

  Serial.print("Distaance");
  Serial.println(distance);

  if (distance >13) {
    motor1.setSpeed(200);
    motor1.run(FORWARD);
    motor2.setSpeed(200);
    motor2.run(FORWARD);
    motor3.setSpeed(200);
    motor3.run(FORWARD);
    motor4.setSpeed(200);
    motor4.run(FORWARD);
  }
  else if (distance <=14 && distance >0) {
    Stop();
    delay(100);
    if (digitalRead(right)==0 && digitalRead(left)==0) {
      turnright();
      delay(400);
    }

    else if (!digitalRead(right)==0 && digitalRead(left)==0) {
      turnleft();
      delay(400);
    }

    else if (digitalRead(right)==0 && !digitalRead(left)==0)  {
      turnright();
      delay(400);
    }

    else if (!digitalRead(right)==0 && !digitalRead(left)==0)  {
      turnaround();
      delay(1600);
    }
  }
   else if (!digitalRead(right)==0 && digitalRead(left)==0) {
     turnleft();
     delay(100);
    }

   else if (digitalRead(right)==0 && !digitalRead(left)==0)  {
     turnright();
     delay(100);
    }
}

void Stop() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void turnright() {
   motor1.run(FORWARD);
   motor1.setSpeed(200);
   motor2.run(BACKWARD);
   motor2.setSpeed(200);
   motor3.run(BACKWARD);
   motor3.setSpeed(200);
   motor4.run(FORWARD);
   motor4.setSpeed(200);
   
}

void turnleft() {
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
}

void turnaround() {
   motor1.run(FORWARD);
   motor1.setSpeed(200);
   motor2.run(BACKWARD);
   motor2.setSpeed(200);
   motor3.run(BACKWARD);
   motor3.setSpeed(200);
   motor4.run(FORWARD);
   motor4.setSpeed(200);
}





//---------------------------------------------------------------------------------THE FAUCETER----------------------------------------------------------------------------------------

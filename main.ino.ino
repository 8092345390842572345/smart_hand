#include<Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;

const int servoPort0 = 5;
const int servoPort1 = 7;
const int servoPort2 = 6;

float deg0 = 90;
float deg1 = 90;
float deg2 = 90;

const int stoptime = 1000;
const float radius = 13;

void statistics()
{
  
  String textDeg0 = String(deg0);
  Serial.println("deg0 = " + textDeg0);
  String textDeg1 = String(deg1);
  Serial.println("deg1 = " + textDeg1);
  String textDeg2 = String(deg2);
  Serial.println("deg2 = " + textDeg2);
  Serial.println(" ");
}

float mathmodel(float x)
{
  if(x >= 0)
  {
    return (sqrt(pow(radius, 2) - pow(x, 2)) - radius);
  }
  else
  {
    return (radius - sqrt(pow(radius, 2) - pow(x, 2)));
  }
}

void setfunc()
{
  servo0.write(deg0);
  servo1.write(deg1);
  servo2.write(deg2);
}

void lineMove()
{
  for (int i = 0; i < 30; i++)
  {
    deg1++;
    deg2 = mathmodel(deg1);
    Serial.println(mathmodel(deg1/20));
    delay(100);
    setfunc();
  }
}

void setup()
{
  Serial.begin(9600);
  
  servo0.attach(servoPort0);
  servo1.attach(servoPort1);
  servo2.attach(servoPort2);
  
  statistics();
  setfunc();
  statistics();
  delay(stoptime);
  lineMove();
}

void loop()
{
  setfunc();
  statistics();
  delay(stoptime);
}

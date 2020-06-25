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

const float pi = 3.14;
float a1;
float b1;
float a2;
float b2;

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
    return (sqrt(pow(radius, 2) + pow(x, 2)) - radius);
  }
  else
  {
    return (radius - sqrt(pow(radius, 2) - pow(x, 2)));
  }
}

float backMathmodel(float x)
{
  if(x >= 0)
  {
    return (sqrt(radius * 2 * x - pow(x, 2)));
  }
  else
  {
    return (-sqrt(-pow(x, 2) - radius * 2 * x));
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
  for (int i = 0; i < 80; i++)
  {
    deg1 = deg1 - 1;
    a1 = ((2 * pi * radius * deg1)/360);
    Serial.println(a1);
    b1 = mathmodel(a1);
    Serial.println(b1);
    b2 = 2 * radius - b1;
    Serial.println(b2);
    a2 = backMathmodel(b2);
    Serial.println(a2);
    deg2 = (a2 * 360) / (2 * pi * radius);
    statistics();
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
  //statistics();
  delay(stoptime);
}

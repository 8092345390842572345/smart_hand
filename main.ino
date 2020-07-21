#include<Servo.h>
#include<Math.h>
//#include<D:\files\projects\smartHand\main\main.ino>

Servo servo0;
Servo servo1;
Servo servo2;
const int servoPin0 = 5;
const int servoPin1 = 7;
const int servoPin2 = 6;

const float pi = 3.1415;
const float len1 = 13.0;
const float len2 = 13.0;
const float high = 5.0;
const int delayTime = 50;

float deg0 = 0;
float deg1 = 0;
float deg2 = 0;

float alpha;
float y;
float beta;
int q = 0;
//void apoint()
//{

//}

void lineMove()
{
  alpha = (deg1 * pi) / 180;
  y = len1;
  //beta = acos(len1 * pow(sin(alpha), 2) - y * sin(alpha) - cos(alpha) * sqrt(pow(len2, 2) - pow((y - len1 * sin(alpha)), 2)) / len2);
  beta = acos((len1 * pow(sin(alpha), 2) - y * sin(alpha) - cos(alpha) * sqrt(pow(len2, 2) - pow((y - len1 * sin(alpha)), 2))) / len2);
  //beta = acos((13 * pow(sin(alpha), 2) - 13 * sin(alpha) - cos(alpha) * sqrt(169 - pow((13 - 13 * sin(alpha))), 2)) / 13);
  
  
  Serial.print("deg1 = ");
  Serial.println(deg1);
  Serial.print("deg2 = ");
  Serial.println(deg2);
  
  deg1++;
  deg2 = 270 - (beta * 180) / pi;
  if (q) 
  {
    deg2 -= 2;
  }
  if (deg1 > 180)
  {
    q += 1;
  }
}

void setF()
{
  servo0.write(deg0);
  servo1.write(deg1);
  servo2.write(deg2);
}

void setup()
{
  Serial.begin(9600);
  servo0.attach(servoPin0);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  deg0 = 0;
  deg1 = 0;
  deg2 = 0;
  delay(1000);
}

void loop()
{
  delay(delayTime);
  lineMove();
  setF();
} 

#include <MsTimer2.h>
#define ENABLE A5
#define DIRA A3
#define DIRB A4
const int BUTTON_PIN = 2;
const int LED_PIN = 10;
volatile bool flag = LOW;
bool highend = LOW;
int i = 0;
int bounce = 100;
int ct, pt;
void switchON();
const int INTERVAL = 1;
void gtogglery() {
  static unsigned int toggler = 0;
  ++toggler;
  if ( toggler % 5000 == 0) stopModeOne( );
  if ( toggler % 5000 == 0) stopModeTwo( );
}
void setup()
{
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("ok.");
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), switchON, FALLING);
  MsTimer2::set(INTERVAL, gtogglery);
  MsTimer2::start( );
}
void loop()
{

  if (flag == LOW && highend == LOW)//stop
  {
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    Serial.println("stop_mode");
    analogWrite(ENABLE, LOW);
    //    digitalWrite(LED_PIN, HIGH);
    //    for (i = 0; i < 5; i++)
    //    {
    //      delay(1000);
    //    }
    //    digitalWrite(LED_PIN, LOW);
    //    for (i = 0; i < 5; i++)
    //    {
    //      delay(1000);
    //    }

  }
  else if (flag == HIGH && highend == LOW)//high
  {
    analogWrite(ENABLE, 255);
    for (i = 0; i < 5; i++)
    {
      Serial.println("high speed mode");
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
      delay(500);
      highend = HIGH;
    }
  }
  if (highend == HIGH)//low
  {
    Serial.println("low speed mode");
    analogWrite(ENABLE, 128);
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);
    delay(2000);
  }
}
void switchON()
{

  ct = millis();
  if ((ct - pt) > bounce) {
    Serial.println("switchON");
    flag = !flag;
    highend = LOW;
  }
  pt = ct;

}
void stopModeOne( ) {
  static int toggler = 0;
  toggler = 1 - toggler; // toggler 0,  1
  digitalWrite(LED_PIN, HIGH);
  for (i = 0; i < 5; i++)
  {
    delay(1000);
  }
}
void stopModeTwo( ) {
  static int toggler = 1;
  toggler = 1 - toggler;
  digitalWrite(LED_PIN, LOW);
  for (i = 0; i < 5; i++)
  {
    delay(1000);
  }

}

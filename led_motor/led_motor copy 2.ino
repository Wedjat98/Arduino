#define ENABLE 5
#define DIRA 3
#define DIRB 4
const int BUTTON_PIN = 2;
const int LED_PIN = 10;
bool flag = LOW;
volatile bool highend = LOW;
int i = 0;
unsigned long msTime;
void setup()
{
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("ok.");
  msTime = millis();
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), switchON, FALLING);
}

void loop()
{
  if (flag == LOW && highend == LOW) // stop
  {
    Serial.println("stop_mode");
    analogWrite(ENABLE, LOW);
    digitalWrite(LED_PIN, HIGH);
    delay(5000);
    digitalWrite(LED_PIN, LOW);
    delay(5000);
  }
  if (flag)
  { // 割り込み発生
    if ((millis() - msTime) > 50)
    {
      Serial.println("switchON");
      digitalWrite(DIRA, HIGH);
      digitalWrite(DIRB, LOW);

      if (flag == HIGH && highend == LOW) // high
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
      if (highend == HIGH) // low
      {
        Serial.println("low speed mode");
        analogWrite(ENABLE, 128);
        digitalWrite(LED_PIN, HIGH);
        delay(2000);
        digitalWrite(LED_PIN, LOW);
        delay(2000);
      }
      msTime = millis(); // 割り込み時刻更新
    }
    flag = !flag; // 割り込みフラグ
  }
}
void switchON()
{

  flag = !flag;
  highend = LOW;
}
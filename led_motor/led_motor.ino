#define ENABLE 5
#define DIRA 3
#define DIRB 4
const int BUTTON_PIN = 2;
const int LED_PIN = 10;
int i;
static bool volatile flag = LOW;
void setup()
{
    Serial.begin(9600);
    pinMode(ENABLE, OUTPUT);
    pinMode(DIRA, OUTPUT);
    pinMode(DIRB, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void stop_mode()
{
    Serial.println("stop_mode begin!!!");
    digitalWrite(LED_PIN, HIGH);
    delay(5000);
    digitalWrite(LED_PIN, LOW);
    delay(5000);
}
void highspeed_mode()
{
    Serial.println("highspeed_mode begin!!!");
    //    analogWrite(ENABLE, 255);
    //    digitalWrite(DIRA, HIGH);
    //    digitalWrite(DIRB, LOW);
    for (i = 0; i < 10; i++)
    {
        digitalWrite(LED_PIN, HIGH);
        delay(500);
        digitalWrite(LED_PIN, LOW);
        delay(500);
        Serial.println("highspeed_mode loop begin!!!");
    }
}
void lowspeed_mode()
{
    //    analogWrite(ENABLE, 128);
    Serial.println("lowspeed_mode begin!!!");
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    digitalWrite(LED_PIN, LOW);
    delay(2000);
}
void loop()
{
   
    static bool pre = HIGH;
    static bool now = HIGH;
    now = digitalRead(BUTTON_PIN);
    if (flag == LOW)
    {
        stop_mode();
    }
    if (now == HIGH && pre == LOW)
    {
        flag = !flag;
        highspeed_mode();
        lowspeed_mode();
        if (now == HIGH && pre == LOW && flag == HIGH)
        {
            analogWrite(ENABLE, 0);
            Serial.println("all end!!!");
        }
    }
    pre = now;
}

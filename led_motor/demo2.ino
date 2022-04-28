static bool flag = LOW;
static bool highend = LOW;
int i = 0;
void setup()
{
    pinMode(2, INPUT_PULLUP);
    Serial.begin(9600);
    Serial.println("ok.");
    attachInterrupt(digitalPinToInterrupt(2), switchON, FALLING);
}

void loop()
{
    //  ButtonState();
    if (flag == LOW && highend == LOW)
    {
        Serial.println("stop_mode");
        delay(5000);
    }
    else if (flag == HIGH && highend == LOW)
    {
        for (i = 0; i < 10; i++)
        {
            Serial.println("high speed mode");
            delay(500);
            highend = HIGH;
        }
    }
    else if (flag == LOW && highend == HIGH)
    {

        Serial.println("low speed mode");
        delay(2000);
    }
}
void switchON()
{
    flag = !flag;
    highend = LOW;
}
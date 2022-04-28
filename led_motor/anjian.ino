#define BUTTON_PIN 2 //定义按键脚
int count = 1;       //定义初始count值
void setup()
{
    Serial.begin(9600);         //设置波特率
    pinMode(BUTTON_PIN, INPUT); //设置按键为输入模式
}
void loop()
{
    while (!digitalRead(BUTTON_PIN)) //一直检测按键是否按下
    {
    }
    if (digitalRead(BUTTON_PIN) == HIGH) //当按键按下时
    {
        count = count + 1;     //计数加1
        Serial.println(count); //输出结果
        delay(1000);           //延时，隔开两次按键时间
    }
    
}
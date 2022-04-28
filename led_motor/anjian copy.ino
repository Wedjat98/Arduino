#define anjian 2 //定义按键脚
int count = 29;  //定义初始count值

void setup()
{
    Serial.begin(9600);     //设置波特率
    pinMode(anjian, INPUT); //设置按键脚为输入模式
}

void loop()
{
    if (digitalRead(anjian) == HIGH) // 当检测到按键按下时
    {
        delay(2);
        count = count + 1; //计数加1
    }
    Serial.println(count); //打印出count值
    delay(500);            //延时一段时间再次检测
}
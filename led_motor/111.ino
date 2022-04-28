#define button 2 //スイッチが接続されているピン番号（例）
#define led 10   // LEDが接続されているピン番号（例）

int Bcount; //ボタンを押した回数
int Lcount; //ボタンが押されている間のループ回数
int Hcount; //ボタンが離されている間のループ回数

void setup()
{
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    Bcount = 0;
    Lcount = 0;
    Hcount = 0;
}

void loop()
{
    if (digitalRead(button) == HIGH)
    {
        Hcount++;
        Lcount = 0; //ボタンが離されている時
    }
    else
    {
        Lcount++;
        Hcount = 0; //ボタンが押されている時
    }
    if (Hcount > 20)
    { //ボタンが離されて50ms×20回＝1秒を過ぎた時
        switch (Bcount)
        {
        case 2:
            digitalWrite(led, HIGH);
            break; // LED点灯
        case 4:
            digitalWrite(led, LOW);
            break; // LED消灯
        }
        Bcount = 0;  //ボタンが押された回数をクリア
        Hcount = 20; // Hcountの上限
    }
    switch (Lcount)
    {
    case 0:
        break; //ボタンが離されている時は何もしない
    case 1:
        Bcount++;
        break; //ボタンが押された回数をカウント
    default:
        Lcount = 2; // Lcountの上限
    }
    delay(50); //チャタリング防止タイマ(50ms)
}
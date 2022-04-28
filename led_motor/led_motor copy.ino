#define ENABLE 5
#define DIRA 3
#define DIRB 4
const int BUTTON_PIN = 11;  // 按鍵的接腳
const int LED_PIN =  10;   // LED燈的接腳
int buttonState = 0;   // 按鈕的狀態

void setup()
{
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(LED_PIN, OUTPUT);   //設定LED的PIN腳為輸出
  pinMode(BUTTON_PIN, INPUT_PULLUP); //設定按鈕的接腳為輸入，因為我們要讀取它的狀態
}
/****************************************/
void loop()
{
  buttonState = digitalRead(BUTTON_PIN);  //讀取按鍵的狀態
  
  if(buttonState == LOW){          //如果按鍵按了
    digitalWrite(LED_PIN, HIGH);   //LED就亮了
    analogWrite(ENABLE,255); //enable on
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
  }else{                           //如果按鍵是未按下
    digitalWrite(LED_PIN, LOW);    //LED就不亮
    analogWrite(ENABLE,128); //half speed
  }

}
/****************************************/
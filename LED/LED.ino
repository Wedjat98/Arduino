const int BUTTON_PIN = 3;  // 按鍵的接腳
const int LED_PIN =  10;   // LED燈的接腳


void setup() {
  pinMode(LED_PIN, OUTPUT);   //設定LED的PIN腳為輸出
  pinMode(BUTTON_PIN, INPUT_PULLUP); //設定按鈕的接腳為輸入，因為我們要讀取它的狀態
  Serial.begin(9600);
}

void loop() {
  if(!digitalRead(BUTTON_PIN)){          //如果按鍵按了
    Serial.println("HIGH");
    digitalWrite(LED_PIN, HIGH);   //LED就亮了 
  }else{                           //如果按鍵是未按下
    digitalWrite(LED_PIN, LOW);    //LED就不亮
    Serial.println("LOW");
  }
}

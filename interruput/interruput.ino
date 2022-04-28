const byte LED_PIN = 10;
const byte INPUT_PIN = 2;
 
//bool ledState = LOW;
static bool interruptState = LOW;
unsigned long msTime;
 
void setup() {
  // Digital Pin設定
//  pinMode(LED_PIN, OUTPUT);      //s On-Board LED
  pinMode(INPUT_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("ok.");
//  digitalWrite(LED_PIN, ledState);   // LED初期表示はOFF
 
  // 割り込み設定：入力ピン、割り込みハンドラ、割り込み条件はHIGH→LOW
  attachInterrupt(digitalPinToInterrupt(INPUT_PIN), switchON, FALLING);
  msTime = millis();
}
 
void loop() {
 
  if(interruptState==HIGH) {              // 割り込み発生
    if((millis() - msTime) > 50) {  // 50ミリ秒以下の割り込みは無視する
//      ledState = !ledState;         // LEDをトグル動作
//      digitalWrite(LED_PIN, ledState);
      Serial.println("pressed."); 
      msTime = millis();            // 割り込み時刻更新
 
    }
    interruptState = LOW;    // 割り込みフラグOFF
  }
}
void switchON() {
  interruptState = !interruptState;
}

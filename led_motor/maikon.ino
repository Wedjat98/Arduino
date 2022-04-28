const byte led = A0;
const byte motor = 3;
const byte btn = 10;
int a = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}
void btn_hantei() {
  if (digitalRead(btn) == LOW) {
    if (a == 1) {
      a = 2;
      delay(50);
    }
    else if (a == 3) {
      a = 1;
      delay(50);
    }
  }
}

void loop() {
  if (a == 1) {
    digitalWrite(motor, LOW);
    digitalWrite(led, HIGH);
    for (int i = 0; i < 50; i++) {
      delay(100);
      btn_hantei();
      if (a != 1)break;
    }
    digitalWrite(led, LOW);
    for (int i = 0; i < 50; i++) {
      delay(100);
      btn_hantei();
      if (a != 1)break;
    }
  } else if (a == 2) {
    analogWrite(motor, 255);
    for (int i = 0; i < 5; i++) {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);

    }
    a = 3;
  } else if (a == 3) {
    analogWrite(motor, 80);
    digitalWrite(led, HIGH);
    for (int i = 0; i < 20; i++) {
      delay(100);
      btn_hantei();
      if (a != 3)break;
    }
    digitalWrite(led, LOW);
    for (int i = 0; i < 20; i++) {
      delay(100);
      btn_hantei();
      if (a != 3)break;
    }
  }
}

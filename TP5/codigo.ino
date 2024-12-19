#define PIR 2
#define RGB_R 3
#define RGB_A 4
#define RGB_V 5
#define TRIG 8
#define ECHO 7
#define BUZZER 6

#define MSG(a,b); Serial.print(a); Serial.println(b);

void setup() {
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_A, OUTPUT);
  pinMode(RGB_V, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  bool move = digitalRead(PIR);

  digitalWrite(RGB_R, LOW);
  digitalWrite(RGB_A, LOW);
  digitalWrite(RGB_V, LOW);
  digitalWrite(BUZZER, LOW);

  if (move == HIGH) {
    MSG("ALERTA:", "intruso");
    digitalWrite(RGB_A, HIGH);

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10); 
    digitalWrite(TRIG, LOW);

    float tiempo = pulseIn(ECHO, HIGH);
    float distancia = tiempo / 57.6;

    if (distancia < 100.0) {
      digitalWrite(RGB_R, HIGH);
      digitalWrite(BUZZER, HIGH);
      delay(500);
    } else {
      digitalWrite(RGB_R, LOW);
      digitalWrite(BUZZER, HIGH);
      delay(100);
      digitalWrite(BUZZER, LOW);
      delay(100);
    }

  } else {
    digitalWrite(RGB_V, HIGH);
  }

  delay(1000);
}
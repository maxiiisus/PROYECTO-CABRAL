// C++ code
//
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(0, 255);
  delay(1000);
  analogWrite(0, 0);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
  analogWrite(5, 150);
  analogWrite(6, 150);
  delay(1000);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  analogWrite(5, 0);
  analogWrite(6, 0);

}
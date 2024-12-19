#define TRIGGER_PIN 6
#define ECHO_PIN 5

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() 
{
  int distance = obtenerDistancia();
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println("");
  delay(500);
}

int obtenerDistancia() 
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}
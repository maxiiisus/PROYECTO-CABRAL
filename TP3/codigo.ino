#define buttonPin 7 

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(buttonPin) == LOW) {
    delay(50);  

    if (digitalRead(buttonPin) == LOW) {
      Serial.println("Tiene 5 s para configurar el color del led....");

      delay(5000);

      int rojo = map(analogRead(A0), 0, 1023, 0, 255);
      int verde = map(analogRead(A1), 0, 1023, 0, 255);
      int azul = map(analogRead(A2), 0, 1023, 0, 255);
      
      analogWrite(3, rojo);
      analogWrite(6, verde);
      analogWrite(5, azul);

      Serial.print("El led esta usando esta configuracion de colores RGB: (");
      Serial.print(rojo);
      Serial.print("; ");
      Serial.print(verde);
      Serial.print("; ");
      Serial.print(azul);
      Serial.println(")");

      delay(5000);  

      analogWrite(3, 0);
      analogWrite(6, 0);
      analogWrite(5, 0);

      Serial.println("LED apagado. Presiona el boton para cambiar el color nuevamente.");

      while (digitalRead(buttonPin) == LOW) {
        delay(50);  
      }
    }
  }
}
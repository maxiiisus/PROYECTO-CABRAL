#define RED_PIN 6
#define GREEN_PIN 5
#define BLUE_PIN 3

void setup() {
  pinMode(A0, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int pikachu = analogRead(A0);
  
  int raichu = map(pikachu, 0, 1023, 0, 255);
  
  analogWrite(RED_PIN, 0);    
  analogWrite(GREEN_PIN, raichu);  
  analogWrite(BLUE_PIN, raichu);   
  
  delay(500);
  
  analogWrite(RED_PIN, raichu);    
  analogWrite(GREEN_PIN, 0);    
  analogWrite(BLUE_PIN, 0);     
  
  delay(500);
  
  analogWrite(RED_PIN, raichu);    
  analogWrite(GREEN_PIN, raichu);  
  analogWrite(BLUE_PIN, 0);     
  
  delay(500);
}
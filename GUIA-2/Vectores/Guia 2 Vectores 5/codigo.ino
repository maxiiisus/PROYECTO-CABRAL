#define LED1 2 
#define LED2 3  

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  int secuencia1[] = {1, 0, 0, 1, 1, 0, 1, 1};
  int secuencia2[] = {0, 1, 0, 1, 0, 0, 1, 0};
  
  int longitud = sizeof(secuencia1) / sizeof(secuencia1[0]);
  
  for (int i = 0; i < longitud; i++) {
    if (secuencia1[i] == 1) {
      digitalWrite(LED1, HIGH);  
    } else {
      digitalWrite(LED1, LOW);   
    }
    
    if (secuencia2[i] == 1) {
      digitalWrite(LED2, HIGH);  
    } else {
      digitalWrite(LED2, LOW);   
    }
    
    delay(500);  
  }
}
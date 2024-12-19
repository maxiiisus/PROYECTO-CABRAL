const int buttonPin = 2;   
const int potPin = A0;      
const int redPin = 9;       
const int greenPin = 10;    
const int bluePin = 11;     

bool ledState = false;      
bool lastButtonState = HIGH; 
int colorState = 0;         

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
 
  bool buttonState = digitalRead(buttonPin);

  
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  
    delay(50);             
  }

  
  lastButtonState = buttonState;

  
  if (ledState) {
    int potValue = analogRead(potPin);
    
    
    int redValue = 0, greenValue = 0, blueValue = 0;

    if (colorState == 0) { 
      redValue = map(potValue, 0, 1023, 0, 255);
    } else if (colorState == 1) { 
      greenValue = map(potValue, 0, 1023, 0, 255);
    } else if (colorState == 2) { 
      blueValue = map(potValue, 0, 1023, 0, 255);
    }

    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);

    
    if (buttonState == LOW && lastButtonState == HIGH) {
      colorState = (colorState + 1) % 3; 
      delay(50); 
    }
  } else {
  
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}
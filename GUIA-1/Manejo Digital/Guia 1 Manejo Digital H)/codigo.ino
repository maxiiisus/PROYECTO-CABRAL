bool boton = false;
int contar = 0;
int tiempo = 200;

void setup()
{
    pinMode(4, INPUT_PULLUP);
    pinMode(5, OUTPUT); 
    pinMode(6, OUTPUT); 
    pinMode(7, OUTPUT); 
    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(4) == LOW)
    {
        boton = !boton;
        delay(tiempo);
    }

    if (boton == true)
    {
        contar = contar + 1;
        boton = false;
    }

    Serial.print(contar);
    Serial.print(" - resto:");
    Serial.println(contar % 7);

    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    if (contar % 7 == 1)
    {
        digitalWrite(5, HIGH);
    }
    else if (contar % 7 == 2)
    {
        digitalWrite(6, HIGH);
    }
    else if (contar % 7 == 3)
    {
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }
    else if (contar % 7 == 4)
    {
        digitalWrite(5, HIGH);
        digitalWrite(7, HIGH);
    }
    else if (contar % 7 == 5)
    {
        digitalWrite(7, HIGH);
    }
    else if (contar % 7 == 6)
    {
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }
    else
    {
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }

    if (contar == 7)
    {
        contar = 0;
    }

   }

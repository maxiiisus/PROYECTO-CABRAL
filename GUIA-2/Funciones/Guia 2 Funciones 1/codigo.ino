#define NOTE_GS4 415
#define NOTE_F4  349
#define NOTE_AS5 466 
#define NOTE_C5  523
#define NOTE_B4  494
#define NOTE_C4  262
#define NOTE_DS4 311
#define NOTE_D4  294
#define NOTE_CS4 277
#define NOTE_CS5 554
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_E4  330

#define MSG(a,b,c,d,e,f) Serial.print("Nota total: ");Serial.print(a);Serial.print(" Figura: ");Serial.print(b);Serial.print(" Duracion: ");Serial.print(c);Serial.print(" Silencio: ");Serial.print(d);Serial.print(" Tone duracion:");Serial.print(e);Serial.print(" Delay: ");Serial.println(f);

#define length(vec,tipo) sizeof(vec)/sizeof(tipo)

int BPM = 110;
int duracionTotalNota = (60000 * 4) / BPM;

void setup() 
{
    pinMode(6, OUTPUT);
    Serial.begin(9600);
}

void tocarMelodia1() 
{
    int nota1[] = {NOTE_C5, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4};
    int figura1[] = {4, 4, 4, 4, 4};
    tocarMelodia(nota1, figura1, length(nota1, int));
}

void tocarMelodia2() 
{
    int nota2[] = {NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
    int figura2[] = {4, 4, 4, 4};
    tocarMelodia(nota2, figura2, length(nota2, int));
}

void tocarMelodia3() 
{
    int nota3[] = {NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4};
    int figura3[] = {8, 8, 8, 8};
    tocarMelodia(nota3, figura3, length(nota3, int));
}

void tocarMelodia(int notas[], int figuras[], int longitud)
{
    for (int i = 0; i < longitud; i++) {
        int duracionNota = (duracionTotalNota / figuras[i]);
        tone(6, notas[i], duracionNota * 0.9);
        delay(duracionNota);
        noTone(6);
    }
}

void loop() 
{
    tocarMelodia1();
    delay(1000);
    tocarMelodia2();
    delay(1000);
    tocarMelodia3();
    delay(1000);
}
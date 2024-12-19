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

#define MSG(a,b,c,d,e,f) Serial.print("Nota total: ");Serial.print(a);Serial.print(" Figura: ");Serial.print(b);Serial.print(" Duracion: ");Serial.print(c);Serial.print(" Silencio: ");Serial.print(d);Serial.print(" Tone duracion:");Serial.print(e);Serial.print(" Delay: ");Serial.println(f);

#define length(vec,tipo) sizeof(vec)/sizeof(tipo)


int nota[] = {NOTE_AS5, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_F4, 
              NOTE_B4, NOTE_GS4, NOTE_AS5, NOTE_C5, NOTE_C4, 
              NOTE_DS4, NOTE_C5, NOTE_AS5, NOTE_D4, NOTE_D4, 
              NOTE_GS4, NOTE_F4, NOTE_B4, NOTE_GS4, NOTE_AS5,
              NOTE_C5, NOTE_C4, NOTE_DS4, NOTE_C5, NOTE_AS5, 
              NOTE_CS4, NOTE_CS4, NOTE_GS4, NOTE_F4, NOTE_B4, 
              NOTE_GS4, NOTE_AS5, NOTE_C5, NOTE_C4, NOTE_DS4, 
              NOTE_C5, NOTE_AS5, NOTE_F4, NOTE_AS5, NOTE_GS4, 
              NOTE_F4, NOTE_CS5, NOTE_F4, NOTE_AS5, NOTE_GS4,
              NOTE_G4, NOTE_C5, NOTE_C4, NOTE_DS4, NOTE_C5,
              NOTE_F4, NOTE_F4};
int figura[] = {16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8};

int BPM = 110;
float tiempoSilencio = 4.0;
int duracionTotalNota = (60000 * 4) / BPM;


void setup() {
    pinMode( 6 , OUTPUT);
      Serial.begin(9600);
}


void loop() {
  
  for( int i = 0 ; i < length(nota,int)-1 ; i++ )
  {
    if( figura[i] >= 0 )
    {
          int duracionNota = ( duracionTotalNota / figura[i] )  ;
          tone( 6 , nota[i] , duracionNota * 0.9 );
          delay( duracionNota );  
          noTone(6);
    }else{
            int duracionNota = ( duracionTotalNota / (figura[i]*(-1)) )  ;
            tone( 6 , nota[i] , duracionNota * 0.9 );
              delay( duracionNota  );
              noTone(6);
    }
 }
}

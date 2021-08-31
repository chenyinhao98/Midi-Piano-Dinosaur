#include "pitches.h"
#define ACTIVATED LOW


const int PIEZO = 11;
const int LEDRED = 12;
const int LEDBLUE = 13;
const int LEDGREEN = 9;
const int LEDYELLOW = 10;

int buttonSong = 8;
const int BUTTON_C = 6;
const int BUTTON_AS = 4;
const int BUTTON_A = 3;
const int BUTTON_G = 2;


void setup()
{
  Serial.begin(9600);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_AS, INPUT);
  digitalWrite(BUTTON_AS,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  pinMode (buttonSong, INPUT);
  digitalWrite(buttonSong, HIGH);
  
  digitalWrite(LEDBLUE,LOW);
  digitalWrite(LEDRED,LOW);
  digitalWrite(LEDGREEN,LOW);
  digitalWrite(LEDYELLOW,LOW);
}


// notes in the melody:
int melody[] = {
NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,


NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3, 
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 




};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  
4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5,

4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5, 
2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 






} ;


void loop()
{
   while(digitalRead(BUTTON_C) == ACTIVATED)
  {
    tone(PIEZO,NOTE_C5);
    digitalWrite(LEDRED,HIGH);
  }
  while(digitalRead(BUTTON_AS) == ACTIVATED)
  {
    tone(PIEZO,NOTE_AS4);
    digitalWrite(LEDBLUE,HIGH);
  }

  while(digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO,NOTE_A4);
    digitalWrite(LEDGREEN,HIGH);
  }
  
  while(digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
    digitalWrite(LEDYELLOW,HIGH);
  }
  
  if(digitalRead(buttonSong) == ACTIVATED) {
    for (int thisNote=0; thisNote <85; thisNote++) {
      int noteDuration = 600 / noteDurations[thisNote];
      tone(11, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.50;
      delay(pauseBetweenNotes);
      noTone(11);
    }
    
  }

  noTone(PIEZO);
  digitalWrite(LEDRED,LOW);
  digitalWrite(LEDGREEN,LOW);
  digitalWrite(LEDYELLOW,LOW);
  digitalWrite(LEDBLUE,LOW);

}

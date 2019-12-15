#include "silent_night.h"

/* This melody is defined in the header above. */
int const melody[] = MELODY;

/********************************************************/
/* 3.) Define a constant LOUDSPEAKER_PIN containing the 
   number of the digital pin you just connected the 
   "+" pin of your loudspeaker to.
 */
#define LOUDSPEAKER_PIN 8
#define LED_PIN 7
/********************************************************/

void play(int note, long duration);

/********************************************************/
/* 7.) Define a new function waitForTap,
   that does nothing until the analog port A0 has
   some value greater than 10.
   
   Call that function just before you call play(int, long).
 */

bool closed()
{
  int val = analogRead(A0);
  return val < 800;
}

bool open()
{
  return analogRead(A0) > 950;
}

void waitForTap()
{
  while (!closed());
}

void waitForUntap()
{
  while (!open());
}

/********************************************************/

void play(int note, long duration) {
  /********************************************************/
  /* The variable note gives you a frequency in Hz.
     The variable duration is given in milliseconds.

     5.) Generate a rectangular wave with the given 
     frequency and duration.
     To do so, change the value at the loudspeaker pin
     to HIGH and to LOW for a sufficient number of
     times and wait an appropriate time after you set
     each value.

     Hint: Think about the resolutions you need!
     You may want to use more percise functions than the
     ones from the LEDFlash example.
   */

  int waitTime = 500000 / note;
  int numberOfCycles = (duration * note) / 1000;
  int i;
  for (i = 0; i < numberOfCycles; i++) {
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(waitTime);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(waitTime);
  }
  /********************************************************/
}

/* the setup routine runs once when you press reset: */
void setup() {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
}

/* the loop routine runs over and over again forever: */
void loop() {
  /********************************************************/
  /* 4.) Look at the included melody.
     How can you determine how long it is?
     
     Call play(int, long) with each note in the melody.
     Play each note for 125ms.
  */

  int note = 0;
  while (melody[note]) {
    waitForTap(); // This line is added in the last step
    digitalWrite(LED_PIN, HIGH);
    while (!open())
      play(melody[note], 100);
    waitForUntap();
    digitalWrite(LED_PIN, LOW);
    note++;
  }
  
  /********************************************************/
}

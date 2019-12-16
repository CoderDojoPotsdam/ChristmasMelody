#include "silent_night.h"

/* Die Konstante MELODY wird in der oben eingebundenen Datei definiert */
int const melody[] = MELODY;

#define LOUDSPEAKER_PIN 8
#define LED_PIN 7

#define BUTTON_PIN A0

/* Diese zwei Funktionen testen ob ein
 * Knopf, der zwischen 3,3V dem PIN und
 * dem A0-PIN angeschlossen ist gedrückt
 * oder losgelassen ist.
 *
 * Wir müssen einen undefinierten Wertebereich
 * ("Hysterese") lassen, da unsere Knöpfe sonst
 * im Übergangsbereich "wackeln" würden.
 *
 * Für den offiziellen Arduino Uno hat der
 * Wertebereich 800-950 gut funktioniert.
 *
 * Für den ELEGOO Uno R3 nimm 980-1005.
 */

bool isButtonDown()
{
  int val = analogRead(BUTTON_PIN);
  return val < 980;
}

bool isButtonUp()
{
  return analogRead(BUTTON_PIN) > 1005;
}

/********************************************************/
/* AUFGABE (EINSTIEG):
 * Definiere zwei Funktionen, die solang warten, bis
 * der Knopf gedrückt ist (waitForTap) oder losgelassen
 * wurde (waitForUntap).
 */

void waitForTap()
{
  while (!isButtonDown());
}

void waitForUntap()
{
  while (!isButtonUp());
}

/********************************************************/

void play(int note, long duration) {
  /********************************************************/
  /* AUFGABE (FÜR FORTGESCHRITTENE):
   * Generiere eine Rechteckschwingung.
   *
   * Der Parameter "note" gibt die Tonfrequenz in Hz.
   * Der Parameter "duration" gibt die Spielzeit in Millisekunden an.
   *
   * Ändere mit digitalWrite ausreichend oft den Wert am
   * Lautsprecher-PIN von HIGH zu LOW low. Warte nach jedem
   * Wechsel für eine passende Zeitlänge mit delayMicroseconds.
   *
   * Tipp: Recherchiere ob mit Arduinos noch einfacher
   * eine "Pulsweitenmodulation" zu realisieren ist.
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
}

/* Diese Methode wird beim Start (oder Reset) einmal ausgeführt */
void setup() {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
}


void playMelody() {
  /********************************************************/
  /* AUFGABEN (MITTEL):
   *
   * 1. Spiele die Melodie, indem du jeden Ton aus "melody"
   * für 100ms anspielst.
   *
   * 2. Warte mit dem Tonbeginn solang, bis der Knopf gedrückt wurde.
   *
   * 3. Halte den Ton solang, wie der Knopf gedrückt ist.
   * Tipp: Du kannst den Ton immer neustarten, solang der Knopf nicht
   * losgelassen wurde.
   *
   * 4. Schalte die LED an wenn ein Ton beginnt und aus, sobald er aufhört.
   */

  int note = 0;
  while (melody[note] != 0) {  /* Am Ende der Melodie ist eine "0" */
    waitForTap();
    digitalWrite(LED_PIN, HIGH);
    while (!isButtonUp())
      play(melody[note], 100);
    waitForUntap();
    digitalWrite(LED_PIN, LOW);
    note++;
  }
}

/* Diese Methode wird immer und immer wieder ausgeführt. */
void loop() {
  /* AUFGABE (EINSTIEG):
   *
   * 1. Lass die LED mit "digitalWrite(LED_PIN, HIGH)"
   * leuchten, sobald der Knopf gedrückt wurde.
   * Schalte sie aus (= LOW) wenn der Knopf losgelassen wurde.
   *
   * 2. Lösch den Code deiner LED und ruf statt dessen playMelody().
   */
   playMelody();
}

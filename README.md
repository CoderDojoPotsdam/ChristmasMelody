# Weichnachtsmelodie

Bau deinen eigenen blinkenden, musizierenden Weihnachtskasten.

![Schaubild Musikkasten](https://i.imgur.com/Qb8J9sF.jpg)

Ein Projekt des [CoderDojo Potsdam](https://coderdojopotsdam.github.io/) und des [ChaosTreff Potsdam](https://www.ccc-p.org) zum gemeinsamen Löten und Basteln in der Adventszeit.

Hier findest du den fertigen Quelltext. Wenn du etwas mehr lernen möchtest, wähle doch eine andere Schwierigkeitsstufe unter "branch" oben aus.

## Kabelbelegung

Falls dir die Kabel rausgerutscht sind, hier die Pin-Belegung:

| Bauteil      | Kabel 1   | Kabel 2    | Notiz                                        |
|--------------|-----------|------------|----------------------------------------------|
| Lautsprecher | Pin `8`   | Pin `GND`  | (beide rechts)                               |
| Knopf        | Pin `A0`  | Pin `3.3V` | (beide links)                                |
| LED          | Pin `7`   | Pin `GND`  | Wenn sie nicht leuchtet, die Kabel tauschen. |


## Bauanleitung

Falls du deine eigene Kiste nachbauen möchtest, findest du die Vorlagen für einen Lasercutter als in als SVG-Dateien mit im diesem Projekt. In Potsdam kannst du jeden Donnerstag um 18 Uhr beim [OpenLab in der machBar](https://machbar-potsdam.de/termine/) den Lasercutter gegen eine kleine Spende nutzen.

Bei der Auswahl der elektronischen Bauteile haben wir auf einen möglichst einfachen Zusammenbau im Rahmen des Adventslöten geachtet. Für alle Bauteile gibt es gute Alternativen. Frag deinen lokalen Elektronikbastler.

* Ein [Ardunino UNO](https://store.arduino.cc/arduino-uno-rev3) (bzw. ein Klon namens "Elgoo Uno R3")
* Einen [L-27 P/32R Mini-Lautsprecher](https://www.segor.de/#Q=L-27P%252F32R-Sonderpreis&M=1)
* Einen Knopf (Pushbutton) aus dem [Arduino-Set](https://www.arduino.cc/en/tutorial/pushbutton) (2 Beine)
* Eine LED, wie aus dem Arduino-Set
* Sechs Jumperkabel

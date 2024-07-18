/*
 Fundación Kinal
 Centro Educativo Técnico Laboral Kinal
 Quinto Perito
 Quinto Electronica
 Codigo Técnico: EB5AM
 Curso: Taller de Electrónica Digital y Reparación de Computadoras
 Proyecto: Práctica III Primera Parte Tercer Bimestre
 Dev: Jeffry Emanuel Arenales López
 Fecha: 18 de Julio 
 */

#include <LedControl.h>

//Directivas del preprocecador
#define pin_din 4
#define pin_cs 5
#define pin_clk 6

int POTE;

//Constructores

LedControl MacheMatriz = LedControl(pin_din, pin_clk, pin_cs, 1);

//Variables
byte pacman_boquiabierto[8] = {
  B00111000,
  B01010100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000,
};

byte pacman_boquicerrada[8] {
  B00111000,
  B01010100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000,
};


void setup() {
  Serial.begin(9600);
  //Enciendiendo mi matriz led y false implica que esta encendida la matriz(logica de negacion bro)
  MacheMatriz.shutdown(0, false);
  MacheMatriz.setIntensity(0, 15);
  MacheMatriz.clearDisplay(0);
  Serial.println("Uso de la matriz led:");


}
//ciclo infinito
void loop() {
  POTE = map(analogRead(A0), 0, 1023, 100, 1000);

  for (int i = 0; i < 8; i++) {
    MacheMatriz.setRow(0, i , pacman_boquiabierto[i]);
  }
  delay(POTE);
  for (int i = 0; i < 8; i++) {
    MacheMatriz.setRow(0, i , pacman_boquicerrada[i]);
  }
  delay (POTE);
}

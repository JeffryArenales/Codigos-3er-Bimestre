/*
 Fundación Kinal
 Centro Educativo Técnico Laboral Kinal
 Quinto Perito
 Quinto Electronica
 Codigo Técnico: EB5AM
 Curso: Taller de Electrónica Digital y Reparación de Computadoras
 Proyecto: Práctica II Tercer Bimestre
 Dev: Jeffry Emanuel Arenales López
 Fecha: 18 de Julio 
 */


#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

ADXL345 acelerometro = ADXL345(); 
int valorX, valorY, valorZ;
float sumaCuadrados, resX, resY, resZ, resultado;
float medida;

SoftwareSerial dfPlayerSerial(10, 11); // RX, TX
DFRobotDFPlayerMini reproductor;

void configuracion() {
  Serial.begin(9600);

  acelerometro.powerOn();
  acelerometro.setRangeSetting(2);

  dfPlayerSerial.begin(9600);
  reproductor.begin(dfPlayerSerial);
  reproductor.volume(25);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
}

 
void setup() {
  configuracion();
}

void loop() {
  acelerometro.readAccel(&valorX, &valorY, &valorZ);
  resX = valorX * 0.04;
  resY = valorY * 0.04;
  resZ = valorZ * 0.04;
  sumaCuadrados = ((resX * resX) + (resY * resY) + (resZ * resZ));
  
  resultado = sqrt(sumaCuadrados);

  medida = map(resultado, 8, 25.70, 0, 10);

  if (medida == 1) {
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
  }

  if (medida == 2) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  if (medida == 3) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  if (medida == 4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }

  if (medida == 5) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }

  if (medida == 6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    
    reproductor.play(1);
    delay(3000);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
          reproductor.pause();
  }

  if (medida == 7) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    
        reproductor.play(1);
    delay(3000);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
        reproductor.pause();
  }

  if (medida == 8) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    
        reproductor.play(1);
    delay(3000);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
        reproductor.pause();
  }

  if (medida == 9) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    
         reproductor.play(1);
    delay(3000);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
        reproductor.pause();
  }

  if (medida == 10) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);

        reproductor.play(1);
    delay(5000);
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
       reproductor.pause();
  }
}

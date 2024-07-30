/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto Electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Parte 2 Practica 3
   Dev: Jeffry Emanuel Arenales López
   Fecha: 27 de Julio.
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Directivas del preprocesador
#define widht_oled    128       //128 pixeles de ancho 
#define height_oled   64        //64 pixeles de alto
#define pot_pin       A0

//Constructores
Adafruit_SSD1306 JeffOled(widht_oled, height_oled, &Wire, -1);

//Variables
unsigned int adc_valor;

void setup() {
  Serial.begin(9600);  //Inicio la comunicación serial
  delay(100);          //pausa de 100 milisegundos
  Serial.println("Uso de la pantalla oled - practica 3 parte 2");
  pinMode(A0, INPUT);

//inicio de la comunicacion OLED
  if(!JeffOled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   //Ciclo infinito

  JeffOled.setTextSize(4);
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 JeffOled.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 JeffOled.setCursor(0, 0);
 //Imprimo la cadena de texto
 JeffOled.println("Jeffry Lopez");
 JeffOled.display();
}

}
void loop() {
   JeffOled.setTextSize(1);
 //Defino el color del texto a imprimir (la pantalla es monocromatica)
 JeffOled.setTextColor(SSD1306_WHITE);
 //Coloco el cursor en una posicion especifica
 JeffOled.setCursor(0, 0);
 //Imprimo la cadena de texto
 JeffOled.println("Valor del ADC");
 //Muestro en pantalla la cadena 
 JeffOled.display();
  adc_valor = analogRead(A0);       //leo el valor del canal 0 del ADC
  Serial.print("El valor del ADC es de: ");
  Serial.println(adc_valor);
  JeffOled.setTextSize(3);
  JeffOled.setTextColor(SSD1306_WHITE);
  JeffOled.setCursor(0,12);
  JeffOled.println(adc_valor);
  JeffOled.display();
  delay(200);
  JeffOled.clearDisplay();
}

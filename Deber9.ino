/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *        FICA-CITEL
 *     SISTEMAS EMBEBIDOS
 *     CHRISTIAN VILLEGAS
 *         DEBER 9
 */
 
#include <avr/wdt.h>
#include<MsTimer2.h>
int i = 0;
int cont = 0;
int leer;
int tiempo=0;
int j=0;
void setup(){
  Serial.begin(9600);
  MsTimer2::set(1000, reseteo);
  Serial.println("Ingrese el valor para el reinicio");
  delay(5000);
  MsTimer2::start();
}

void loop() {
  leer=analogRead(0);
  leer=map(leer , 0, 1023, 0, 60);
  Serial.println(String("Tiempo en el que se reiniciara: ")+String(leer-j));
  j++;
  delay(1000);
}

void reseteo() {
  cont++;
  if (cont>=leer){
    wdt_disable();
    wdt_enable(WDTO_500MS);
  }
}

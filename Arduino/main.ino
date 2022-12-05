#include <Servo.h>

#include <Keyboard.h>

Servo spalla;

Servo braccio;

Servo avambraccio;

Servo polso;

Servo mano;

Servo dita;

const int val=3;  

char incomingByte='n';

 

void setup() {

  Serial.begin(9600);

  pinMode(52, INPUT);

  pinMode(50, INPUT);

  pinMode(48, INPUT);

  spalla.attach(2);

  braccio.attach(3);

  avambraccio.attach(4);

  polso.attach(5);

  mano.attach(6);

  dita.attach(7);

 /*  

  spalla.write(65);

  braccio.write(160);

  avambraccio.write(180);

  polso.write(44);

  mano.write(100);

  dita.write(10);

posizione iniziale braccio 1 (blu)*/

 

   //posizione iniziale braccio 2(arancione)

  spalla.write(110);

   braccio.write(50);

   avambraccio.write(95);

   polso.write(105);

  mano.write(1);

  dita.write(5);

 }

void loop(){

/*

      if(digitalRead(52))

      backwords(val); 

      if(digitalRead(53))

      spara(val);  

      if(digitalRead(50))

      Serial.print("funzione va a destra "); 

      if(digitalRead(51))

     Serial.print("funzione va a sinistra"); 

     Serial.print("\n"); 

      */

   //lettura da porta seriale per input valore

 

  if  (Serial.available()) {

      incomingByte = Serial.read();

      switch(incomingByte){

      case 'w':

          up(val);

          break;

   

       case 'a':

         left(val);

         break;

   

       case 's':

         backwords(val);

         break;

   

      case 'd':

        right(val);

         break;

   

      case 'p':

       spara(val);

       break;

   

      }   

  }}

void up(int c)

{

  if(braccio.read()<134)

    braccio.write((braccio.read())+c);

    if(avambraccio.read()<107)

    avambraccio.write((avambraccio.read())+c);

    delay(25);

    Serial.print(braccio.read());

    Serial.print("\n");  

    Serial.print(   avambraccio.read()); 

    Serial.print("\n");

}

void right(int c)

{

  if(spalla.read()<172){

   spalla.write((spalla.read())+val);

   delay(25);} 

 

}

void left(int c)

{

  if(spalla.read()>49){

    spalla.write((spalla.read())-val);

    delay(20); }

}

void backwords(int c)

{  

    if(braccio.read()<108 && avambraccio.read()<173){

        braccio.write((braccio.read())+c);

        avambraccio.write((avambraccio.read())+c);

        delay(25);}

    else if(avambraccio.read()>110){

        avambraccio.write(avambraccio.read()-c);

        polso.write(polso.read()-(c+2));

        delay(25);

    

}}

void spara(int c)

{  

  while(dita.read()<87)

  {

     dita.write((dita.read())+c);

     delay(25);}

     dita.write(10);

}

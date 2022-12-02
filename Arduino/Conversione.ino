#define DIM 4
void setup() {
  Serial.begin(9600);
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(52, INPUT);
  pinMode(53, INPUT);
  
}

void loop() {
  short int pin[DIM] = {0, 1, 0, 1};
  for(short int i=0; i<DIM; i++)    pin[i] = digitalRead(50+i);
  Serial.print(conversione(pin)); // Prova debug converisone
  /*switch() Futuro Swithc
  {
    case 0:
      Funzione stop
      break;
    case 1:
      Funzione 1 
      
    }*/
}

short int conversione(short int pin[]){
  short int risultato = 0, conteggio[DIM] = {1, 2, 4, 8};
  for(short int i=0; i<DIM; i++)    risultato += conteggio[i]*pin[i];
  return risultato;
}

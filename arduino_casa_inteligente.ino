#include <IRremote.h>

//LEDS

byte ledPin[] = {3,4,5,6,7,8};

byte liga_desliga[]={0,0,0,0,0,0};
int resultado = 0;
//decode_results results;

//SENSOR GÁS
int sensor_gas = 0;
int leitura_sensor = 300;
int PinA0 = 0;
//BUZZER
int Pinbuzzer = 8;

//Teclas
byte RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
long int codTecla1 = 16724175;
long int codTecla2 = 16718055;
long int codTecla3 = 16743045;
long int codTecla4 = 16716015;
long int codTecla5 = 16726215;
long int codTecla6 = 16734885;
//long int codTecla7 = 16728765; //tecla para o portão da garegem
//long int codTecla8 = 16730805;
//long int codTecla9 = 16732845;
//long int codTecla0 = 16738455;
decode_results results;

void setup()
{
  //-------------------leds
   for(int i=0;i<=7;i++){
  pinMode(ledPin[i], OUTPUT);
  }
  for(int i=0;i<=7;i++){
  digitalWrite(ledPin[i], HIGH);
  }
  //--------------------gás
  pinMode (PinA0, INPUT);
  pinMode (Pinbuzzer, OUTPUT);
  Serial.begin(9600);
  //-------------------Controle Remoto
 irrecv.enableIRIn();
   
}

void loop()
{
  //LEDS
   if(irrecv.decode(&results)){
            
   if(results.value==codTecla1){
      resultado = liga_desliga[0] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[0],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[0],HIGH);
        delay(20);
      
      }
      liga_desliga[0]++;
 }
    if(results.value==codTecla2){
      resultado = liga_desliga[1] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[1],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[1],HIGH);
        delay(20);
      
      }
      liga_desliga[1]++;
 }
    if(results.value==codTecla3){
      resultado = liga_desliga[2] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[2],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[2],HIGH);
        delay(20);
      
      }
      liga_desliga[2]++;
 }
       if(results.value==codTecla4){
      resultado = liga_desliga[3] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[3],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[3],HIGH);
        delay(20);
      
      }
      liga_desliga[3]++;
 }
       if(results.value==codTecla5){
      resultado = liga_desliga[4] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[4],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[4],HIGH);
        delay(20);
      
      }
      liga_desliga[4]++;
 }
      if(results.value==codTecla6){
      resultado = liga_desliga[5] % 2;
      if(resultado == 0){
       digitalWrite(ledPin[5],LOW);
        delay(20); 
        }else{
        digitalWrite(ledPin[5],HIGH);
        delay(20);
      
      }
      liga_desliga[5]++;
 }
     irrecv.resume();
     delay(40);

    //SENSOR GÁS
  int valor_analogico = analogRead (PinA0);
  
   Serial.print("Leitura:");
   Serial.println(valor_analogico);
   
   if(valor_analogico > leitura_sensor){
   digitalWrite(Pinbuzzer, HIGH);
  }
  else{
    digitalWrite(Pinbuzzer, LOW);
  }
  delay(100);

   }  
   
  }


  


 

 

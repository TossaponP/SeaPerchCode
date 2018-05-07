int stat = 1;

//motor A
int enA = 7 ;
int in1 =5;
int in2 =6;

//motor B
int enB = 10;
int in3 = 8;
int in4 =9;

//motor C
int enC = 13;
int in5 =  11;
int in6 = 12;


int pushButton = 2; 
int pushButton2 =3; 


int pushButton3 =4; 
int anaButton = A0;
int anaButton2 = A1;
int anaButton3 = A2;

int anaButton4 = A3; 
int anaButton5 = A4;
int speedC = 0;

void setup() {

  Serial.begin(9600); 
  pinMode(pushButton, INPUT); 
  pinMode(pushButton2, INPUT); 
  pinMode(pushButton3, INPUT); 



  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  
  pinMode(enB,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(enC,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);
  
}


void loop() {

  int buttonState = digitalRead(pushButton); 
  int buttonState2 = digitalRead(pushButton2); 
  int buttonState3 = digitalRead(pushButton3); 


  int buttonState4 = analogRead(anaButton);
  int buttonState5 = analogRead(anaButton2);
  int buttonState6 = analogRead(anaButton3);
  int buttonState7 = analogRead(anaButton4);
  int buttonState8 = analogRead(anaButton5);



   if(stat == 1 ){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
  }else if( stat == 0){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
 }
    
      analogWrite(enA,0);
      analogWrite(enB,0);
  if(buttonState == 1){
   stat = 0;
      analogWrite(enA,255);
      analogWrite(enB,255);
  }else if(buttonState2 == 1){
      stat = 1;
      analogWrite(enA,255);
      analogWrite(enB,255);
  }else if(buttonState3 == 1){
      stat = 0;
      analogWrite(enA,0);
      analogWrite(enB,255);
    
     //Serial.println("Didgi 4");
  }else if(buttonState4 > 100){
      stat = 0;
      analogWrite(enA,255);
      analogWrite(enB,0);
     
    //Serial.println("Analog A0");
  }else if(buttonState5 > 100){
       stat = 1;
      analogWrite(enA,255);
      analogWrite(enB,0);
  }else if(buttonState6 > 100){
       stat = 1;
      analogWrite(enA,0);
      analogWrite(enB,255);
  }else if(buttonState7 > 100){
    stat = 1;
      if(speedC == 0){
         speedC = 0;
      }else{
        speedC = speedC -1;
      }

     analogWrite(enC,speedC);

    Serial.println(speedC);
     
  }else if(buttonState8 > 100){
     stat = 1;
      if(speedC == 255){
         speedC = 255;
      }else{
        speedC = speedC +1;
      }

     analogWrite(enC,speedC);
     Serial.println(speedC);
    
  }

  delay(1);
  
  
}

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int ena = 9;
const int in1 = 8;
const int in2 = 7;

const int enb = 3;
const int in3 = 5;
const int in4 = 4;

const int x_joystick = A0;
const int y_joystick = A1;

const int joystick_low = 0;
const int joystick_high = 1023;

const int motorLow = 0;
const int motorHigh = 255;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ena, OUTPUT); 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(enb, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 
}

void demo1(){
  digitalWrite(ena, HIGH);   
  digitalWrite(in1, HIGH);    
  digitalWrite(in2, LOW); 
  
  analogWrite(ena, 200);
  
  digitalWrite(in3, HIGH);    
  digitalWrite(in4, LOW); 
  
  analogWrite(enb, 200);
  
  delay(2000);  
  
  digitalWrite(in1, LOW);    
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);    
  digitalWrite(in4, HIGH); 
  
  delay(2000); 
  
  digitalWrite(in1, LOW);    
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);    
  digitalWrite(in4, LOW); 
  
}

void demo2(){
    digitalWrite(in1, LOW);    
    digitalWrite(in2, HIGH); 
    digitalWrite(in3, LOW);    
    digitalWrite(in4, HIGH); 
    
    for(int i=0; i <256 ; ++i){
      analogWrite(ena, i);
      analogWrite(enb, i);
      delay(20);  
  }
  
  for(int i=255; i > 0 ; --i){
      analogWrite(ena, i);
      analogWrite(enb, i);
      delay(20);  
  }
  
  digitalWrite(in1, LOW);    
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);    
  digitalWrite(in4, LOW);
  
}

void joystick_motor(){
  
   int xreading = analogRead(x_joystick);
   int yreading = analogRead(y_joystick);
  
    
}


void loop() {
  
  demo1();
  
  delay(1000);
  
  demo2();
  
  delay(1000);
}

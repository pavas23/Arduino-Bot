#include<SoftwareSerial.h>
// this library is used to setup a dummy COM port on Arduino which allows for bluetooth 
//communication

SoftwareSerial abc(2,5);
//Setting 8 and 9 pins on Arduino Uno as RX and TX pins instead of 0 and 1 pins

char val;
//8-->RX on arduino
//9-->TX on arduino
int en1 = 3;
int en2 = 9;
int inp1 = 7;
int inp2 = 4;
int inp3 = 8;
int inp4 = 12;
void setup() {
  Serial.begin(9600);//setting up Serial monitor
  abc.begin(9600);//setting up Serial communication with the App over bluetooth
  pinMode(inp1,OUTPUT);
  pinMode(inp2,OUTPUT);
  pinMode(inp3,OUTPUT);
  pinMode(inp4,OUTPUT);
  //Setting up the direction pins on the motor driver as output pins
}

void loop() {
  while(abc.available()==0){}
  //to wait till there is any input from the App
  
  val=abc.read();
  //once the input is received, we gotta read it into a variable 
  digitalWrite(en1,1);
  digitalWrite(en2,1);
  
  if(val=='F'){
    
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, HIGH);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, HIGH);
  }//to move the bot forward

  else if(val=='B'){
    digitalWrite(inp1, HIGH);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, HIGH);
    digitalWrite(inp4, LOW);
  }//to move the bot backwards

  else if(val=='L'){
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, HIGH);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, LOW);
  }//to turn bot left

  else if(val=='R'){
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, HIGH);
  }//to turn bot right

  else if(val=='S'){
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, LOW);
  }//to stop the bot

  Serial.println(val);
}

// Arduino Line Follower Robot Code


#define enA 10//Enable1 L293 Pin enA   right

#define in1 8 //Motor1  L293 Pin in1 

#define in2 9 //Motor1  L293 Pin in1 

#define in3 7 //Motor2  L293 Pin in1 

#define in4 6 //Motor2  L293 Pin in1 

#define enB 11 //Enable2 L293 Pin enB   left

#define R_S A0//ir sensor Right

#define L_S A1 //ir sensor Left

void setup(){ 

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(enB, OUTPUT);

analogWrite(enA, 0); 

analogWrite(enB, 0); 

pinMode(13,OUTPUT);
digitalWrite(13,0);
delay(2000);
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(2000);
digitalWrite(13,1);
delay(1000);
digitalWrite(13,0);
delay(3000);
digitalWrite(13,1);
delay(200);
digitalWrite(13,0);
delay(200);
digitalWrite(13,1);
delay(200);
digitalWrite(13,0);

}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function

}

void forward(){  //forword

digitalWrite(in1, HIGH); //Right Motor forword Pin 

digitalWrite(in2, LOW);  //Right Motor backword Pin 

digitalWrite(in3, LOW);  //Left Motor backword Pin 

digitalWrite(in4, HIGH); //Left Motor forword Pin 

analogWrite(enA, 60); 

analogWrite(enB, 60); 

}

void turnRight(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 

digitalWrite(in2, HIGH); //Right Motor backword Pin  

digitalWrite(in3, LOW);  //Left Motor backword Pin 

digitalWrite(in4, HIGH); //Left Motor forword Pin 

analogWrite(enA, 120); 

analogWrite(enB, 150); 

}

void turnLeft(){ //turnLeft

digitalWrite(in1, HIGH); //Right Motor forword Pin 

digitalWrite(in2, LOW);  //Right Motor backword Pin 

digitalWrite(in3, HIGH); //Left Motor backword Pin 

digitalWrite(in4, LOW);  //Left Motor forword Pin 

analogWrite(enA, 150); 

analogWrite(enB, 120); 

}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 

analogWrite(enA, 0); 

analogWrite(enB, 0); 

}
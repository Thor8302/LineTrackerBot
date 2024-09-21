// Optimized Arduino Line Follower Robot Code

#define enA 10  // Enable1 L293 Pin enA (right motor)
#define in1 8   // Motor1 L293 Pin in1 (right motor forward)
#define in2 9   // Motor1 L293 Pin in2 (right motor backward)
#define in3 7   // Motor2 L293 Pin in3 (left motor forward)
#define in4 6   // Motor2 L293 Pin in4 (left motor backward)
#define enB 11  // Enable2 L293 Pin enB (left motor)

#define R_S A0  // Right IR sensor
#define L_S A1  // Left IR sensor

int baseSpeed = 100;  // Base speed for both motors
int turnSpeed = 50;   // Speed differential for turning

void setup() {
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(1000);  // Simple startup delay
}

void loop() {
  int rightSensor = digitalRead(R_S);  // Read right sensor
  int leftSensor = digitalRead(L_S);   // Read left sensor

  // Condition for forward movement
  if (rightSensor == 0 && leftSensor == 0) {
    forward(baseSpeed);
  }

  // Condition for turning right
  else if (rightSensor == 1 && leftSensor == 0) {
    turnRight(baseSpeed, turnSpeed);
  }

  // Condition for turning left
  else if (rightSensor == 0 && leftSensor == 1) {
    turnLeft(baseSpeed, turnSpeed);
  }

  // Condition for stopping (both sensors on black)
  else if (rightSensor == 1 && leftSensor == 1) {
    Stop();
  }
}

void forward(int speed) {
  digitalWrite(in1, HIGH);  // Right motor forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);  // Left motor forward
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);  // Adjust PWM for speed control
  analogWrite(enB, speed);
}

void turnRight(int baseSpeed, int turnSpeed) {
  digitalWrite(in1, HIGH);  // Right motor slow down
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);  // Left motor speed up
  digitalWrite(in4, LOW);
  analogWrite(enA, baseSpeed - turnSpeed);  // Right motor slower
  analogWrite(enB, baseSpeed + turnSpeed);  // Left motor faster
}

void turnLeft(int baseSpeed, int turnSpeed) {
  digitalWrite(in1, HIGH);  // Right motor speed up
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);  // Left motor slow down
  digitalWrite(in4, LOW);
  analogWrite(enA, baseSpeed + turnSpeed);  // Right motor faster
  analogWrite(enB, baseSpeed - turnSpeed);  // Left motor slower
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);  // Stop motors
  analogWrite(enB, 0);
}

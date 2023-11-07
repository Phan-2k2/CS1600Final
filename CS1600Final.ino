/*
* Prints the result of the button press to the serial monitor.
*/

#include <Servo.h>

Servo myservo;
int servoPosition = 0;

int button6 = 6;
int button7 = 7;
int button8 = 8;
int button9 = 9;
int servoPin = 5;

int enablePin = 2;
int in1Pin = 3;
int in2Pin = 4;


void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize
  Serial.println("Ready!");
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);
  myservo.attach(servoPin);  


  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

void loop() {
  int buttonState6 = digitalRead(button6);
  int buttonState7 = digitalRead(button7);
  int buttonState8 = digitalRead(button8);
  int buttonState9 = digitalRead(button9);


  if (buttonState6 == HIGH) {
    Serial.println("Button6 pressed!");
    myservo.writeMicroseconds(0);
  }
  if (buttonState7 == HIGH) {
    Serial.println("Button7 pressed!");
    myservo.write(180);
  }
  if (buttonState8 == HIGH) {
    Serial.println("Button8 pressed!");
    setMotor(255, true);
  } else if (buttonState9 == HIGH) {
    Serial.println("Button9 pressed!");
    setMotor(255, false);
  } else {
    setMotor(0, false);
  }
}
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}





// int enablePin = 2;
// int in1Pin = 3;
// int in2Pin = 4;

// void setup()
// {
//   pinMode(in1Pin, OUTPUT);
//   pinMode(in2Pin, OUTPUT);
//   pinMode(enablePin, OUTPUT);
// }

// void loop()
// {
//   int speed = analogRead(potPin) / 4;
//   boolean reverse = digitalRead(switchPin);
//   setMotor(speed, reverse);
// }

// void setMotor(int speed, boolean reverse)
// {
//   analogWrite(enablePin, speed);
//   digitalWrite(in1Pin, ! reverse);
//   digitalWrite(in2Pin, reverse);
// }
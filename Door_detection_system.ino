/*
  First part of the Code for creating the Ultrasonic sensor interface
  
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial
  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzPin=8;
// defines variables
long duration;
int distance;
bool dooropen;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   pinMode(buzzPin, OUTPUT); // Sets the trigPin as an Output
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(dooropen);
  /*
  instructions to activate the active buzzer:
  
  if  it is sensed that the door opened (Sensor detected a distance of at least 10cm)
  then set the door open in the code and delay for a second
  
  if the door was closed and the sensor captured the required distance the
  "dooropen" variable becomes true and the buzzer is active
  
  if the door is then sensed to close after it was already open
  the buzzer will turn off.
  */
  if (distance<=10){
    delay(1000);
    if(dooropen==false){
    digitalWrite(buzzPin,HIGH);
    dooropen=true;
    
    }
    else{
      delay(10);
      digitalWrite(buzzPin,LOW);
      dooropen=false;
     
      
}
      
      }}

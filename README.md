# Open Door Detection
Very simple Arduino Project using an Ultrasonic sensor and a Active Buzzer to alert that a door has been let open.


# Code Operation
if it is sensed that the door opened 
(Sensor detected a distance of at least 10cm) and the door was closed the buzzer is active.
if the door is then sensed to close after it was already open the buzzer will turn off.

The code for detecting distances in centimeters is extracted from: 
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/

# Schematic

![image](https://user-images.githubusercontent.com/124648406/228062538-1541d05d-a008-4bc8-bff5-b82ede0b17e4.png)

* Keep in mind that the ultrasonic sensor requires the signals trig and echo to be a PWM. If the pins are changed on code, they must be a PWM output on the arduino in order to work.



Here is a small demonstration on the operation of the device:

https://user-images.githubusercontent.com/124648406/228067111-78f69b5f-3924-46ea-ab03-61c40e5f7763.mov



# Notes
* You might want to play with the delay times and the distance requirement at the end of the code to assure that the system works well for you (depending on how close
or far the sensor is located from the door). The serial port 9600 displays the current distance detected from the sensor and the state of the door within the code for troubleshooting purposes.
````C++
//this process is triggered when a distance of 10cm or lower is sensed
//altering the comparison value on the if statement allows for greater or lower sensitivity.
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

````

* The placement of the sensor is also important, ideally you will want the sensor to be located at the highest distance possible from the door, as you don’t want the sensor to detect people and trigger the buzzer. 




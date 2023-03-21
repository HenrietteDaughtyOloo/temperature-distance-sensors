#include <Servo.h>

#define temperature A0
#define orangeLED 4

Servo myServo;
int position = 0;
int previousPosition;

void setup() {
  
  pinMode(temperature, INPUT);
  pinMode(orangeLED, OUTPUT);
  myServo.attach(9);
  
  Serial.begin(9600);

}

void loop() {
  
  int temperatureReading = analogRead(temperature);  // code that does analysis of the Temperature.

  float voltage = temperatureReading * 5.0;    //  Since were using 5v power.

  
  voltage /= 1024.0;    // Divided by 1024 to covert the value 0-1023 from ADC to 0-5V the sensor's output voltage

  float tempChange = (voltage - 0.5) * 100;  //Converting Volts into temperature i.e from 10mv per degree
  
  int position = map(tempChange, 31,125, 90, 180);  // The code maps temperature to degrees

  Serial.println(position);
  if(previousPosition != position){
     myServo.write(position);
  	 digitalWrite(orangeLED, HIGH);
     delay(1000);
  }
     
  digitalWrite(orangeLED, LOW);
  previousPosition = position;
}



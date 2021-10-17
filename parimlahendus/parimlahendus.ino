/*
 * Capacitor = 100nF
 * Resistor = 4.7kOhm
 */



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  if(sensorValue == 0){
    Serial.println("Too strong light, out of measurement!");
  }else{
    Serial.println(10000/sensorValue-10);
  }
  // print out the value you read:
  delay(1000);
}

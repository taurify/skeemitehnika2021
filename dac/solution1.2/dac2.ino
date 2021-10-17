void setup() {
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm = 0;
  float voltage = 3.75;
  int input;
  float voltageInput;
  pwm = (voltage / 5) * 255;
  

  while(1)
  {
      input = analogRead(0);
      voltageInput = ((float)input / 1023) * 5;
      Serial.print("Voltage: ");
      Serial.println(voltageInput);
      analogWrite(3,pwm);
  }
}

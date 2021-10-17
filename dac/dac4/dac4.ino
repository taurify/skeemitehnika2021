#include <MCP48xx.h>

float voltageAim = 3.75;
int input1,input2;
float voltage;
int sine;

const byte mcp4802_cs_pin = 10;
const byte mcp4802_ldac_pin = 9;

MCP4802 mcp4802(mcp4802_cs_pin);

void setup() {
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(mcp4802_ldac_pin, OUTPUT);
  digitalWrite(mcp4802_ldac_pin, LOW);

  mcp4802.init();
  mcp4802.setGainA(MCP4802::High);
  mcp4802.turnOnChannelA();
  mcp4802.setVoltageA(0);
  mcp4802.updateDAC();
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

  while(1)
  {
      input1 = analogRead(0);
      input2 = analogRead(1);
      //DAC
      voltage = ((float)input1 / 1023) * 5;
      Serial.println(voltage);
      //FILL
      /*voltage = ((float)input2 / 1023) * 5;
      Serial.println(voltage);*/
      sine = sine % 360 + 3;
      voltageAim = 2.5 + 2.5*sin(sine * DEG_TO_RAD);
      mcp4802.setVoltageA((voltageAim/5)*255);
      mcp4802.updateDAC();
      if(voltage < voltageAim)
      {
        analogWrite(3,255);
      }
      else
      {
        analogWrite(3,0);
      }
      delay(100);      
  }
}

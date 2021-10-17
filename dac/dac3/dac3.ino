void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int* getBinaryFilterArray(float voltageAim)
{
  int i = 0;
  int* filterArray = (int*)malloc(sizeof(int)*6);
  int set = (voltageAim / 5) * 63;
  if(voltageAim > 5)
  {
    while(i < 6)
    {
      filterArray[i] = 1;
      i++;
    }
    return filterArray;
  }
  while(i < 6)
  {
    filterArray[i] = set&1;
    set = set >> 1;
    i++;
  }
  return filterArray;
}

void BinaryFilterSet(int* set, int port[])
{
  int i = 0;
  while(i<6)
  {
    if(set[i] == 1)
    {
      analogWrite(port[i],255);
    }
    else
    {
      analogWrite(port[i],0);
    }
    i++;
  }
  free(set);
}

float voltageAim = 3.25;
int input;
float voltageInput;
int port[] = {3,5,6,9,10,11};
int* set = getBinaryFilterArray(voltageAim);
int sinValue = 0;

void loop() {
  input = analogRead(0);
  sinValue = sinValue % 360 + 3;
  voltageAim = 2.5 + 2.5*sin(sinValue * DEG_TO_RAD);
  voltageInput = ((float)input / 1023) * 5;
  Serial.println(voltageInput);
  set = getBinaryFilterArray(voltageAim);
  BinaryFilterSet(set, port);
  
  delay(100);
}

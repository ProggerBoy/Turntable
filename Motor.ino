byte stepperPins[] = {8,9,10,11};
int Pin0=A4;
unsigned int motorSpeed =  10000;
int StepCounter=0;
int ArrayPosition;

byte stepValue[8][4]={{HIGH,LOW,LOW,LOW},
                      {HIGH,HIGH,LOW,LOW},                     
                      {LOW,HIGH,LOW,LOW},                      
                      {LOW,HIGH,HIGH,LOW},                     
                      {LOW,LOW,HIGH,LOW},                      
                      {LOW,LOW,HIGH,HIGH},                     
                      {LOW,LOW,LOW,HIGH},                      
                      {HIGH,LOW,LOW,HIGH}};  

void setup() {
  pinMode(Pin0,INPUT);
  digitalWrite(Pin0, HIGH);
  for(int i= 0; i<4; i++)
  pinMode(stepperPins[i], OUTPUT); 
}              
void loop(){ 
  unsigned long n = millis() / 3000; // 3 Sekunden
  if(digitalRead(Pin0)==LOW){
    StepCounter=0;
    ArrayPosition=0;
    for(StepCounter=0; StepCounter<=8; StepCounter++){
      for(ArrayPosition=0; ArrayPosition<4; ArrayPosition++)
        digitalWrite(stepperPins[ArrayPosition], stepValue[StepCounter][ArrayPosition]);
      delayMicroseconds(motorSpeed);
      }
    }
  else{};
}

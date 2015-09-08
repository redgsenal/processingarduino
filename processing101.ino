char charSerial;
int valSerial;

int pinLED1 = 4;
int pinLED2 = 2;
int pinLED1status = 0;
int pinLED2status = 0;

int potPin = 0;
int potVal = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  valSerial = 0;
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
}

void loop() {
  while (Serial.available() == 0){
    potVal = map(analogRead(potPin), 0, 1023, 0, 255);
    //Serial.print("potVal ");
    Serial.println(potVal);
    delay(500);
  }
  charSerial = (char)Serial.read();
  valSerial = charSerial - '0';
  //Serial.println(valSerial);
  if (valSerial == 1){
    pinLED1status = setLEDStatus(pinLED1, pinLED1status);
  }
  else if (valSerial == 2){
    pinLED2status = setLEDStatus(pinLED2, pinLED2status);
  }else{
    Serial.println("Invalid");
  }
  Serial.flush();
}

int setLEDStatus(int pinNo, int pinStatus){
   if (pinStatus){
      digitalWrite(pinNo, LOW);
      pinStatus = 0;
    }else{
      digitalWrite(pinNo, HIGH);
      pinStatus = 1;
    }
    return pinStatus;
}


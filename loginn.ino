#include <PS2Keyboard.h>

const int DataPin = 8;
const int IRQpin =  2;
const int DoorPin = 13;
PS2Keyboard keyboard;
char sendValue[100];
char receiveValue[100];
String pass = "toggle";

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  
}

void loop() {
  
  int i = 0;
  bool READ = false;
  bool RECEIVE = false;

  for (int j=0; j<100; j++) {
    sendValue[j] = 0;
    receiveValue[j] = 0;
  }

  while (keyboard.available()) {
    READ=true;
    // read the next key
    char c = keyboard.read();
    sendValue[i] = c;

    i++;
    delay(10); //Barcode Scanner is slower than Arduino. So you have to put delay on the source code.
    
  }

  if (READ) {
    Serial.print("pwd ");
    Serial.println(sendValue);
  }

  i = 0;
  
  while (Serial.available()) {
    RECEIVE = true;
    char c = Serial.read();
    receiveValue[i] = c;
    i++;
  }

  if (RECEIVE) {
    for (int j=0; j<100; j++) {
      if (receiveValue[j] == pass[j]) {
        if (receiveValue[j] == 0) {
          pinMode(DoorPin, OUTPUT);
          digitalWrite(DoorPin, LOW);
          delay(100);
          pinMode(DoorPin, INPUT);
          break;
        }
      }
    }
  }
}

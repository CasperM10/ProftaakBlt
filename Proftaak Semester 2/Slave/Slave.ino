
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
char c = ' ';

void setup()
{
  pinMode(2, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(2, LOW);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}

void loop()
{
  if (BTSerial.available()){
    Serial.write(BTSerial.read());
  }
    
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  /*if (BTSerial.available()){
    c = BTSerial.read();
    Serial.println(c);
    if (c == 49){
      if(digitalRead(2) == HIGH){
      digitalWrite(2, LOW); 
    } else {
      digitalWrite(2, HIGH);
    }
  }
  }*/

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());

  
}

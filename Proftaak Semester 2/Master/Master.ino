
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
int lastReading = 0;

void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
  //BTSerial.write("AT+INQ");
  //BTSerial.write("AT+CONN1");
}

void loop()
{  
  int reading = map(analogRead(A5), 0, 1024, 5, 30);
  if(reading != lastReading) {
    BTSerial.print(reading);
    Serial.println(reading);
    lastReading = reading;
    }
  
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}

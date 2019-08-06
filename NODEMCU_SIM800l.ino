// GET MORE DETAILS HERE http://miliohm.com/sim800l-arduino-tutorial/

#include <SoftwareSerial.h>
SoftwareSerial sim(5, 4); //RX,TX

String number = "+65********"; // ++65 is the country code
String number2 = "+65********"; 

void setup() {
  Serial.begin(9600);
  Serial.println("Wait few seconds...");
  delay(5000);
  Serial.println("System Started...");
  sim.begin(9600);
  delay(1000);
  Serial.println("Type c to make a call and s to send an SMS");
}

void loop() {
  if (Serial.available() > 0)
    switch (Serial.read())
    {
      case 'c':
        callNumber();
        break;
      case 's':
        SendMessage();
        break;
    }
  if (sim.available() > 0)
    Serial.write(sim.read());
}

void SendMessage()
{
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(1000);
  String SMS = "Hello, this message is from arduino..";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);
  delay(1000);
}

void callNumber() {
  sim.print (F("ATD"));
  sim.print (number2);
  sim.print (F(";\r\n"));
}

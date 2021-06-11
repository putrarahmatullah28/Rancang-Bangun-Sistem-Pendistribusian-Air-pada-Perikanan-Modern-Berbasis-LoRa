#include <SPI.h>
#include <LoRa.h>

 int Led = 5;
 int Buzz = 11;

void setup() 
{
  Serial.begin(9600);   
  pinMode(Buzz,OUTPUT);
  digitalWrite(Buzz,HIGH);
  delay(500);
  digitalWrite(Buzz,LOW);
  delay(500);
  digitalWrite(Buzz,HIGH);
  delay(500);
  while (!Serial);
  
  if (!LoRa.begin(433E6)) {
   Serial.println("Starting LoRa failed!");
    delay(500);
    while (1);
  }
}

void loop()
{
  int packetSize = LoRa.parsePacket();
  if (packetSize) 
  {
    while (LoRa.available())
    {
     char data = LoRa.read();
     Serial.print(data);
    }
}
}

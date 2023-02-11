#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include "server_config.h"

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

EthernetClient askClient;
PubSubClient client(askClient);

//
void reconnect()
{

  while (!client.connected())
  {

    if (client.connect(CLIENTID, USERNAME, PASSWORD))
    {
      Serial.println("*** Connected MQTT server successfully.");
      client.subscribe(PROPERTY_DOWN, 1);
      client.subscribe(ACTION_DOWN, 1);
    }
    else
    {
      Serial.print("*** Connected MQTT server failed, rc=");
      Serial.print(client.state());
      Serial.println(", try again in 5 seconds");
      delay(5000);
    }
  }
}
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("*** Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
//
void setup()
{
  Serial.begin(115200);
  while (Serial.available())
    ;
  Serial.print("*** Device starting: ");
  Serial.println(DEVICEID);
  Serial.print("*** Device Baud Rate: ");
  Serial.println(115200);
  Serial.print("*** MQTT Server: ");
  Serial.println(MQTT_HOST);
  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac);
  }
  delay(1000);
  client.setServer(MQTT_HOST, MQTT_PORT);
  client.setCallback(callback);
}

//
static char json[80];
void loop()
{
  if (!client.connected())
  {
    reconnect();
    return;
  }
  double a0 = analogRead(A0) * (5.0 / 1023.0);
  double a1 = analogRead(A1) * (5.0 / 1023.0);
  double a2 = analogRead(A2) * (5.0 / 1023.0);
  double a3 = analogRead(A3) * (5.0 / 1023.0);
  double a4 = analogRead(A4) * (5.0 / 1023.0);
  sprintf(json, "{\"adc0\":%2f,\"adc1\":%2f,\"adc2\":%2f,\"adc3\":%2f,\"adc4\":%2f}", a0, a1, a2, a3, a4);
  client.publish(PROPERTY_UP, (uint8_t *)json, strlen(json), false);
  client.loop();
  delay(5000);
}

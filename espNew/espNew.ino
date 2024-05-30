#define BLYNK_TEMPLATE_ID "TMPL6oXAye89F"
#define BLYNK_TEMPLATE_NAME "Smart Coffee Machine"
#define BLYNK_AUTH_TOKEN "QbtuxxMRcaP-nFTaONjMV_QXu3Ny0xm8"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Galaxy A51 25DC";
char pass[] = "ihke5276";

BlynkTimer timer;
int high=1;
int low=0;
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int coffee = param.asInt();

  // Update state
  Blynk.virtualWrite(V0, coffee);

    Blynk.virtualWrite(V1, low);
    Blynk.virtualWrite(V3, low);

  Serial.println("coffee");
  Serial.println(coffee);
}
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V1)
{
  // Set incoming value from pin V0 to a variable
  int coffeeMilk = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, coffeeMilk);

      Blynk.virtualWrite(V0, low);
    Blynk.virtualWrite(V3, low);

    Serial.println("coffee & milk");
  Serial.println(coffeeMilk);
}
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V2)
{
  // Set incoming value from pin V0 to a variable
  int cupSize = param.asInt();

  // Update state
  Blynk.virtualWrite(V2, cupSize);
  
    Serial.println("cup size");
  Serial.println(cupSize);
}
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V3)
{
  // Set incoming value from pin V0 to a variable
  int espresso = param.asInt();

  // Update state
  Blynk.virtualWrite(V3, espresso);

      Blynk.virtualWrite(V1, low);
    Blynk.virtualWrite(V0, low);

   Serial.println("espresso");
  Serial.println(espresso);
}
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V4)
{
  // Set incoming value from pin V0 to a variable
  int con = param.asInt();

  // Update state
  Blynk.virtualWrite(V4, con);
   Serial.println("con");
  Serial.println(con);
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

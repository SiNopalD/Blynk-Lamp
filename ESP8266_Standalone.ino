#define BLYNK_PRINT Serial

/* Isi template ID kamu (Hanya jika kamu menggunakan Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h>

// Kamu bisa menerima token autentikasi di Aplikasi Blynk atau Gmail.
// Pergi ke pengaturan project (icon nut).
char auth[] = "_1QzT1tAH5RHcuZYAEB9G4sZ-xqr7SUN";

// Wifi Kredensial kita.
// Set kata sandi di dalam "" untuk membuka jaringan.
char ssid[] = "AndroidA";
char pass[] = "00000000";

void setup()
{
  // Konsol Debug
  //WiFiManager wifiManager;
  //wifiManager.autoConnect("Opal");
  //WiFiManagerParameter custom_blynk_token("Blynk", "blynk token", auth, 33);
  //wifiManager.addParameter(&custom_blynk_token);
  //Blynk.config(custom_blynk_token.getValue());


  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

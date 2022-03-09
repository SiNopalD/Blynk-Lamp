#define BLYNK_PRINT Serial

/* Isi template ID kamu (Hanya jika kamu menggunakan Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h>

// Kamu bisa menerima token autentikasi di Aplikasi Blynk atau Gmail.
// Pergi ke pengaturan project (icon nut).
char auth[] = "Your Blynk Token";

void setup()
{
  // WiFi Manager
  WiFiManager wifiManager;
  wifiManager.autoConnect("Opal");
  WiFiManagerParameter custom_blynk_token("Blynk", "blynk token", auth, 33);
  wifiManager.addParameter(&custom_blynk_token);
  Blynk.config(custom_blynk_token.getValue());
  Serial.begin(9600);
  String ssid = wifiManager.getWiFiSSID();
  String pass = wifiManager.getWiFiPass();
  int n = ssid.length();
  int o = pass.length();
  char char_ssid[n+1];
  char char_pass[o+1];
  strcpy(char_ssid, ssid.c_str());
  strcpy(char_pass, pass.c_str());

  Serial.println(ssid);
  Serial.println(pass);

  Blynk.begin(auth, char_ssid, char_pass);
  //  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}

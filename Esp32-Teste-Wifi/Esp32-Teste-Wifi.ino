#include <WiFi.h>
const char* ssid = "TUPI";   /*Replace SSID of your network*/
const char* password = "12345678"; /*Replace with Password of your Network*/
void initWiFi() {
  WiFi.mode(WIFI_STA);  /*Initialize ESP32 WiFi in station mode*/
  WiFi.begin(ssid, password); /*Begin WiFi connection*/
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());  /*Print local IP address of ESP32*/
}
void setup() {
  Serial.begin(115200); /*Baud Rate for serial communication*/
  initWiFi();  /*Initialize WiFi*/
  Serial.print("Connected Network Signal Strength (RSSI): ");
  Serial.println(WiFi.RSSI());  /*Print WiFi signal strength*/
}
void loop() {
}
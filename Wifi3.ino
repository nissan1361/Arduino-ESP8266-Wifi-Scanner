#include <ESP8266WiFi.h>
 

void setup() {
  Serial.begin(4800);
  Serial.println(""); //Remove garbage
 
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();  //ESP has tendency to store old SSID and PASSword and tries to connect
  delay(100);

  Serial.println("WiFi Netwoek Scan Started");
}
 

void loop() {
 
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
   
  Serial.println("Scan done");
  
  if (n == 0)
    Serial.println("No Networks Found");
  else
  {
    Serial.print(n);
    Serial.println(" Networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);  //Sr. No
      Serial.print(": ");
      Serial.print(WiFi.SSID(i)); //SSID
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); //Signal Strength
      Serial.print(") MAC:");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" Unsecured":" Secured");
      delay(10);
    }
  }
  Serial.println("");
 
  // Wait a bit before starting New scanning again
  delay(5000);
}

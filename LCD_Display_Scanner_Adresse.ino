#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial); // Warte auf den seriellen Monitor (nur bei einigen Boards nötig)
  Serial.println("I2C Scanner gestartet...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C Gerät gefunden bei Adresse 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("Unbekannter Fehler bei Adresse 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("Keine I2C Geräte gefunden\n");
  else
    Serial.println("Scan abgeschlossen\n");

  delay(5000); // Warte 5 Sekunden und scanne erneut
}

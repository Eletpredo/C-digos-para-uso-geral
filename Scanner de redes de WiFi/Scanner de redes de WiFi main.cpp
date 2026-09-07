#include <Arduino.h>
#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Escaneando redes Wi-Fi...");
    int n = WiFi.scanNetworks();
    
    if (n == 0) {
        Serial.println("Nenhuma rede encontrada.");
    } else {
        Serial.printf("%d redes encontradas:\n", n);
        for (int i = 0; i < n; ++i) {
            Serial.printf("%d: %s (%d dBm) %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Aberta" : "Protegida");
        }
    }
}

void loop() {}

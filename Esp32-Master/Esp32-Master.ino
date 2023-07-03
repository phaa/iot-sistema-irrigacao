#include <WiFi.h>
#include <PubSubClient.h>

// Pinos UART do Esp32
#define RXp2 16
#define TXp2 17

// Crendenciais Wifi
const char* ssid = "TUPI";
const char* password = "12345678";

// Dados MQTT
const char* mqttServer = "test.mosquitto.org";
const char* mqttClientId = "ifrn-estufas-esp32";

// Tópicos MQTT
const char* mqttTopics[] = { "esp32/placa/input" };
const uint8_t topicsCount = 1;

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

float temperature = 0;
float humidity = 0;

// LED Pin
const int ledPin = 4;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  //Serial.println(Serial2.readString());

  // Inicia Wifi
  setupWifi();

  // Inicia cliente MQTT
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);

  // Substituir por função
  pinMode(ledPin, OUTPUT);
}

void setupWifi() {
  delay(10);

  Serial.println();
  Serial.print("Conectando na rede ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Intensidade do sinal: ");
  Serial.println(WiFi.RSSI());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Chegou uma mensagem no tópico: ");
  Serial.print(topic);
  Serial.print(". Mensagem: ");

  // Monta uma string com os bytes recebidos
  String messageTemp;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  //String topicName = String(topic);
  if (String(topic) == mqttTopics[0]) {
    //Serial.print("Changing output to ");
    Serial2.println(messageTemp);
    /* if (messageTemp == "on") {
      Serial2.println("HIGH:13");
    } else if (messageTemp == "off") {
      Serial2.println("LOW:13");
    } */
  }
}

void reconnect() {
  // Espera até reconectar
  while (!client.connected()) {
    Serial.print("Carregando conexão MQTT...");
    // Tenta conectar
    if (client.connect(mqttClientId)) {
      Serial.println("conectado");
      // Se inscreve novamente
      for (uint8_t i = 0; i < topicsCount; i++) {
        client.subscribe(mqttTopics[i]);
        Serial.print("Inscrito no tópico: ");
        Serial.println(mqttTopics[i]);
      }

    } else {
      Serial.print("falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      // Espera 5s antes de tentar denovo
      delay(5000);
    }
  }
}
void loop() {
  // Verifica a conexão
  if (!client.connected()) {
    reconnect();
  }

  // Verifica e executa a callback do MQTT
  client.loop();

  // Delay não blocante de 5s
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    Serial.println("5s");
    //client.publish(mqttTopics[1], "teste");

  }
}
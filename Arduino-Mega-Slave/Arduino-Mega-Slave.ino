String inputString = "";
bool stringComplete = false;  // flag para indicar se a string está completa

void setup() {
  Serial.begin(9600);
  inputString.reserve(20); // reserva 20 bytes para a string de comando
  pinMode(13, OUTPUT);
  Serial.println("Pronto!");
  // os pinos digitais serão setados a medida que formos precisando deles no projeto
}

void loop() {
  commitCmdString();
}

void commitCmdString() {
  if (stringComplete) {
    parseCmdString();
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void parseCmdString() {
  // exemplo do comando:
  // A:15 leitura analógica da porta 15
  // HIGH:2 ligar pino 2
  // LOW:2 desligar pino 3
  uint8_t cmdIndex = inputString.indexOf(":");
  String cmd = inputString.substring(0, cmdIndex);
  uint8_t pin = inputString.substring(cmdIndex+1, inputString.length()).toInt();

  if(cmd.equals("A")) {
    // A0 = GPIO 54 e A15 = GPIO 69
    if(pin >= 54 && pin <= 69) {
      Serial.println(analogRead(pin));
    }
  } 
  else if(cmd.equals("LOW")) {
    digitalWrite(pin, LOW);
    Serial.println("ok");
  } 
  else if (cmd.equals("HIGH")) {
    digitalWrite(pin, HIGH);
    Serial.println("ok");
  }

  //Serial.println(cmd);
  //Serial.println(pin);
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    // se o caractere for uma quebra de linha, dizemos que a string está pronta  
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

String inputString = "";
bool stringComplete = false;  // flag para indicar se a string está completa

void setup() {
  Serial.begin(9600);
  inputString.reserve(200); // reserva 200 bytes para a string de comando

  // os pinos digitais serão setados a medida que formos precisando deles no projeto
}

void loop() {
  commitCmdString();
  
}

void commitCmdString() {
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void parseCmdString() {
  // exemplo do comando:
  // A:15 leitura analógica da porta 15
  // ON:2 ligar pino 2
  // OFF:2 desligar pino 3
  
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

# IoT Sistema de Irrigação Inteligente para Estufas

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa1.jpeg" title="Projeto na VI Secitex" width="500" />
</p>

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa2.jpeg" title="Projeto na VI Secitex" width="500" />
</p>

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa3.jpeg" title="Projeto na VI Secitex" width="500" />
</p>

## Apresentação

Este projeto nasceu durante a disciplina de Internet das Coisas (IoT) do curso de Tecnologia em Sistemas para Internet no Instituto Federal de Educação, Ciência e Tecnologia do Rio Grande do Norte (IFRN), *Campus* Currais Novos. Ele foi calorosamente recebido e reconhecido pela diretoria na VI Semana de Ciência, Tecnologia e Extensão (Secitex) do IFRN em 2023.

A motivação central deste projeto foi desenvolver um sistema de automação de baixo custo e acessível para estufas, direcionado especialmente a produtores familiares que enfrentam desafios na gestão de áreas de produção maiores. Nosso objetivo é capacitar esses produtores a aumentar significativamente sua produtividade através da otimização inteligente do uso de recursos, mantendo as plantações em condições ideais de temperatura e umidade do solo e do ar de forma constante.

## ⚙️ Implementação (Parte de IoT - Arduino)

Este repositório concentra-se na parte de IoT do projeto, especificamente nos códigos desenvolvidos para as plataformas Arduino. O sistema é composto por:

* **Placa Master ESP32:** Responsável pela lógica principal, comunicação Wi-Fi com a API e processamento dos dados devido ao seu dual-core. A comunicação com a API é realizada através do protocolo MQTT, onde dados dos sensores são enviados e comandos para os atuadores são recebidos.
* **Placa Slave Arduino Mega:** Utilizada para interfacear com um grande número de sensores e atuadores que operam em 5V, os quais não seriam diretamente compatíveis com os 3.3V do ESP32. A comunicação entre o ESP32 (master) e o Arduino Mega (slave) é estabelecida via Serial UART.

A API responsável pelo processamento dos dados e pela lógica de controle pode ser encontrada neste repositório: [https://github.com/phaa/api-sistema-irrigacao](https://github.com/phaa/api-sistema-irrigacao)

### 📂 Organização das Pastas

1.  **`Esp32-Teste-Wifi`**: Contém os códigos dos testes iniciais realizados para estabelecer a conexão da placa ESP32 com a rede IoT do *campus*.
2.  **`Esp32-Master`**: Inclui o código principal rodando na placa ESP32, responsável pela comunicação MQTT e controle geral do sistema.
3.  **`Arduino-Mega-Slave`**: Apresenta o código para a placa Arduino Mega, gerenciando a leitura de sensores e o acionamento dos atuadores.

## 🚀 Próximos Passos e Melhorias Futuras

Este projeto demonstra um grande potencial, e algumas áreas para desenvolvimento futuro incluem:

* Implementação de um painel de controle web ou mobile para visualização dos dados e controle manual do sistema.
* Integração com serviços de previsão do tempo para ajustes proativos na irrigação.
* Utilização de aprendizado de máquina para otimizar ainda mais o uso da água e os parâmetros ambientais da estufa.
* Adição de suporte a mais tipos de sensores e atuadores.
* Criação de um guia de montagem e configuração do hardware para facilitar a replicação do projeto.

## 🧑‍💻 Desenvolvedor

[Pedro Henrique Amorim de Azevedo](https://github.com/phaa)

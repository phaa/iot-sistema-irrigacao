# Agrosoft - Greenhouse IoT Irrigation System

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa1.jpeg" title="Project at VI Secitex" width="500" />
</p>

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa2.jpeg" title="Project at VI Secitex" width="500" />
</p>

<p align="center">
  <img src="https://github.com/phaa/iot-sistema-irrigacao/blob/main/estufa3.jpeg" title="Project at VI Secitex" width="500" />
</p>

## Presentation

This project originated during the Internet of Things (IoT) course of the Internet Systems Technology program at the Federal Institute of Education, Science and Technology of Rio Grande do Norte (IFRN), *Campus* Currais Novos. It was warmly received and recognized by the board at the VI Science, Technology and Extension Week (Secitex) of IFRN in 2023.

The central motivation behind this project was to develop a low-cost and accessible automation system for greenhouses, specifically aimed at family farmers who face challenges in managing larger production areas. Our goal is to empower these producers to significantly increase their productivity through the intelligent optimization of resource use, constantly maintaining crops in ideal temperature and soil/air humidity conditions.

## ⚙️ Implementation (IoT Part - Arduino)

This repository focuses on the IoT part of the project, specifically the code developed for the Arduino platforms. The system is composed of:

* **ESP32 Master Board:** Responsible for the main logic, Wi-Fi communication with the API, and data processing due to its dual-core. Communication with the API is done via the MQTT protocol, where sensor data is sent and actuator commands are received.
* **Arduino Mega Slave Board:** Used to interface with a large number of 5V sensors and actuators, which would not be directly compatible with the ESP32's 3.3V. Communication between the ESP32 (master) and the Arduino Mega (slave) is established via Serial UART.

The API responsible for data processing and control logic can be found in this repository: [https://github.com/phaa/api-sistema-irrigacao](https://github.com/phaa/api-sistema-irrigacao)

### 📂 Folder Organization

1.  **`Esp32-Teste-Wifi`**: Contains the code for the initial tests carried out to establish the ESP32 board's connection with the campus IoT network.
2.  **`Esp32-Master`**: Includes the main code running on the ESP32 board, responsible for MQTT communication and overall system control.
3.  **`Arduino-Mega-Slave`**: Presents the code for the Arduino Mega board, managing sensor readings and actuator activation.

## 🚀 Next Steps and Future Improvements

This project demonstrates great potential, and some areas for future development include:

* Implementation of a web or mobile control panel for data visualization and manual system control.
* Integration with weather forecast services for proactive irrigation adjustments.
* Use of machine learning to further optimize water usage and greenhouse environmental parameters.
* Addition of support for more types of sensors and actuators.
* Creation of a hardware assembly and configuration guide to facilitate project replication.

## 🧑‍💻 Developer

[Pedro Henrique Amorim de Azevedo](https://github.com/phaa)

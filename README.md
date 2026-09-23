# 🛡️ Guardian Care Autonomous Safety Network

An IoT-based autonomous safety monitoring system designed to detect unauthorized movement in restricted areas and provide immediate alerts using **NodeMCU ESP8266, PIR sensor, buzzer, LED, and Blynk IoT**.

## 📌 Project Overview

**Guardian Care Autonomous Safety Network** is a smart security and monitoring system that continuously monitors a restricted area for human movement.

When the PIR sensor detects motion, the NodeMCU ESP8266 processes the sensor input and activates a local **buzzer and LED alert**. The system can also communicate with the **Blynk IoT platform** through Wi-Fi, allowing the user to monitor the system remotely.

## 🎯 Objectives

* Detect human movement in restricted areas.
* Provide immediate local alerts using a buzzer and LED.
* Enable remote monitoring through Blynk IoT.
* Reduce the need for continuous manual monitoring.
* Provide an IoT-based approach to safety and security monitoring.

## ⚙️ Features

* 🔍 Real-time motion detection
* 🚨 Buzzer alert for detected movement
* 💡 LED status indication
* 📱 Blynk IoT monitoring
* 📶 Wi-Fi connectivity
* 🔄 Automatic system operation
* 🛡️ Restricted-area safety monitoring

## 🧰 Hardware Requirements

* NodeMCU ESP8266
* PIR Motion Sensor
* Buzzer
* LED
* Resistor
* Jumper Wires
* Breadboard
* USB Cable / 5V Power Supply
* Wi-Fi Network

## 💻 Software Requirements

* Arduino IDE
* ESP8266 Board Package
* Blynk IoT
* Blynk Library
* Windows / Linux / macOS
* Blynk Mobile Application

## 🔌 Circuit Connections

| Component      | NodeMCU Pin |
| -------------- | ----------- |
| PIR Sensor OUT | D5          |
| Buzzer         | D6          |
| LED            | D7          |
| PIR VCC        | 3.3V        |
| PIR GND        | GND         |
| Buzzer GND     | GND         |
| LED GND        | GND         |

> **Note:** Check your specific components and module voltage requirements before making the connections.

## 🔄 Working Principle

```text
PIR Sensor
     ↓
Motion Detected
     ↓
NodeMCU ESP8266
     ↓
 ┌───────────────┐
 ↓               ↓
Buzzer + LED   Wi-Fi
                 ↓
             Blynk IoT
                 ↓
          Remote Monitoring
```

### Working Steps

1. The PIR sensor continuously monitors the restricted area.
2. When human movement is detected, the sensor sends a signal to the NodeMCU.
3. The NodeMCU processes the sensor signal.
4. The buzzer and LED are activated as a local warning.
5. The system sends the motion status to Blynk through Wi-Fi.
6. The user can monitor the system remotely using the Blynk application.
7. After the alert period, the local buzzer and LED return to their normal state.

## 📱 Blynk IoT

The project uses Blynk IoT for remote monitoring.

Suggested virtual pins:

| Virtual Pin | Purpose       |
| ----------- | ------------- |
| V0          | Motion Status |
| V1          | System Status |
| V2          | Motion Count  |

You can customize the Blynk dashboard according to your requirements.

## 📂 Project Structure

```text
Guardian-Care-Autonomous-Safety-Network/
│
├── GuardianCare/
│   └── GuardianCare.ino
│
├── images/
│   ├── circuit-diagram.png
│   ├── project-setup.jpg
│   └── blynk-dashboard.jpg
│
├── README.md
└── LICENSE
```

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/Guardian-Care-Autonomous-Safety-Network.git
```

### 2. Open the Code

Open:

```text
GuardianCare.ino
```

using Arduino IDE.

### 3. Install Required Libraries

Install:

* ESP8266 Board Package
* Blynk Library

### 4. Configure Wi-Fi

Update the Wi-Fi credentials in the code:

```cpp
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

### 5. Configure Blynk

Add your Blynk credentials:

```cpp
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Guardian Care"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
```

### 6. Select Board

In Arduino IDE:

```text
Tools → Board → ESP8266 Boards → NodeMCU 1.0 (ESP-12E Module)
```

### 7. Upload

Connect the NodeMCU to your computer using a USB cable and upload the program.

## 🔮 Future Enhancements

* Multiple PIR sensor support
* Mobile push notifications
* Email alerts
* Cloud-based event logging
* Camera integration
* Additional environmental sensors
* Improved remote monitoring dashboard
* Data analytics and activity history


## 👩‍💻 Project Information

**Project Name:** Guardian Care Autonomous Safety Network
**Domain:** IoT & Embedded Systems
**Platform:** NodeMCU ESP8266
**Programming:** Arduino / Embedded C++
**IoT Platform:** Blynk IoT
**Sensor:** PIR Motion Sensor

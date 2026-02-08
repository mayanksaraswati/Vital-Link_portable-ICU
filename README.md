🏥 ICU Patient Monitoring System (ESP32-S3)

A real-time Smart ICU Monitoring System using ESP32-S3, integrating multiple biomedical sensors to continuously monitor patient vitals and environmental conditions, and display them on a TFT dashboard with alert mechanisms.

📌 Project Overview

In Intensive Care Units (ICUs), continuous monitoring of patient vitals is critical. Manual monitoring increases workload and risks delayed response during emergencies.

This project provides a low-cost, real-time ICU monitoring solution that:

Continuously tracks patient vitals

Detects abnormal conditions automatically

Displays all data on a centralized dashboard

Triggers alerts using buzzer and LEDs

🔧 System Architecture

Master ESP32-S3 (Dashboard Unit)

TFT Display (ICU Dashboard)

MPU6050 (Fall detection)

ECG Sensor

GPS (Patient location)

UART communication with Slave ESP32

Slave ESP32 (Sensor Unit)

MAX30102 (Heart Rate & SpO₂)

DHT11 (Room Temperature & Humidity)

Buzzer & Alert LEDs

Sends processed data to Master ESP32

🧠 Features

❤️ Heart Rate Monitoring

🫁 SpO₂ Monitoring

🌡️ Room Temperature Monitoring

💧 Humidity Monitoring

📉 ECG Signal Reading

🤕 Fall Detection using MPU6050

📍 Patient Location (GPS)

🚨 Automatic Alert System

🖥️ Real-time ICU Dashboard

🔄 Master–Slave ESP32 Communication

📊 Display Output (TFT Dashboard)
ICU MONITORING SYSTEM
ESP32-S3 | PATIENT
---------------------------
MPU X: 0.15        HR: 72
MPU Y: 1.02        SpO2: 98
MPU Z: 0.10        Room T: 26.5
Fall: NO           Hum: 55%
ECG: 1987          Status: OK
Lat: 18.5204       Buzzer: OFF
Lon: 73.8567

🔌 Hardware Components
Component	Purpose
ESP32-S3	Main controller & TFT dashboard
ESP32	Sensor processing (slave)
MAX30102	Heart rate & SpO₂
DHT11	Temperature & humidity
MPU6050	Fall detection
ECG Sensor	ECG signal
GPS Module	Location tracking
ILI9341 TFT	ICU display
Buzzer	Emergency alert
LEDs	Status indication
🛠️ Software & Libraries

Arduino IDE

LovyanGFX (TFT)

Wire.h (I2C)

MAX30105 Library

DHT Sensor Library

ESP32 HardwareSerial

📂 Repository Structure
ICU-Monitoring-System/
│
├── ESP32_S3_ICU_Dashboard/
│   └── icu_dashboard_s3.ino
│
├── Slave_ESP32_MAX30102/
│   └── slave_max30102.ino
│
├── README.md

⚠️ Alert Logic
Condition	Status
Temp ≥ 39°C OR SpO₂ < 90 OR Fall Detected	DANGER
Temp ≥ 37.5°C	ALERT
Normal vitals	OK

Buzzer ON during DANGER

Alert LED ON

Dashboard updates in real time

🚀 Applications

ICU patient monitoring

Remote healthcare systems

Smart hospitals

Elderly care systems

Post-surgery monitoring

🔮 Future Enhancements

Cloud integration (Firebase / ThingsBoard)

Mobile app for doctors

ECG waveform plotting

AI-based health prediction

Secure patient data storage

👨‍💻 Developed By

Mayank Saraswati
Electronics / Embedded Systems
ESP32 • IoT • Healthcare Tech

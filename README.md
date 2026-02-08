# Vital-Link_portable-ICU
“Smart ICU Patient Monitoring System with AI-based risk prediction for remote villages and defence (army) areas.”

# 🏥 Portable ICU Monitoring System

A **real-time, portable ICU monitoring system** built using **ESP32** and biomedical sensors to continuously monitor a patient’s vital signs.  
This project is designed for **hospitals, emergency response units, defense medical support, and remote healthcare** where continuous monitoring is critical.

---

## 📌 Project Overview

The **Portable ICU Monitoring System** measures and displays essential physiological parameters in real time, helping doctors and caregivers make faster and more accurate decisions.

The system integrates multiple sensors with an ESP32 microcontroller and sends live data to a dashboard/mobile app for remote monitoring and alerts.

---

## 🔍 Features

- ❤️ **Heart Rate (HR) Monitoring**
- 🩸 **SpO₂ (Blood Oxygen Level) Measurement**
- 🫀 **ECG Signal Acquisition & Visualization**
- 🌡️ **Body / Room Temperature Monitoring**
- 🚶 **Fall Detection using MPU6050**
- 📍 **GPS-based Patient Location Tracking**
- 🚨 **Emergency Alerts (LED / Buzzer)**
- 📊 **Real-Time Dashboard Visualization**
- 🤖 **AI-based Heart Attack Risk Prediction (Planned / Integrated)**
- 📱 **Cloud & Mobile App Support (Blynk / Web Dashboard)**

---

## 🛠️ Hardware Components

- **ESP32 / ESP32-S3**
- **MAX30102** – Heart Rate & SpO₂ Sensor
- **ECG Sensor Module** (AD8232 or equivalent)
- **MPU6050** – Accelerometer & Gyroscope (Fall Detection)
- **Temperature Sensor** (LM35 / DS18B20)
- **GPS Module (NEO-6M)**
- **Buzzer**
- **Alert LEDs**
- Jumper Wires & Breadboard
- Power Supply / Battery Pack

---

## 🔌 Sensor Connections (Example)

| Sensor | ESP32 Pins |
|------|-----------|
| MAX30102 SDA | GPIO 21 |
| MAX30102 SCL | GPIO 22 |
| MPU6050 SDA | GPIO 21 |
| MPU6050 SCL | GPIO 22 |
| ECG Output | Analog Pin |
| GPS TX | RX Pin |
| GPS RX | TX Pin |
| Buzzer | Digital GPIO |
| LEDs | Digital GPIO |

> ⚠️ **Note:** All sensor grounds must be connected to **ESP32 GND**.

---

## 🧠 AI & Prediction Module

- Uses **Machine Learning (Random Forest)** to analyze:
  - Heart Rate
  - ECG patterns
  - SpO₂ levels
- Predicts **possible heart attack risk**
- Designed for **early warning**, not as a replacement for medical diagnosis

---

## 📊 Dashboard & Visualization

- Live ECG waveform
- Real-time vitals update
- Patient status (Normal / Warning / Critical)
- Location tracking via GPS
- Alerts displayed on dashboard & mobile app

Supported platforms:
- **Blynk App**
- **Web Dashboard**
- **Serial Monitor (Debugging)**

---

## 🚑 Use Cases

- ICU & Hospital Patient Monitoring
- Ambulance & Emergency Services
- Remote Healthcare & Telemedicine
- Defense & Military Medical Units
- Elderly Care & Home Monitoring

---

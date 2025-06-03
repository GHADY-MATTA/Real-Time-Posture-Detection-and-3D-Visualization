# 🚀 Posture Tracker 3D — MPU6050 + Arduino + Processing Visualization

![Platform](https://img.shields.io/badge/platform-Arduino%20%7C%20Processing-blue.svg)
![Language](https://img.shields.io/badge/language-C++%20%7C%20Java-orange)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-Completed-brightgreen)

> A full-stack hardware-software project that combines embedded motion sensing with real-time 3D visualization and posture analysis using **MPU6050**, **Arduino**, and **Processing**.

---

## 📸 Demo Preview

*Live 3D visualization with posture classification (healthy/unhealthy) and animated model rotation based on real quaternion data.*

## 📸 Demo Preview

![MPU6050 Posture Tracker Demo](mpu-working.gif)


## 🧠 Key Features

✅ **Real-Time Motion Tracking** with MPU6050 DMP  
✅ **Serial Communication Protocol** with 14-byte Teapot Packets  
✅ **Live Quaternion-Based 3D Rendering**  
✅ **Posture Classification Engine**  
✅ **Custom OpenGL Models (Wings, Fins, Cylinders)**  
✅ **Textual HUD Feedback on Axis States**  
✅ **Failsafe Serial Sync & Restart Resilience**

---

## 🛠️ Tech Stack

| Layer             | Tech Used                             |
|-------------------|----------------------------------------|
| 👾 Microcontroller | Arduino UNO + MPU6050 IMU             |
| 🔌 Communication   | I2C + USB Serial                      |
| 🧠 Firmware        | C++ (I2Cdev + MPU6050 DMP6)           |
| 🖥️ Host GUI        | Processing (Java) + Toxiclibs         |
| 📐 Graphics        | OpenGL Renderer + Quaternion Rotation |
| 📝 Visual Feedback | Dynamic Text Labels + Model State     |

---

## 🧰 Setup Instructions

### 🔧 Arduino Side (Firmware)

1. Wire your **MPU6050 to Arduino** as follows:

| MPU6050 | Arduino UNO |
|---------|-------------|
| VCC     | 3.3V        |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |
| INT     | D2          |

2. Install required libraries:

```cpp
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

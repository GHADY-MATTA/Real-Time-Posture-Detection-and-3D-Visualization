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










💻 Processing Side (Visualization)
Download and install the Processing IDE

Add the following libraries using the Contribution Manager:

ToxiclibsSupport

processing.serial

Set the correct COM port in your sketch:



String portName = "COM3"; // Change this to match your Arduino port
Run the PostureTracker3D.pde sketch.

🎨 UI Breakdown
🧍 Orientation	📈 Axis Values Display	✅ Posture Status
Live 3D rotation	W, X, Y, Z shown in UI	Healthy/Unhealthy label based on thresholds

💡 How It Works
mermaid


graph LR
A[MPU6050 IMU] -->|I2C| B[Arduino UNO]
B -->|Teapot Packet| C[Processing App]
C --> D[Quaternion Parsing]
D --> E[OpenGL Render]
D --> F[Posture Logic]
E --> G[3D Visual Output]
F --> H[Posture Status Text]
🧪 Quaternion Parsing Example


q[0] = ((teapotPacket[2] << 8) | teapotPacket[3]) / 16384.0f;
q[1] = ((teapotPacket[4] << 8) | teapotPacket[5]) / 16384.0f;
q[2] = ((teapotPacket[6] << 8) | teapotPacket[7]) / 16384.0f;
q[3] = ((teapotPacket[8] << 8) | teapotPacket[9]) / 16384.0f;
quat.set(q[0], q[1], q[2], q[3]);
🩻 Posture Detection Logic

if (axis[0] >= -2 && axis[0] <= 1 &&
    axis[1] >= 0.9 && axis[1] <= 2.0 &&
    axis[2] >= 0.1 && axis[2] <= 0.2 &&
    axis[3] >= -3 && axis[3] <= 1) {
    text("Healthy posture", 20, 100);
} else {
    text("Unhealthy posture", 20, 120);
}
📦 File Structure
objectivec
Copy
Edit
posture-tracker-3d/
├── arduino/
│   └── MPU6050_DMP6.ino
├── processing/
│   └── PostureTracker3D.pde
├── assets/
│   └── demo.gif
└── README.md
📌 Applications
🎓 IMU/Quaternion Learning Tools

🛠️ Rapid IoT/Embedded Prototyping

💺 Ergonomics & Posture Monitoring

🤖 Robotics Orientation Modules

🤝 Contributions
Want to improve posture logic or add dashboard support?
Pull Requests & Issues are welcome.

📃 License
This project is released under the MIT License.
Use it freely in personal, educational, or commercial projects.


#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

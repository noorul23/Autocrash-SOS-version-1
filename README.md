# 🚗 AutoCrash SOS – Version 1 (Internship Project)

AutoCrash SOS Version 1 was developed during my IoT internship as a prototype accident detection and emergency alert system.

This version focuses on real-time accident notification using:
- ESP32 microcontroller  
- SIM800L GSM module  
- Collision switch (YL-99 switch trigger)  
- MIT App Inventor mobile application (for GPS data)

---

## 📌 Internship Context

This project was developed during my IoT internship in 2024.  

Due to malfunction of a dedicated GPS module during development, mobile GPS was used as a workaround. The mobile application transmitted GPS coordinates to the ESP32 via Bluetooth.

This version represents the **original internship implementation**.

---

## ⚙️ System Overview

### Working Flow

1. Mobile app retrieves phone GPS coordinates.
2. GPS data is sent to ESP32 via Bluetooth.
3. A collision switch (YL-99) simulates accident detection.
4. Upon trigger:
   - Buzzer activates
   - ESP32 sends SMS via SIM800L
   - SMS contains GPS coordinates (Google Maps link format)

---

## 🧩 Hardware Components

- ESP32 Development Board  
- SIM800L GSM Module  
- Collision Switch (YL-99)  
- Buzzer  
- 18650 Battery & External Power Supply  

Circuit diagram available in `/hardware`.

---

## 📱 Mobile Application (MIT App Inventor)

- Driver-side app retrieves GPS coordinates
- Sends latitude and longitude via Bluetooth
- Simple interface for GPS data transmission

Screenshots available in `/images`.

> Note: `.aia` source file is not available. Only screenshots are provided.

---

## 🚨 Accident Detection Mechanism

- YL-99 switch used as collision switch
- Acts as simulation for accident event
- On press:
  - Buzzer sounds
  - SMS alert sent to predefined contact

This version does **not** use inspired airbag-based triggering.

---

## 📂 Repository Structure

- `firmware/` – ESP32 source code  
- `hardware/` – Circuit and architecture diagrams  
- `images/` – Output screenshots and prototype images  
- `presentation/` – Internship PPT  
- `report/` – Official internship report  

---

## ⚠️ Limitations (Version 1)

- Relied on mobile GPS instead of dedicated GPS module  
- Trigger mechanism was a simple YL-99 collision switch  
- SMS delivery depends on GSM network strength  
- No real impact sensor or airbag-style trigger  

---

## 🔄 Project Evolution

After the internship, the system was independently redesigned and enhanced in **Version 2**, which includes:

- Hardware-based collision triggering inspired by real airbag mechanism  
- Improved physical deployment mechanism  
- Multi-recipient SMS and call alerts  

(See Version 2 repository for enhanced system.)

---

## 📜 License

MIT License

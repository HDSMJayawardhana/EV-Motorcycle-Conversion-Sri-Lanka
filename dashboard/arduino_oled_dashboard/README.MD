# 🖥️ Custom EV Dashboard

Custom digital dashboard for the converted CT100 EV motorcycle,
developed using Arduino Nano and OLED display.

---

## 🔗 Live Simulation

> 🎮 **Try it now:** [Wokwi Simulation](https://wokwi.com/projects/437040105929841665)

---

## 📁 Folder Structure

```
dashboard/
└── arduino_oled_dashboard/
    └── dashboard.ino        ← Main Arduino source code
```

---

## 🔧 Hardware Components

| Component | Specification | Purpose |
|-----------|---------------|---------|
| Arduino Nano | ATmega328P | Main microcontroller |
| OLED Display | 0.96" SSD1306, I2C | Visual display |
| Voltage Divider | R1=9kΩ, R2=1kΩ | Battery voltage reading |
| NTC Thermistor | 10kΩ at 25°C | Motor temperature |
| Hall Effect Sensor | Digital output | Speed measurement |
| Push Button | Tactile switch | Mode selection |

---

## 📊 Display Information

| Parameter | Source | Unit |
|-----------|--------|------|
| Speed | Hall effect sensor (interrupt) | km/h |
| Battery Voltage | Voltage divider → A0 | V |
| Battery Percentage | Calculated (39V–54.6V range) | % |
| Motor Temperature | NTC Thermistor → A1 | °C |
| Riding Mode | Button press (ECO/NORMAL/SPORT) | — |

---

## 🔌 Wiring Diagram

```
Arduino Nano
├── A0 ──── Voltage Divider  (Battery +48V → 0-5V)
├── A1 ──── NTC Thermistor   (Motor temperature)
├── D2 ──── Hall Effect Sensor (Speed pulse - INT0)
├── D3 ──── Mode Button      (INPUT_PULLUP)
├── A4 ──── OLED SDA         (I2C Data)
└── A5 ──── OLED SCL         (I2C Clock)
```

---

## 📦 Required Libraries

Install these in Arduino IDE → **Tools → Manage Libraries:**

```
Adafruit SSD1306   (version 2.5.x)
Adafruit GFX       (version 1.11.x)
Wire               (built-in)
```

---

## 🚀 How to Upload

1. Open `arduino_oled_dashboard/dashboard.ino` in Arduino IDE
2. Install required libraries
3. Select Board: **Arduino Nano**
4. Select Processor: **ATmega328P (Old Bootloader)**
5. Select Port: **COMx** (Windows) or **/dev/ttyUSBx** (Linux)
6. Click **Upload** ▶️

---

## 📱 Display Layout

```
┌──────────────────────────────┐
│  CT100 EV       Mode: ECO    │
├──────────────────────────────┤
│       35        V: 47.2V     │
│      km/h       T: 42.5C     │
├──────────────────────────────┤
│  BAT: 78%  [████████░░]      │
│                              │
│   H.D.S.M. Jayawardhana      │
└──────────────────────────────┘
```

---

*Arduino Nano + SSD1306 OLED | ME420 | University of Peradeniya | 2025*

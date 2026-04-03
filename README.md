# ⚡ Feasibility Study and Implementation of EV Conversions for Motorcycles in Sri Lanka

![Status](https://img.shields.io/badge/Status-Prototype_Phase-yellow)
![Year](https://img.shields.io/badge/Year-2025-blue)
![University](https://img.shields.io/badge/University-Peradeniya-orange)
![License](https://img.shields.io/badge/License-MIT-green)
![Motor](https://img.shields.io/badge/Motor-1000W_BLDC-red)
![Vehicle](https://img.shields.io/badge/Prototype-Bajaj_CT100-purple)

> **ME420 – Final Year Individual Research Project** | BSc (Hons) Mechanical Engineering | University of Peradeniya
> In collaboration with **Ceylon Electricity Board (CEB)**

---

## 📌 Problem Statement

Sri Lanka faces rising fuel costs, increased emissions, and limited affordable green mobility options. Motorcycles dominate the personal transport sector, making them ideal candidates for low-cost EV conversion. This project explores converting the widely-used **Bajaj CT100** from ICE to electric propulsion, balancing **cost, weight, and energy efficiency** for the Sri Lankan market.

---

## 🎯 Objectives

- Conduct a market survey to understand rider preferences and fuel consumption patterns
- Design a complete electric propulsion retrofit system for the Bajaj CT100
- Perform motor selection, battery sizing, and weight balancing calculations
- Develop a custom digital dashboard and mobile app interface
- Deliver a validated techno-economic model proving financial viability
- Explore an innovative plug-in hybrid concept

---

## 🔧 System Architecture

```
┌─────────────────────────────────────────────────────┐
│            EV CONVERSION SYSTEM (48V)                │
├─────────────────────────────────────────────────────┤
│                                                      │
│  ┌──────────┐    ┌──────────────┐    ┌────────────┐ │
│  │ Battery  │───▶│    Motor     │───▶│ Rear Wheel │ │
│  │  Pack    │    │  Controller  │    │ (Hub Motor)│ │
│  │(48V,40Ah)│    │  (1000W)     │    │  1000W     │ │
│  └──────────┘    └──────────────┘    └────────────┘ │
│       │                │                             │
│       ▼                ▼                             │
│  ┌──────────┐    ┌──────────────┐    ┌────────────┐ │
│  │   BMS    │    │  3-Speed     │    │  Dashboard │ │
│  │          │    │  Throttle    │    │  (OLED)    │ │
│  └──────────┘    └──────────────┘    └────────────┘ │
│       │                                              │
│       ▼                                              │
│  ┌──────────┐    ┌──────────────┐                   │
│  │  DC-DC   │    │  Mobile App  │                   │
│  │ Converter│    │ (Bluetooth)  │                   │
│  │(48V→12V) │    │              │                   │
│  └──────────┘    └──────────────┘                   │
└─────────────────────────────────────────────────────┘
```

---

## 🏍️ Prototype Vehicle — Bajaj CT100

The **Bajaj CT100** was selected based on RMV data and survey results due to:

- ✅ Highest market penetration in Sri Lanka
- ✅ Lightweight chassis (109 kg curb weight)
- ✅ Simple drivetrain — easy mechanical disassembly
- ✅ Affordable spare parts and wide availability

### Original ICE Specifications

| Parameter | Value |
|-----------|-------|
| Engine | 4-Stroke, 97.2cc |
| Fuel Tank | 10.5 Litres |
| Mileage | ~65 km/l |
| Curb Weight | 109 kg |
| Top Speed | ~90 km/h |

---

## ⚙️ Motor & Drivetrain Specifications

| Parameter | Value |
|-----------|-------|
| Motor Model | MY1020 (HC Motor Co.) |
| Motor Type | Brushless DC (BLDC) |
| Voltage | 48V DC |
| Power | 1000W |
| Rated Speed | 3000 RPM |
| Rated Current | 26A |
| Max Speed (converted) | 40 km/h |
| Cruise Power | 774 W |
| Peak Power | 4.4 kW (during acceleration) |
| Wheel Torque (peak) | 116.7 Nm |
| Recommended Gear Ratio | ~6:1 |

---

## 🔋 Battery Pack Design (Future Phase)

| Parameter | Value |
|-----------|-------|
| Voltage | 48V |
| Capacity | 40 Ah (1.92 kWh) |
| Configuration | 13S15P Li-ion |
| Cell Voltage | 3.6V |
| Cell Capacity | 2.5 Ah |
| Energy per Cell | 9 Wh |
| Cell Mass | 45 g |
| Total Cells | 195 |
| Battery Mass | ~8.78 kg |
| Peak Current | 75A |
| Peak Power | 3.6 kW |
| Estimated Range | ~50 km (moderate speed) |

---

## 🔬 Vehicle Parameters & Force Analysis

### Input Parameters

| Parameter | Value |
|-----------|-------|
| Gross Vehicle Weight (GVW) | 150 kg (bike + rider) |
| Wheel Radius (r) | 0.345 m |
| Top Speed (V) | 40 km/h = 11.11 m/s |
| Drag Coefficient (Cd) | 0.9 |
| Frontal Area (A) | 0.8 m² |
| Air Density (ρ) | 1.2 kg/m³ |
| Rolling Resistance (Crr) | 0.004 |
| Motor Efficiency (η) | 85% |

### Forces on Flat Road

| Force | Formula | Value |
|-------|---------|-------|
| Rolling Resistance | F_r = Crr × m × g | **5.89 N** |
| Aerodynamic Drag | F_d = 0.5 × Cd × A × ρ × V² | **53.3 N** |
| Acceleration (0→40 km/h in 6s) | F_a = m × a | **277.5 N** |
| **Total Tractive Force** | **F_t = F_r + F_d + F_a** | **336.7 N** |

### Power Requirements

| Condition | Power | Status |
|-----------|-------|--------|
| Peak (during acceleration) | 4.4 kW | ⚠️ Brief burst only |
| Cruising at 40 km/h | 774 W | ✅ Within 1000W motor range |

### Torque Calculations

| Parameter | Value |
|-----------|-------|
| Wheel Torque (Peak) | T = 336.7 × 0.345 = **116.7 Nm** |
| Motor Torque Output | ~20 Nm |
| Required Gear Ratio | 116.7/20 ≈ **5.8 → Use 6:1** |

---

## ⚡ Power & Range Estimation

| Parameter | Calculation | Result |
|-----------|-------------|--------|
| Current Draw (full load) | I = 1000W / 48V | **20.83 A** |
| Battery Capacity (1hr full load) | 20.83A × 1h | **~21 Ah** |
| Effective Power (60% average) | 1000W × 0.6 | **600 W** |
| Battery Energy | 48V × 21Ah | **1008 Wh** |
| **Estimated Range** | **(1008/600) × 30 km/h** | **~50 km** |

---

## ⚖️ Weight Balancing Analysis

| Parameter | Value |
|-----------|-------|
| Front Weight | 144 kg |
| Rear Weight | 165 kg |
| Total Weight | 309 kg |
| Rear Distribution | 53.4% |
| Front Distribution | 46.6% |

> ✅ **Within safe riding limits** (40%–60% rear is acceptable for motorcycles)

---

## 💰 Cost-Benefit Analysis

### Monthly Operating Cost Comparison

| Category | ICE Motorcycle (LKR) | EV Motorcycle (LKR) |
|----------|---------------------|---------------------|
| Fuel / Charging | 7,000 | 1,000 |
| Maintenance | 2,000 | 500 |
| **Total** | **9,000** | **1,500** |

### Financial Summary

| Metric | Value |
|--------|-------|
| Monthly Savings | LKR 7,500 |
| Annual Savings | LKR 90,000 |
| Total Conversion Cost | LKR 184,500 |
| **Payback Period** | **~2 years (24.6 months)** |

> 💡 EV conversion becomes cost-effective in just over **2 years** through monthly savings on fuel and maintenance.

---

## 🔩 Conversion Kit — Bill of Materials

### 1. Main Conversion Kit

| Component | Specification | Cost (LKR) | Source |
|-----------|--------------|------------|--------|
| Hub Motor | 48V 1800W, 17" Alloy/Spoke | 65,000 | UBUY Sri Lanka |
| BLDC Controller | 48V, matched with motor | 9,000 | UBUY Sri Lanka |
| Li-ion Battery | 48V 60Ah (modular/custom) | 80,000 | Duino, Kandy |
| Throttle + Display + Key | 3-speed, digital meter | 6,000 | UBUY Sri Lanka |
| DC-DC Converter | 48V to 12V, 10A | 3,500 | Duino, Kandy |
| Anti-Theft Alarm | Remote + Siren | 1,700 | Duino, Kandy |
| MCB + Fuse Box | 48V Miniature Circuit Breaker | 1,500 | Duino, Kandy |
| Charging Cable | 3-pin input | 2,000 | Duino, Kandy |
| **Subtotal** | | **168,700** | |

### 2. Mechanical Fabrication & Mounting

| Item | Cost (LKR) |
|------|-----------|
| Battery Box (steel/aluminum) | 5,000 |
| Controller Mount (brackets + bolts) | 1,800 |
| Wiring and Connectors | 2,500 |
| Rubber Insulators | 1,000 |
| **Subtotal** | **10,300** |

### 3. Testing & Miscellaneous

| Item | Cost (LKR) |
|------|-----------|
| Basic Tools & Meters | 3,000 |
| Protective Gear | 1,000 |
| Miscellaneous | 1,500 |
| **Subtotal** | **5,500** |

### Total Budget

| Category | Cost (LKR) |
|----------|-----------|
| Main Conversion Kit | 168,700 |
| Mechanical Fabrication | 10,300 |
| Testing & Miscellaneous | 5,500 |
| **TOTAL** | **LKR 184,500** |

---

## 🖥️ Custom Digital Dashboard

A custom dashboard was developed using **Arduino Nano + 0.96" OLED Display (I2C)** for real-time monitoring:

### Features
- ⚡ Real-time voltage display
- 🏎️ Speed (km/h) — via Hall-effect sensor
- 🌡️ Motor temperature monitoring — via NTC thermistor
- 🔋 Battery state of charge
- 🎮 Riding mode indicator (Eco / Normal / Sport)

### Live Simulation
🔗 **Wokwi:** [https://wokwi.com/projects/437040105929841665](https://wokwi.com/projects/437040105929841665)

---

## 📱 Mobile Application Interface

A companion mobile app developed using **MIT App Inventor** with Bluetooth connectivity:

| Screen | Features |
|--------|----------|
| **Dashboard** | Battery %, Speed, Temperature, Mode, Alarms |
| **Trip Summary** | Distance, Time, Energy Used, Estimated Cost |
| **Settings** | Max Temperature, Speed Limit, Cost per kWh, Bluetooth Setup |
| **Alarm History** | Log of all triggered alarms with timestamps |

---

## 🔌 Plug-in Hybrid Concept (Ongoing Research)

An innovative concept exploring a **dual-mode motorcycle**:

- ⚡ **Electric Mode** — BLDC hub motor for city commuting
- ⛽ **Petrol Mode** — Original ICE engine for long-distance travel
- 🔄 **Switching** — Relay or clutch-based mechanical control

> ⚠️ Currently in **conceptual and design phase**

---

## 🧪 Prototype Testing Results (Without Battery)

Testing performed using a **48V DC lab power supply**:

| Test Parameter | Observation | Result |
|----------------|-------------|--------|
| Motor spin-up | Smooth, quick throttle response | ✅ Pass |
| Display meter | Functional — reads voltage and speed | ✅ Pass |
| Controller heating | Within safe limits (ambient temp) | ✅ Pass |
| Reverse throttle | Working as expected | ✅ Pass |
| RPM measurement | Verified using Echometer | ✅ Pass |

---

## 📋 Project Milestones

| # | Milestone | Status |
|---|-----------|--------|
| 1 | Survey and literature review | ✅ Completed |
| 2 | Cost and energy analysis | ✅ Completed |
| 3 | Motor and controller selection | ✅ Done |
| 4 | Kit procurement (university funds) | ✅ Done |
| 5 | SolidWorks prototype design | ✅ Done |
| 6 | Mobile app development | ✅ Done |
| 7 | Partial implementation (no battery) | ✅ Done |
| 8 | Dashboard simulation | ✅ Done |
| 9 | Plug-in hybrid research | ✅ Done |
| 10 | Battery purchase | ⏳ Budget limitation |
| 11 | Final prototype demo | 📅 University Exhibition |

---

## 🛠️ Implementation Challenges & Solutions

| Challenge | Solution |
|-----------|----------|
| Budget limitations | Used university cash advance; phased approach |
| No battery for testing | Used lab 48V DC power supply |
| Frame alignment with hub motor | Used adjustable spacers for swingarm |
| Dashboard design unfamiliarity | Used Wokwi simulation + Arduino guides |
| Component heating | Designed airflow slots in controller mounting |

---

## 📊 Survey Highlights (100+ Riders)

| Finding | Percentage |
|---------|-----------|
| Interested in EV conversion (if cost < LKR 150,000) | **78%** |
| Unaware of available conversion kits | **85%** |
| Concerned about battery replacement | **60%** |
| Support government incentives for conversions | **90%** |

> Survey conducted via Google Forms across Kandy, Gampaha, Colombo, and Kurunegala districts.

---

## 🛠️ Tools & Technologies

| Category | Tools |
|----------|-------|
| CAD/Design | SolidWorks 2022 |
| Simulation | Wokwi (Dashboard) |
| Embedded Systems | Arduino Nano, OLED Display (I2C) |
| Mobile App | MIT App Inventor |
| Analysis | MS Excel, MATLAB |
| Documentation | MS Office, LaTeX |
| Testing Equipment | Lab DC Power Supply, Echometer, Oscilloscope |

---

## 📂 Repository Structure

```
EV-Motorcycle-Conversion-Sri-Lanka/
│
├── README.md
├── LICENSE
│
├── docs/
│   ├── Final_Report.pdf
│   ├── Cost_Benefit_Analysis.pdf
│   ├── Vehicle_Specifications.pdf
│   ├── Force_Calculations.pdf
│   ├── Power_Range_Weight_Analysis.pdf
│   ├── Motor_Battery_Selection_Calculations.pdf
│   └── Project_Budget_Report.pdf
│
├── dashboard/
│   └── arduino_oled_dashboard/
│
├── analysis/
│   ├── handwritten_calculations/
│   └── typed_calculations/
│
├── images/
│   ├── prototype/
│   ├── cad_renders/
│   ├── dashboard/
│   ├── mobile_app/
│   └── testing/
│
└── survey/
    └── survey_results/
```

---

## 📚 Key References

1. Kumar et al. (2019) — Total cost of ownership study for electric motorcycles in India
2. Lopez et al. (2020) — Three-wheeler EV conversion pilot study, Philippines
3. Shivnay & Yadav (2021) — Design and Analysis of Electric Bike, IRJET
4. Santoso et al. (2024) — Conversion of motorcycles to electric vehicles, GJESM
5. NREL — BLDC hub motor studies for two-wheelers
6. Sri Lanka DMT — Vehicle registration statistics

---

## 🤝 Acknowledgments

- **Supervisor:** Ms. Lekha Bakmeedeniya — Dept. of Mechanical Engineering, UoP
- **Co-Supervisor:** Eng. Tharanga Wickramarathna — Project Manager, CEB
- **Department of Mechanical Engineering**, University of Peradeniya
- **Ceylon Electricity Board (CEB)** — Industry partner and data support
- University of Peradeniya — Cash advance funding support

---

## 👤 Author

**H. D. S. M. Jayawardhana (Salinda Madushan)**
- Registration: E/19/169
- Degree: BSc (Hons) Mechanical Engineering
- University: University of Peradeniya, Sri Lanka

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?style=flat&logo=linkedin&logoColor=white)](https://linkedin.com/in/h-d-s-m-jayawardhana)
[![Email](https://img.shields.io/badge/Email-Contact-D14836?style=flat&logo=gmail&logoColor=white)](mailto:salindamadushansalinda@gmail.com)
[![GitHub](https://img.shields.io/badge/GitHub-Salinda1999-181717?style=flat&logo=github&logoColor=white)](https://github.com/Salinda1999)

---

## 📝 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

> ⚠️ **Academic Disclaimer:** This report is submitted in partial fulfillment of the academic requirements for the Bachelor of Science in Engineering degree at the University of Peradeniya. All findings and conclusions are solely those of the author. The EV conversion activities were carried out in accordance with academic and safety guidelines. This content should not be replicated for commercial use without appropriate supervision or approvals.

---

*ME420 – Mechanical Engineering Individual Research Project | Department of Mechanical Engineering | Faculty of Engineering | University of Peradeniya | 2025*

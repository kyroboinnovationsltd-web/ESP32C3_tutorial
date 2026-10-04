# ESP32-C3 Beginner Tutorial Series

A hands-on, step-by-step project series for learning electronics and programming with the **ESP32-C3 SuperMini**, by **Kyrobo Innovations**.

Each project builds on the one before it, starting from blinking a single LED and moving up to sensors, sound and motion. Every project folder has its own **README**, **circuit diagram** and **Arduino code**.

---

## Who This Is For
- Students and beginners with **no prior experience** in electronics or coding
- Anyone who has an ESP32-C3 SuperMini and wants to learn by building
- Teachers looking for ready-made, classroom-friendly projects

---

## The Kit
All projects use only the parts in the Kyrobo ESP32-C3 starter kit.

| Component | Component |
|-----------|-----------|
| ESP32-C3 SuperMini | DHT11 Temperature & Humidity Sensor |
| Mini Breadboard | IR Sensor |
| Ultrasonic Sensor (HC-SR04) | Touch Sensor (TTP223) |
| SG90 Servo Motor | LDR (Light Sensor) |
| Potentiometer | Push Buttons (4 pcs) |
| LEDs (4 pcs – Red, Yellow, Green, Blue) | On/Off Switch |
| Resistor Set (330Ω and 1kΩ) | Sound Sensor |
| Jumper Wires | Passive Buzzer |

**Resistor guide used across the series**
| Use | Resistor |
|-----|----------|
| LEDs | 330Ω |
| Push buttons | 1kΩ |
| LDR voltage divider | 1kΩ |

---

## Getting Started
Do this once before starting Project 01.

📘 **New to Arduino IDE? Follow the full step-by-step guide: [GETTING-STARTED.md](GETTING-STARTED.md)**. It covers installing the IDE, adding ESP32 support, selecting the board and port, installing libraries and troubleshooting.

Quick summary:

1. Install the **[Arduino IDE](https://www.arduino.cc/en/software)**.
2. Open **Boards Manager**, search for **esp32**, and install **esp32 by Espressif Systems**.
3. Select **Tools → Board → ESP32C3 Dev Module**.
4. Set **Tools → USB CDC On Boot → Enabled**. Without this, the Serial Monitor shows nothing.
5. Connect the board with a **data** USB Type-C cable and select the correct **Port**.
6. Set the Serial Monitor baud rate to **115200**.

**If an upload fails:** hold the **BOOT** button, plug in the USB cable, release BOOT, then upload again.

---

## Projects

| # | Project | What You Learn | Main Parts |
|---|---------|----------------|------------|
| 01 | [Blink the Onboard LED](01-Onboard-led-blink) | Arduino IDE setup, `digitalWrite()`, `delay()`, active-low LEDs | Board only |
| 02 | [Traffic Light](02-traffic-light) | External LEDs, resistors, writing your own function | 3 LEDs |
| 03 | [LED Chaser](03-LED-chaser) | Arrays and `for` loops | 4 LEDs |
| 04 | [Push Button LED](04-push-button-LED) | Digital input, `INPUT_PULLUP`, toggling, debouncing | Button, LED |
| 05 | [Four-Button LED Controller](05-Four-Button-LED-Controller) | Multiple inputs and outputs with arrays | 4 buttons, 4 LEDs |
| 06 | [LED Dimmer](06-LED-dimmer) | Analog input, `map()`, PWM with `analogWrite()` | Potentiometer, LED |
| 07 | [Doorbell](07-Doorbell) | Sound with `tone()` and `noTone()` | Button, passive buzzer |
| 08 | [Touch Lamp](08-Touch-lamp) | Sensor modules, `INPUT` vs `INPUT_PULLUP` | Touch sensor, LED |
| 09 | [Automatic Night Light](09-Night-light) | LDR, voltage dividers, thresholds, hysteresis | LDR, LED |
| 10 | [Temperature & Humidity Monitor](10-Temperature-humidity-monitor) | Installing libraries, `float`, `isnan()` | DHT11, LED |

### Coming Soon
| # | Project | Main Parts |
|---|---------|------------|
| 11 | Parking Sensor | Ultrasonic sensor, buzzer |
| 12 | Distance Meter with LED Bar Graph | Ultrasonic sensor, 4 LEDs |
| 13 | Clap Switch | Sound sensor, LED |
| 14 | Object Counter / Intruder Alarm | IR sensor, buzzer |
| 15 | Mini Piano | 4 buttons, buzzer |
| 16 | Servo Sweep | Servo |
| 17 | Knob-Controlled Servo | Potentiometer, servo |
| 18 | Automatic Dustbin Lid | Ultrasonic sensor, servo |
| 19 | Touch-to-Open Door Lock | Touch sensor, servo, buzzer |
| 20 | Simple Sun Tracker | LDR, servo |
| 21–25 | WiFi Projects: web-controlled LEDs, weather dashboard, servo controller, smart room monitor, security alarm | Various |

---

## Folder Structure
Each project folder follows the same layout:

```
01-Onboard-led-blink/
├── 01-Onboard-led-blink.ino     ← Arduino code
├── README.md                    ← Explanation, wiring and troubleshooting
└── circuit-diagram.png          ← Wiring diagram
```

To open a project in Arduino IDE, download or clone this repo and open the `.ino` file inside the project folder.

---

## ESP32-C3 SuperMini – Things to Know
- **Onboard LED** is on **GPIO8** and is **active-low** (`LOW` = ON).
- **Analog pins** are **GPIO0 – GPIO4**. Only these can use `analogRead()`.
- **Boot pins:** avoid **GPIO2, GPIO8 and GPIO9** for buttons and sensors. If an upload fails, unplug anything connected to them.
- **Power sensors from 3.3V, not 5V.** The ESP32-C3's pins only accept up to 3.3V.
- **No built-in touch pins and no DAC**, unlike the original ESP32.
- **Bluetooth Low Energy (BLE) only.** Classic Bluetooth (`BluetoothSerial`) is not supported.

---

## Common Problems
| Problem | Fix |
|---------|-----|
| Upload fails | Hold **BOOT**, plug in USB, release BOOT, then upload |
| Nothing in the Serial Monitor | Set **USB CDC On Boot → Enabled** and baud rate to **115200** |
| `xxx.h: No such file or directory` | Install the missing library from the **Library Manager** |
| LED doesn't light | Flip it around: long leg (+) faces the GPIO side |
| Board not detected | Use a **data** USB cable, not a charge-only cable |

---

## About Kyrobo Innovations
**Kyrobo Innovations Ltd** works in embedded systems, robotics and IoT, with a focus on hands-on learning through its EdTech wing and Arduino and IoT kits.

Found a mistake or have a suggestion? Open an **Issue** in this repository.

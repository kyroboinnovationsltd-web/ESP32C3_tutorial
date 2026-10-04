# Project 10 – Temperature & Humidity Monitor (ESP32-C3 SuperMini)

The tenth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
A DHT11 sensor measures the room's temperature and humidity and prints them to the Serial Monitor. A red warning LED turns on when it gets too hot.

## What You Will Learn
- How the **DHT11** temperature and humidity sensor works
- Installing and using an Arduino **library**
- Working with decimal numbers using `float`
- Detecting failed sensor readings with `isnan()`
- Triggering a warning when a value crosses a limit

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| DHT11 Temperature & Humidity Sensor (3-pin module) | 1 |
| LED (Red) | 1 |
| Resistor 330Ω (for LED) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| DHT11 VCC (+) | 3.3V |
| DHT11 DATA (S / OUT) | GPIO7 |
| DHT11 GND (−) | GND |
| LED long leg (+) | GPIO5 via 330Ω resistor |
| LED short leg (−) | GND |

> **Tip:** The 3-pin DHT11 module has a pull-up resistor built in, so no extra resistor is needed.
> **Check the pin labels printed on your module.** The pin order is different between makers.

## Install the Library First
This is the first project in the series that needs a library. Without it you'll get the error **`DHT.h: No such file or directory`**.

1. In Arduino IDE, click the **Library Manager** icon on the left sidebar, or go to **Sketch → Include Library → Manage Libraries…**
2. Search for **DHT sensor library**.
3. Install **DHT sensor library by Adafruit**.
4. When asked to install dependencies (**Adafruit Unified Sensor**), click **Install All**.
5. If the error still appears, close and reopen Arduino IDE.

## How It Works
- The DHT11 has a small chip inside that measures temperature and humidity and sends the result to the ESP32 as **digital data over a single wire**.
- The **DHT library** handles that communication, so reading the sensor takes just one line: `dht.readTemperature()` or `dht.readHumidity()`.
- The readings are **`float`** numbers, which can have decimals (like 28.0), unlike the `int` whole numbers used in earlier projects.
- If the sensor isn't connected properly, the library returns **NaN** ("not a number"). `isnan()` catches this, prints a helpful message, and skips the rest of the loop.
- The DHT11 is a slow sensor and can only be read about **once every 2 seconds**, so the code waits 2 seconds between readings.
- If the temperature goes above `TEMP_LIMIT` (32°C), the red LED turns on as a warning.

## About the DHT11
| Measurement | Range | Accuracy |
|-------------|-------|----------|
| Temperature | 0 – 50°C | ±2°C |
| Humidity | 20 – 90% | ±5% |

It's great for a room monitor, but not for precise measurements.

## Troubleshooting
- **`DHT.h: No such file or directory`:** The library isn't installed. Follow the steps in *Install the Library First*.
- **"Failed to read from DHT11 sensor!":** Check the wiring against the labels on your module, and make sure DATA is on GPIO7.
- **Readings never change:** Wait at least 2 seconds between readings, and check that `DHT_TYPE` is set to `DHT11`.
- **Warning LED never turns on:** Lower `TEMP_LIMIT` to a value just above your room temperature to test it.
- **LED doesn't light:** Flip it around (long leg to the GPIO side) and check its resistor.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- **Test it:** hold the sensor between your fingers or breathe on it gently and watch the temperature and humidity rise.
- **Fahrenheit:** use `dht.readTemperature(true)` to show °F as well.
- **Comfort indicator:** green LED when comfortable, yellow when warm, red when hot, using the traffic light from Project 02.
- **Heat alarm:** beep the buzzer from Project 07 when the temperature crosses the limit.

---
**Previous:** Project 09 – Automatic Night Light
**Next:** Project 11 – Parking Sensor (Ultrasonic)

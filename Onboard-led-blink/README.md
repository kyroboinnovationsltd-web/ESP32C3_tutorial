# Project 01 – Blink the Onboard LED (ESP32-C3 SuperMini)

The first project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
You will make the small LED built into the ESP32-C3 SuperMini blink on and off every second.

## What You Will Learn
- Setting up the Arduino IDE for the ESP32-C3
- Using `pinMode()`, `digitalWrite()` and `delay()`
- Printing messages to the Serial Monitor
- What an **active-low** LED is

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| USB Type-C cable (data) | 1 |

No wiring needed. The LED is already on the board (GPIO8).

## Setup
1. Install the **Arduino IDE**.
2. Open **Boards Manager**, search for **esp32** and install *esp32 by Espressif Systems*.
3. Select **Tools → Board → ESP32C3 Dev Module**.
4. Set **Tools → USB CDC On Boot → Enabled** (needed for the Serial Monitor).
5. Select the correct **Port**.

## How It Works
The onboard LED is **active-low**. Writing `LOW` to GPIO8 turns the LED **ON**, and writing `HIGH` turns it **OFF**.
`delay(1000)` pauses the program for 1 second between each change.

## Troubleshooting
- **Upload fails:** Hold the **BOOT** button, plug in the USB cable, release BOOT, then upload again.
- **Nothing in the Serial Monitor:** Check that *USB CDC On Boot* is **Enabled** and the baud rate is **115200**.
- **LED doesn't blink:** Some board versions use a different pin. Try `#define LED_PIN 2`.

## Try It Yourself
- Change the delay to `200` for fast blinking.
- Blink **SOS** in Morse code: 3 short, 3 long, 3 short.

---
**Next:** Project 02 – Traffic Light

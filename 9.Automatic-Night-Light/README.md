# Project 09 – Automatic Night Light (ESP32-C3 SuperMini)

The ninth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
The LED turns on by itself when the room gets dark and turns off again when it gets bright, just like a real automatic night light.

## What You Will Learn
- How an **LDR (light-dependent resistor)** senses light
- Building a **voltage divider** with an LDR and a resistor
- Reading light levels with `analogRead()`
- Making decisions with **thresholds**
- Using **hysteresis** to stop the light from flickering

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| LDR (Light Sensor) | 1 |
| Resistor 1kΩ (for LDR) | 1 |
| LED (Red) | 1 |
| Resistor 330Ω (for LED) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| LDR, one leg | 3.3V |
| LDR, other leg | GPIO1, and one end of the 1kΩ resistor |
| 1kΩ resistor, other end | GND |
| LED long leg (+) | GPIO5 via 330Ω resistor |
| LED short leg (−) | GND |

> **Tip:** The LDR has no + or − side, so it can go either way round.
> Use **3.3V, not 5V**. The LDR must connect to **GPIO0–GPIO4**, the only pins on the ESP32-C3 that can read analog values.

## How It Works
- An **LDR** changes its resistance with light. In bright light its resistance is low, and in the dark it becomes very high.
- The LDR and the 1kΩ resistor form a **voltage divider**, just like the potentiometer in Project 06. GPIO1 reads the voltage at the point where they meet.
- In **bright light** the voltage rises, giving a **high** reading. In the **dark** it falls, giving a **low** reading.
- The code uses **two thresholds**: the light turns **on** below `DARK_LEVEL` (150) and only turns **off** above `LIGHT_LEVEL` (250).
- This gap is called **hysteresis**. Without it, the LED would flicker on and off at dusk, when the light level hovers around a single value.
- The `lightOn` variable remembers the current state, so a message prints only when the light actually changes.

## Calibrating for Your Room
Every room and every LDR is different, so set the thresholds before using the project:
1. Upload the code and open the Serial Monitor at **115200** baud.
2. Note the **Light level** in normal room light.
3. Cover the LDR with your finger and note the new value.
4. Set `DARK_LEVEL` a little above the covered value.
5. Set `LIGHT_LEVEL` about 100 higher than `DARK_LEVEL`.

**Example:** room light reads 450 and covered reads 40, so use `DARK_LEVEL = 100` and `LIGHT_LEVEL = 200`.

## Troubleshooting
- **Reading is always 0:** Check that the LDR's top leg is on 3.3V and that GPIO1 connects to the middle point between the LDR and the 1kΩ resistor.
- **Reading is always very high:** The LDR and the 1kΩ resistor may be swapped. The LDR goes to 3.3V and the resistor goes to GND.
- **Readings are very low even in room light:** Put 2 or 3 of the 1kΩ resistors in series (end to end) in place of the single 1kΩ to make the sensor more sensitive.
- **Light never turns on or off:** Recalibrate `DARK_LEVEL` and `LIGHT_LEVEL` using the steps above.
- **LED flickers at dusk:** Increase the gap between `DARK_LEVEL` and `LIGHT_LEVEL`.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- **Smooth night light:** the darker it gets, the brighter the LED glows. Use `map()` and `analogWrite()` from Project 06.
- **Remove the hysteresis:** set both thresholds to the same number and slowly cover the LDR. Watch the flicker.
- **Sunrise alarm:** play a tune on the buzzer from Project 07 when it gets bright.

---
**Previous:** Project 08 – Touch Lamp
**Next:** Project 10 – Temperature & Humidity Monitor (DHT11)

# Project 06 – LED Dimmer (ESP32-C3 SuperMini)

The sixth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Turn the potentiometer knob to make an LED smoothly brighter or dimmer. This is your first project that reads an **analog** value.

## What You Will Learn
- How a potentiometer works as a **voltage divider**
- Reading analog values with `analogRead()`
- Scaling numbers from one range to another with `map()`
- Controlling LED brightness with **PWM** using `analogWrite()`
- Watching live values in the **Serial Plotter**

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| Potentiometer (10kΩ) | 1 |
| LED (Red) | 1 |
| Resistor 220Ω or 330Ω (for LED) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| Potentiometer left pin | 3.3V |
| Potentiometer middle pin | GPIO0 |
| Potentiometer right pin | GND |
| LED long leg (+) | GPIO5 via resistor |
| LED short leg (−) | GND |

> **Important:** Connect the potentiometer to **3.3V, not 5V**. The ESP32-C3's pins only accept up to 3.3V, and 5V can damage the board.
> The middle pin must go to **GPIO0–GPIO4**. These are the only pins on the ESP32-C3 that can read analog values.

## The Two Steps
1. **Read the knob:** print the potentiometer value to the Serial Monitor and watch it change from 0 to 4095 as you turn the knob. Open **Tools → Serial Plotter** to see it as a live graph.
2. **Dim the LED (main project):** convert the knob value into a brightness level and send it to the LED.

## How It Works
- The potentiometer is a **voltage divider**. Turning the knob changes the voltage on its middle pin anywhere from 0V to 3.3V.
- `analogRead()` turns that voltage into a number from **0 to 4095**, because the ESP32 reads analog values with 12 bits.
- `map()` scales that number down to **0–255**, the range `analogWrite()` uses.
- `analogWrite()` uses **PWM (Pulse Width Modulation)**: it switches the LED on and off very fast. The longer it stays on in each cycle, the brighter the LED looks to our eyes.

## Troubleshooting
- **Value is always 0 or always 4095:** Check that the outer pins go to 3.3V and GND, and the middle pin goes to GPIO0.
- **Value jumps around a little:** This is normal electrical noise. Average several readings to smooth it out.
- **LED only turns fully on or off:** Make sure the LED is on GPIO5 and that you are using `analogWrite()`, not `digitalWrite()`.
- **`analogWrite` gives an error:** Update the **esp32** board package to the latest version in Boards Manager.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- **Reverse it:** make the LED get brighter when you turn the knob the other way. Hint: swap `0, 255` in `map()`.
- **Speed control:** use the knob to set the speed of the Project 03 LED chaser.
- **Bar graph:** light 1, 2, 3 or 4 LEDs depending on how far the knob is turned.

---
**Previous:** Project 05 – Four-Button LED Controller
**Next:** Project 07 – Doorbell (Button + Buzzer)

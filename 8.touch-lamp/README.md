# Project 08 – Touch Lamp (ESP32-C3 SuperMini)

The eighth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Tap the touch sensor to turn the LED on, and tap again to turn it off, just like a touch-controlled bedside lamp.

## What You Will Learn
- How a **touch sensor module** (TTP223) works
- Reading a sensor module that sends a ready-made **digital signal**
- The difference between `INPUT` and `INPUT_PULLUP`
- Toggling an output on the **moment of touch**

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| Touch Sensor Module (TTP223) | 1 |
| LED (Red) | 1 |
| Resistor 220Ω or 330Ω (for LED) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| Touch sensor VCC | 3.3V |
| Touch sensor GND | GND |
| Touch sensor SIG (I/O) | GPIO10 |
| LED long leg (+) | GPIO5 via resistor |
| LED short leg (−) | GND |

> **Important:** Power the touch sensor from **3.3V, not 5V**, so its signal is safe for the ESP32-C3.
> The LED wiring is the same as Project 04.

## Why We Use a Touch Module
The original ESP32 has built-in touch pins, but the **ESP32-C3 has none**. The TTP223 module does the touch detection itself and simply sends **HIGH** or **LOW** to the board, so any GPIO pin can read it.

## How It Works
- The TTP223 senses your finger through its touch pad. It outputs **HIGH** while you touch it and **LOW** when you don't.
- This is the **opposite of the button** in Project 04. The button read LOW when pressed because of `INPUT_PULLUP`, but the touch module sends HIGH when touched.
- The pin is set as `INPUT`, not `INPUT_PULLUP`, because the module drives the pin itself.
- The lamp toggles only at the **moment of touching** (LOW → HIGH), so keeping your finger on the pad doesn't make it flicker.
- The module gives a clean signal, so a short delay is enough. There's no need for the full debounce code from Project 04.

## Troubleshooting
- **Lamp doesn't respond:** Check that VCC is on 3.3V, GND on GND, and SIG on GPIO10.
- **Lamp toggles by itself:** Keep wires and fingers away from the pad while powering on. The module calibrates itself at power-up, so wait a second before touching.
- **LED stays on only while touching:** The **A** pad on the back of the module may be soldered, which changes its mode. Leave the A and B pads unsoldered.
- **LED doesn't light:** Flip it around (long leg to the GPIO side) and check its resistor.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- **Hold-to-light:** make the LED stay on only while you touch the pad.
- **Touch + sound:** add a short beep from the buzzer on every touch, using Project 07.
- **Brightness levels:** each tap moves through off → dim → medium → bright, using `analogWrite()` from Project 06.

---
**Previous:** Project 07 – Doorbell
**Next:** Project 09 – Automatic Night Light (LDR)

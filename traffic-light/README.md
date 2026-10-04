# Project 02 – Traffic Light (ESP32-C3 SuperMini)

The second project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
You will build a mini traffic signal using red, yellow and green LEDs that change in the same order as a real one.

## What You Will Learn
- Connecting external LEDs with resistors on a breadboard
- Controlling multiple GPIO pins
- Writing your own function (`setLights()`)
- The difference between **active-high** (external) and **active-low** (onboard) LEDs

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| LEDs (Red, Yellow, Green) | 3 |
| Resistors (220Ω or 330Ω) | 3 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| LED | Long leg (+) | Short leg (−) |
|-----|--------------|---------------|
| Red | GPIO4 via resistor | GND |
| Yellow | GPIO3 via resistor | GND |
| Green | GPIO2 via resistor | GND |

> **Tip:** The long leg of the LED is positive (+) and must face the GPIO side.

## How It Works
- **Red** stays on for 5 seconds (Stop).
- **Green** stays on for 5 seconds (Go).
- **Yellow** stays on for 2 seconds (Slow down), then the cycle repeats.

The `setLights()` function sets all three LEDs at once, so only one is ON at a time.
External LEDs are **active-high**: `HIGH` turns them ON. This is the opposite of the onboard LED from Project 01.

## Troubleshooting
- **LED doesn't light:** Flip it around. The long leg must connect to the GPIO side.
- **All LEDs very dim:** Check the resistor value. Use 220Ω–330Ω, not 10kΩ.
- **Board won't upload or start:** GPIO2 is a boot pin. Unplug the green LED wire while uploading, or move green to **GPIO5** and change `#define GREEN_LED 5`.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- Make the yellow LED **blink 3 times** before turning red.
- Add the blue LED as a **pedestrian signal** that turns on only while the light is red.
- Change the timings to match a real traffic signal near your school.

---
**Previous:** Project 01 – Blink the Onboard LED
**Next:** Project 03 – LED Chaser / Running Lights

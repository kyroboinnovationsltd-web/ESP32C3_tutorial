# Project 03 – LED Chaser / Running Lights (ESP32-C3 SuperMini)

The third project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Four LEDs light up one after another and bounce back, like the famous "Knight Rider" running lights.

## What You Will Learn
- Storing pin numbers in an **array**
- Using **for loops** to repeat actions
- Running a sequence forwards and backwards
- Controlling animation speed with a variable

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| LEDs (Red, Yellow, Green, Blue) | 4 |
| Resistors (220Ω or 330Ω) | 4 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| LED | Long leg (+) | Short leg (−) |
|-----|--------------|---------------|
| LED 1 (Red) | GPIO4 via resistor | GND |
| LED 2 (Yellow) | GPIO3 via resistor | GND |
| LED 3 (Green) | GPIO2 via resistor | GND |
| LED 4 (Blue) | GPIO5 via resistor | GND |

> **Tip:** Place the LEDs in a straight line in this order so the running effect is easy to see.
> This is the same wiring as Project 02, with one extra LED on GPIO5.

## How It Works
- `ledPins[]` is an **array**, a list that holds all four pin numbers. `ledPins[0]` is the first LED, `ledPins[3]` the last.
- The first **for loop** counts up (0 → 3) and lights each LED briefly, moving the light forward.
- The second loop counts down (2 → 1) so the light bounces back without blinking the end LEDs twice.
- The `speed` variable sets how long each LED stays on. Change it in one place to speed up the whole effect.

## Troubleshooting
- **One LED doesn't light:** Flip it around (long leg to the GPIO side) and check its resistor.
- **Lights run in the wrong order:** Rearrange the LEDs on the breadboard, or change the order of numbers in `ledPins[]`.
- **Board won't upload or start:** GPIO2 is a boot pin. Unplug the LED 3 wire while uploading.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- Make **all LEDs blink together** 3 times after each run.
- **Fill-up effect:** turn the LEDs on one by one and keep them on, then turn them off one by one.
- Try different `speed` values like `50` and `500`. Which looks best?

---
**Previous:** Project 02 – Traffic Light
**Next:** Project 04 – Push Button LED

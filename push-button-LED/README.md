# Project 04 – Push Button LED (ESP32-C3 SuperMini)

The fourth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Press a button to turn an LED on, and press it again to turn it off. This is your first project that **reads an input**.

## What You Will Learn
- Reading a button with `digitalRead()`
- Using the ESP32's internal pull-up resistor (`INPUT_PULLUP`)
- Detecting a single press and toggling a state
- **Debouncing** a button with `millis()`

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| Push Button | 1 |
| LED (Red) | 1 |
| Resistor 220Ω or 330Ω (for LED) | 1 |
| Resistor 1kΩ (for button) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| LED long leg (+) | GPIO5 via resistor |
| LED short leg (−) | GND |
| Button, one leg | GPIO10 via 1kΩ resistor |
| Button, diagonally opposite leg | GND |


> **Tip:** Place the button across the middle gap of the breadboard and use **diagonal legs**. The two sides then connect only when the button is pressed.
> The 1kΩ resistor protects the GPIO pin if it is ever set as an output by mistake. The code still uses the ESP32's internal pull-up, so no other resistor is needed.

## Step 1 – Hold to Light 
## Step 2 – Press to Toggle 
## How It Works
- **INPUT_PULLUP** keeps the button pin HIGH. Pressing the button connects it to GND, so it reads **LOW**.
- The code reacts only at the **moment of pressing** (HIGH → LOW), not while the button is held. One press means one toggle.
- `ledState = !ledState` flips the state: on becomes off, and off becomes on.
- **Debouncing:** a button "bounces" for a few milliseconds when pressed, which can look like many presses. `millis()` ignores any extra presses within 50 ms.

## Troubleshooting
- **LED is always on or always off:** Check that the button uses diagonal legs, so it isn't permanently connected.
- **Button doesn't respond:** Check the button resistor is 1kΩ, not 10kΩ or higher. A large resistor stops the pin reading LOW.
- **LED toggles twice or misses presses:** Increase `debounceDelay` to `100`.
- **LED doesn't light:** Flip it around (long leg to the GPIO side) and check its resistor.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- Remove the debounce check and press quickly. Does the LED sometimes miss or double-toggle?
- **Counter:** print how many times the button has been pressed.
- **Mode button:** each press moves to the next LED (red → yellow → green → blue) using the array from Project 03.

---
**Previous:** Project 03 – LED Chaser / Running Lights
**Next:** Project 05 – Four-Button LED Controller

# Project 05 – Four-Button LED Controller (ESP32-C3 SuperMini)

The fifth project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Four buttons each control their own LED: press a button to turn its LED on, and press it again to turn it off.
This project combines the **arrays** from Project 03 with the **button toggle** from Project 04.

## What You Will Learn
- Handling **multiple inputs and outputs** at the same time
- Pairing buttons and LEDs using matching **array indexes**
- Keeping a separate state for each button with arrays
- Reusing the toggle and debounce logic inside a **for loop**

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| LEDs (Red, Yellow, Green, Blue) | 4 |
| Push Buttons | 4 |
| Resistors 220Ω or 330Ω (for LEDs) | 4 |
| Resistors 1kΩ (for buttons) | 4 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
**LEDs** (same as Project 03)

| LED | Long leg (+) | Short leg (−) |
|-----|--------------|---------------|
| Red | GPIO4 via 220Ω resistor | GND |
| Yellow | GPIO3 via 220Ω resistor | GND |
| Green | GPIO2 via 220Ω resistor | GND |
| Blue | GPIO5 via 220Ω resistor | GND |

**Buttons**

| Button | One leg | Diagonally opposite leg | Controls |
|--------|---------|-------------------------|----------|
| Button 1 | GPIO0 via 1kΩ resistor | GND | Red LED |
| Button 2 | GPIO1 via 1kΩ resistor | GND | Yellow LED |
| Button 3 | GPIO6 via 1kΩ resistor | GND | Green LED |
| Button 4 | GPIO7 via 1kΩ resistor | GND | Blue LED |


> **Tip:** Keep your Project 03 LED wiring and just add the four buttons.
> Place each button across the middle gap of the breadboard and use **diagonal legs**.
> The 1kΩ resistors protect the GPIO pins. The code uses the internal pull-up, so no other resistor is needed.

## How It Works
- Each button and its LED share the same **index**: `buttonPins[0]` controls `ledPins[0]`, `buttonPins[1]` controls `ledPins[1]`, and so on.
- Every button needs its own memory of its LED state, last button state and last press time, so these are arrays too.
- The **for loop** checks all four buttons very quickly, again and again, so pressing any button feels instant.
- The toggle and debounce logic is exactly the same as Project 04, just repeated for each button.

## Troubleshooting
- **A button controls the wrong LED:** Check that the button is wired to the pin listed in the table, or swap the numbers in `buttonPins[]`.
- **A button doesn't respond:** Use diagonal legs, and check that its resistor is 1kΩ, not 10kΩ or higher.
- **An LED doesn't light:** Flip it around (long leg to the GPIO side) and check its resistor.
- **Board won't upload or start:** GPIO2 is a boot pin. Unplug the green LED wire while uploading.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- Make **Button 4** a master switch that turns all LEDs off at once.
- **Quiz buzzer game:** the first button pressed lights its LED and locks out the others until a reset.
- Print how many LEDs are on after every press.

---
**Previous:** Project 04 – Push Button LED
**Next:** Project 06 – LED Dimmer (Potentiometer)

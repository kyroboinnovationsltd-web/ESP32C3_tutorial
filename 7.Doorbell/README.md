# Project 07 – Doorbell (ESP32-C3 SuperMini)

The seventh project in the ESP32-C3 beginner series by **Kyrobo Innovations**.
Press the button and a passive buzzer plays a "ding-dong" tune, just like a real doorbell. This is your first project that makes **sound**.

## What You Will Learn
- How a **passive buzzer** makes sound
- Playing notes with `tone()` and stopping them with `noTone()`
- How **frequency** controls pitch
- Combining a button input with a sound output
- Putting a tune inside your own function (`playDoorbell()`)

## Components
| Component | Qty |
|-----------|-----|
| ESP32-C3 SuperMini | 1 |
| Push Button | 1 |
| Passive Buzzer | 1 |
| Resistor 1kΩ (for button) | 1 |
| Mini Breadboard | 1 |
| Jumper Wires | As needed |

## Wiring
| Part | Connection |
|------|------------|
| Button, one leg | GPIO10 via 1kΩ resistor |
| Button, diagonally opposite leg | GND |
| Buzzer (+) long leg | GPIO6 |
| Buzzer (−) short leg | GND |

> **Tip:** The button is wired the same way as Project 04.
> Look for the **+** mark on top of the buzzer so you connect it the right way round.

## How It Works
- A **passive buzzer** has no sound of its own. It only makes noise when the ESP32 sends it a fast on/off signal.
- `tone(pin, frequency)` sends that signal. A higher frequency gives a higher pitch: **659 Hz** is the note E ("ding") and **523 Hz** is the note C ("dong").
- `noTone()` stops the sound. Without it, the buzzer keeps beeping.
- The tune lives in its own function, `playDoorbell()`, so it can be played with one line whenever the button is pressed.
- The button logic is the same as Project 04: one press plays the tune once, however long you hold the button.

## Why `digitalWrite` Doesn't Work Here
A common beginner mistake is to use `digitalWrite(BUZZER_PIN, HIGH)` with a passive buzzer. It only makes a tiny click, because a passive buzzer needs a **changing** signal, not a steady one. That's why `tone()` is used.

## Troubleshooting
- **No sound at all:** Check the buzzer's + leg is on GPIO6 and the − leg is on GND. Try flipping it.
- **Only a click, no tune:** Make sure you are using `tone()`, not `digitalWrite()`.
- **Buzzer beeps but never stops:** Check that `noTone()` is called at the end of the tune.
- **Tune plays twice or keeps repeating:** Check the button uses diagonal legs, and that the debounce code is included.
- **`tone` gives an error:** Update the **esp32** board package to the latest version in Boards Manager.
- **Nothing in the Serial Monitor:** Set *USB CDC On Boot* to **Enabled** and the baud rate to **115200**.

## Try It Yourself
- **Three-note bell:** add a third note, like G5 (784 Hz).
- **Light and sound:** flash an LED while the bell plays.
- **Change the speed:** make the notes shorter or longer by changing the `delay()` values.

---
**Previous:** Project 06 – LED Dimmer
**Next:** Project 08 – Touch Lamp

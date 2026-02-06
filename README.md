# simonsays
simple memory game with esp32
ESP32 Simon Says Memory Game with Buzzer 🎮
4 LEDs, 4 Buttons, Piezo Buzzer - Test your memory!

🎯 Game Overview
Classic Simon Says memory game built with ESP32. The LEDs light up in a random sequence with unique tones. Repeat the sequence using the buttons. 5 difficulty levels with increasing speed - Level 5 is super fast & tricky!

📋 Features
5 Difficulty Levels (slow → lightning fast)
4 colored LEDs + 4 push buttons
Piezo buzzer with unique tones for each color
Level-up sounds & game over effects
No external libraries - pure Arduino code
Restart by pressing any button after game over

Level Timing (LED ON/OFF ms):
text
Level 1: 600/300ms (easy)
Level 2: 500/250ms  
Level 3: 400/200ms
Level 4: 300/150ms
Level 5: 200/100ms (VERY FAST!)

🛠️ Components Required

| Component          | Quantity | Notes                        |
| ------------------ | -------- | ---------------------------- |
| ESP32 Dev Board    | 1        | Any ESP32 works              |
| LEDs (any color)   | 4        | Different colors recommended |
| Push Buttons       | 4        | Tactile switches             |
| Piezo Buzzer       | 1        | Active or passive            |
| 220-330Ω Resistors | 4        | For LEDs                     |
| Jumper Wires       | 20+      | Male-female recommended      |
| Breadboard         | 1        | Full-size                    |

🔌 Circuit Diagram

| ESP32 Pin | Component | Connection |
|-----------|-----------|------------|
| GPIO4 | LED 0 | → LED+ → 220Ω → GND |
| GPIO5 | LED 1 | → LED+ → 220Ω → GND |
| GPIO18 | LED 2 | → LED+ → 220Ω → GND |
| GPIO19 | LED 3 | → LED+ → 220Ω → GND |
| GPIO12 | Button 0 | → Button → GND |
| GPIO13 | Button 1 | → Button → GND |
| GPIO14 | Button 2 | → Button → GND |
| GPIO15 | Button 3 | → Button → GND |
| GPIO2 | Buzzer | → Buzzer+ , Buzzer- → GND |
| GND | Common | All grounds together |

🎵 Sound Effects

| Event     | Tone Pattern                               |
| --------- | ------------------------------------------ |
| Each LED  | C4(262Hz), E4(330Hz), G4(392Hz), C5(523Hz) |
| Level Up  | Rising melody 800-1000Hz                   |
| Game Over | Descending buzz 200Hz                      |
| Startup   | C-E-G-C jingle                             |

Made with ❤️ for makers & students

[⭐ Star this repo if it helped you!]
Questions? Open an Issue

Level 5 is HARD - Can you beat it? 🧠💪
Happy Making! 🎮✨

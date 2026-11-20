# clock-alarm

This project builds an RTC (DS1302) powered alarm clock with Arduino UNO, a 16x2 LCD screen, a buzzer and three buttons.


<img width="2640" height="1640" alt="arduino-alarm-clock-wiring" src="https://github.com/user-attachments/assets/7dd256ce-2145-4493-ac4b-8b5590f75243" />






Subsystem 	Source Pin 	Destination Pin 	Wire Color 	Signal Purpose
Power & GND 	Arduino 5V 	+5V Power Rail 	Red 	Regulated +5V supply output feeding the main breadboard power rails.
Power & GND 	Arduino GND 	GND Rail (0V) 	Black 	Common ground reference connecting Arduino GND to top and bottom ground buses.
Power & GND 	+5V Power Rail 	LCD VDD (Pin 2) 	Red 	+5V logic power supply for the HD44780 LCD controller.
Power & GND 	GND Rail (0V) 	LCD VSS (Pin 1) 	Black 	Ground reference (0V) for the 16×2 LCD module.
Power & GND 	GND Rail (0V) 	LCD RW (Pin 5) 	Black 	Ties Read/Write (RW) LOW to keep the LCD permanently in Write mode.
Power & GND 	GND Rail (0V) 	LCD K / LED- (Pin 16) 	Black 	Ground cathode return for the LCD LED backlight.
Power & GND 	+5V Power Rail 	220Ω Resistor → LCD A (Pin 15) 	Red 	+5V backlight supply routed through a 220Ω current-limiting resistor to LCD Anode (A).
Power & GND 	+5V Power Rail 	10kΩ Potentiometer (Pin 1) 	Red 	+5V high-side reference for the LCD contrast voltage divider.
Power & GND 	GND Rail (0V) 	10kΩ Potentiometer (Pin 3) 	Black 	Ground low-side reference for the LCD contrast voltage divider.
Power & GND 	+5V Bottom Rail 	DS1302 RTC VCC 	Red 	+5V primary supply for the DS1302 real-time clock module.
Power & GND 	GND Bottom Rail 	DS1302 RTC GND 	Black 	Ground connection for the DS1302 real-time clock module.
Power & GND 	Piezo Buzzer (-) 	GND Bottom Rail 	Black 	Ground return path for the piezo alarm buzzer.
Power & GND 	Btn 1: Config GND 	GND Bottom Rail 	Black 	Pulls Arduino D6 LOW when Config button is pressed (INPUT_PULLUP active-low).
Power & GND 	Btn 2: Inc/Stop GND 	GND Bottom Rail 	Black 	Pulls Arduino D7 LOW when Increment/Stop button is pressed.
Power & GND 	Btn 3: Select GND 	GND Bottom Rail 	Black 	Pulls Arduino D8 LOW when Select Field button is pressed.
16×2 LCD 	10kΩ Pot Wiper 	LCD V0 (Pin 3) 	Gray 	Variable contrast voltage (0V–5V) controlling LCD pixel darkness.
16×2 LCD 	Arduino D12 	LCD RS (Pin 4) 	Blue 	Register Select: LOW for LCD commands, HIGH for character data.
16×2 LCD 	Arduino D11 	LCD EN (Pin 6) 	Cyan 	Enable clock pulse latching 4-bit nibbles into the LCD controller.
16×2 LCD 	Arduino D5 	LCD D4 (Pin 11) 	Green 	4-bit parallel data bus line D4 (LSB of upper nibble).
16×2 LCD 	Arduino D4 	LCD D5 (Pin 12) 	Yellow-Green 	4-bit parallel data bus line D5.
16×2 LCD 	Arduino D3 	LCD D6 (Pin 13) 	Orange 	4-bit parallel data bus line D6.
16×2 LCD 	Arduino D2 	LCD D7 (Pin 14) 	Purple 	4-bit parallel data bus line D7 (MSB).
DS1302 RTC 	Arduino D13 	DS1302 RST (CE) 	Magenta 	Chip Enable / Reset line initiating serial burst transfers with DS1302.
DS1302 RTC 	Arduino A4 	DS1302 DAT (I/O) 	Indigo 	Bidirectional synchronous serial data pin (used as digital I/O).
DS1302 RTC 	Arduino A5 	DS1302 CLK (SCLK) 	Teal 	Serial clock signal synchronizing bit shifts between Arduino and DS1302.
Buttons & Buzzer 	Arduino D9 	Piezo Buzzer (+) 	Amber 	Square-wave tone() output pulsing at 100ms intervals when alarm triggers.
Buttons & Buzzer 	Arduino D8 	Btn 3: Select (D8) 	Lime 	Cycles active alarm edit field between Hours (0), Minutes (1), and Seconds (2).
Buttons & Buzzer 	Arduino D7 	Btn 2: Inc / Stop (D7) 	Sky Blue 	Silences ringing buzzer or increments the selected alarm time unit.
Buttons & Buzzer 	Arduino D6 	Btn 1: Config (D6) 	Pink 	Toggles alarm configuration mode (displays CNF indicator on top-right of LCD).

**BLE Keyboard with ESP32 and RGB LED**

This project demonstrates how to use the ESP32 as a Bluetooth Low Energy (BLE) keyboard. The ESP32 is connected to five push buttons, each mapped to specific keyboard keys, and an RGB LED that visually indicates the Bluetooth connection status and button presses.

**Features**

Simulates a BLE keyboard using the BleKeyboard library.

Controls an RGB LED to indicate the Bluetooth connection status:

**Red LED:** Blinks when Bluetooth is not connected.

**Green LED:** Lights up briefly upon connection.

**Blue LED:** Lights up when a button is pressed.

Five buttons are mapped to simulate keyboard actions:

**Up Arrow**

**Down Arrow**

**Left Arrow**

**Right Arrow**

**Page Up**

**Hardware Requirements**

ESP32 Development Board.

RGB LED

Five Push Buttons

Resistors (10kΩ recommended for buttons)

Connecting wires and breadboard

**Circuit Diagram**

**RGB LED Pins:**

Red → GPIO 2

Green → GPIO 15

Blue → GPIO 4

**Button Pins:**

Up → GPIO 13

Down → GPIO 26

Left → GPIO 12

Right → GPIO 27

Center → GPIO 14

*Connect all button pins to GPIOs with pull-up configuration and one leg to the ground.*


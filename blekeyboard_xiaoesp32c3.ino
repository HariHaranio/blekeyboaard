// Include BLE Mouse library for "XIAO ESP32C3" board
#include <BleKeyboard.h>

// RBG led pin definition
#define G D7 // green led
#define R D8 // red led
#define B D9 // blue led

// definition for button connected to XIAO C3
#define U_BUT D0 // to move upward
#define L_BUT D1 // to move left
#define C_BUT D2 // center button
#define R_BUT D3 // to move right
#define D_BUT D4  // to move downward


// BLEKEBOARD gloal declaration
BleKeyboard bleKeyboard;

bool status = true;
void setup() {
  Serial.begin(115200);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(U_BUT, INPUT_PULLUP);
  pinMode(L_BUT, INPUT_PULLUP);
  pinMode(C_BUT, INPUT_PULLUP);
  pinMode(R_BUT, INPUT_PULLUP);
  pinMode(D_BUT, INPUT_PULLUP);
  bleKeyboard.begin();
}
// when bluetooth is not connected
void not_connected()
{
  digitalWrite(R, HIGH);
  delay(500);
  digitalWrite(R, LOW);
  delay(500);

  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  status = true;
}
// when bluetooth is connected and but is presses led
void but_pressed()
{
  digitalWrite(B, HIGH);
}
// to read button value and transmit data
void keyboardconnected() {
  if (digitalRead(U_BUT) == 0) {
    bleKeyboard.write(KEY_UP_ARROW);
    but_pressed();
    Serial.println("UP KEY PRESSED");
    delay(750);
  }
  if (digitalRead(D_BUT) == 0) {
    bleKeyboard.write(KEY_DOWN_ARROW);
    but_pressed();
    Serial.println("DOWN KEY PRESSED");
    delay(750);
  }
  if (digitalRead(L_BUT) == 0) {
    bleKeyboard.write(KEY_LEFT_ARROW);
    but_pressed();
    Serial.println("LEFT KEY PRESSED");
    delay(750);
  }
  if (digitalRead(R_BUT) == 0) {
    bleKeyboard.write(KEY_RIGHT_ARROW);
    but_pressed();
    Serial.println("RIGHT KEY PRESSED");
    delay(750);
  }
  if (digitalRead(C_BUT) == 0) {
    bleKeyboard.write(KEY_PAGE_UP);
    but_pressed();
    Serial.println("PAGE UP KEY PRESSED");
    delay(750);
  } else {
    digitalWrite(B, LOW);
  }
}
void loop() {
  if (bleKeyboard.isConnected()) {
    if (status == true) {
      digitalWrite(G,HIGH);
      delay(3000);
      status = false;
    }
    digitalWrite(G,LOW);
    keyboardconnected();
  } else {
    not_connected();
  }
}

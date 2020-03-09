#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int data, int iclock, int power, int count) {

    dataPin = data;

    clockPin = iclock;

    powerPin = power;

    pinCount = count;

    pinMode(data, OUTPUT);

    pinMode(iclock, OUTPUT);

    pinMode(power, OUTPUT);

    for (int i = 0; i < 100; i++) {
        pins[i] = false;
    }
}

void ShiftRegister::Write(int pin, bool power) {

    pins[pin] = power;

    UpdateRegister();

}

void ShiftRegister::UpdateRegister() {

    digitalWrite(powerPin, LOW);

    for (int i = pinCount; i > 0; i--) {

        digitalWrite(clockPin, LOW);

        if (pins[i]) {
            digitalWrite(dataPin, HIGH);
        }
        else {
            digitalWrite(dataPin, LOW);
        }

        digitalWrite(clockPin, HIGH);
    }

    digitalWrite(powerPin, HIGH);
}
#ifndef ShiftRegister_h
#define ShiftRegister_h
#include "Arduino.h"

class ShiftRegister {

private:

	int dataPin;

	int clockPin;

	int powerPin;

	int pinCount;

	bool pins[100];

public:

	ShiftRegister(int data, int iclock, int power, int count);

	void Write(int pin, bool power);

	void UpdateRegister();

};

#endif
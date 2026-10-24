const byte BUTTON_PINS[] = {2, 3, 4, 5, 6};
const byte BUTTON_COUNT = sizeof(BUTTON_PINS) / sizeof(BUTTON_PINS[0]);
int lastButtonState = -1;

void setup() {
	for (byte index = 0; index < BUTTON_COUNT; index++) {
		pinMode(BUTTON_PINS[index], INPUT_PULLUP);
	}
	Serial.begin(9600);
}

void loop() {
	int buttonState = 0;
	for (byte index = 0; index < BUTTON_COUNT; index++) {
		if (digitalRead(BUTTON_PINS[index]) == LOW) {
			buttonState = index + 1;
			break;
		}
	}

	if (buttonState != lastButtonState) {
		Serial.println(buttonState);
		lastButtonState = buttonState;
	}

	delay(10);
}

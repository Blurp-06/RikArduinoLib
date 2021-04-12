class btn {
    // For button press.
    int lastButtonState = LOW;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
    int buttonState;

    int btnPin;

  public:
    btn(int pinNumber) {
      this->btnPin = pinNumber;
      pinMode(pinNumber, INPUT);
    }

    bool btnPressed() {
      int reading = digitalRead(btnPin);
      if (reading != lastButtonState) {
        lastDebounceTime = millis();
        return true;
      }
      if ((millis() - lastDebounceTime) > debounceDelay) {
        return false;
      }

      // save the reading. Next time through the loop, it'll be the lastButtonState:
      lastButtonState = reading;
    }
};
// Pin Definitions
const int sensorPin = 2;        // Eye blink sensor
const int buzzerPin = 8;        // Buzzer
const int vibrationPin = 9;     // Vibration motor

// Timing variables
unsigned long eyeClosedTime = 0;
const unsigned long threshold = 3000;   // 3 seconds

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibrationPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(vibrationPin, LOW);
}

void loop()
{
  int eyeState = digitalRead(sensorPin);

  // Assuming LOW means eye closed (check your sensor)
  if (eyeState == LOW)
  {
    if (eyeClosedTime == 0)
    {
      eyeClosedTime = millis();   // Start timing
    }

    if (millis() - eyeClosedTime >= threshold)
    {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(vibrationPin, HIGH);
    }
  }
  else
  {
    // Eye opened → reset everything
    eyeClosedTime = 0;
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrationPin, LOW);
  }
}

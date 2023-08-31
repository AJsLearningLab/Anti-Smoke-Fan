// Initialize the pin where the smoke sensor is connected
int smoke = A5;

// Initialize the pin where the potentiometer is connected
int potPin = A4;

// Initialize the threshold value for the smoke sensor
int sensorThreshold = 325;

// Initialize the pin for the relay
int relayPin = 9;

// This function runs once when you turn on your Arduino or press the reset button.
void setup() {
  // Set the smoke sensor pin as an input pin
  pinMode(smoke, INPUT);

  // Set the relay pin as an output pin
  pinMode(relayPin, OUTPUT);

  // Start the serial communication with a baud rate of 9600
  Serial.begin(9600);
}

// This function runs repeatedly after the setup() function completes
void loop() {
  // Read the analog value from the smoke sensor pin
  int analogSensor = analogRead(smoke);

  // Read the raw analog value from the potentiometer
  int rawThreshold = analogRead(potPin);

  // Map the raw potentiometer value to a 0-500 range for the sensor threshold
  sensorThreshold = map(rawThreshold, 0, 1023, 0, 500);

  // Print the sensor value to the serial monitor for debugging
  Serial.print("Pin A5: ");
  Serial.println(analogSensor);

  // Print the threshold value to the serial monitor for debugging
  Serial.print("Threshold: ");
  Serial.println(sensorThreshold);

  // Check if the sensor value has exceeded the threshold
  if (analogSensor > sensorThreshold) {
    // If it has, turn the relay ON by setting the pin HIGH
    digitalWrite(relayPin, HIGH);
  } else {
    // If not, turn the relay OFF by setting the pin LOW
    digitalWrite(relayPin, LOW);
  }

  // Wait for 1 second before reading the sensor again
  delay(1000);
}

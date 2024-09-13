const int ldrPin = 4;  // Digital output from LDR module
const int ledPin = 2;  // LED connected to D4 (GPIO 2)

void setup() {
  pinMode(ldrPin, INPUT);  // Set LDR pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Initialize serial communication
}

void loop() {
  int ldrValue = 0;
  // Read the digital value from the LDR sensor
  ldrValue = digitalRead(ldrPin);
  
  // Print the LDR value to the Serial Monitor
  Serial.print("LDR Digital Value: ");
  Serial.println(ldrValue);

  // Invert the logic
  if (ldrValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on LED when light is LOW
    Serial.println("LED ON (Low light detected)");
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED when light is HIGH
    Serial.println("LED OFF (Sufficient light detected)");
  }
  
  delay(1000);  // Wait for 1 second before reading again
}

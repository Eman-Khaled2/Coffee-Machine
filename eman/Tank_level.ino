
void ultra1(){
  digitalWrite(TRIGGER_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_1, LOW);

  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration_1 = pulseIn(ECHO_PIN_1, HIGH);

  // Calculating the distance
  distance_1 = duration_1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
Serial.print("distance_1");
Serial.println(distance_1);
  delay(1000); // Wait for 1 second to get the next reading
}

void ultra2(){
  // Sets the TRIGGER_PIN on HIGH state for 10 micro seconds
  digitalWrite(TRIGGER_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_2, LOW);

  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration_2 = pulseIn(ECHO_PIN_2, HIGH);

  // Calculating the distance
  distance_2 = duration_2 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
Serial.print("distance_2");
Serial.println(distance_2);

  delay(1000); // Wait for 1 second to get the next reading
}


// PIN CONFIGURATION
const int LASER_PIN = 13;      // Built-in LED or Laser module
const int MOTOR_LEFT_PIN = 5;  // PWM Pin
const int MOTOR_RIGHT_PIN = 6; // PWM Pin

// Variables
String inputString = "";
bool stringComplete = false;

void setup() {
  // Initialize Serial
  Serial.begin(115200);
  inputString.reserve(200);

  // Initialize Pins
  pinMode(LASER_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);

  // Safety: Everything OFF at startup
  digitalWrite(LASER_PIN, LOW);
  analogWrite(MOTOR_LEFT_PIN, 0);
  analogWrite(MOTOR_RIGHT_PIN, 0);
}

void loop() {
  // Check if a full command has arrived
  if (stringComplete) {
    processCommand(inputString);
    
    // Reset buffer
    inputString = "";
    stringComplete = false;
  }
}

// Interrupt-like function for reading Serial
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

void processCommand(String command) {
  command.trim(); // Remove whitespace/newlines

  if (command == "FIRE") {
    // Fire laser logic
    Serial.println("DEBUG: Firing Laser");
    digitalWrite(LASER_PIN, HIGH);
    delay(1000); // Fire for 1 second
    digitalWrite(LASER_PIN, LOW);
  }
  else if (command == "FORWARD") {
    analogWrite(MOTOR_LEFT_PIN, 150);
    analogWrite(MOTOR_RIGHT_PIN, 150);
  }
  else if (command == "STOP") {
    analogWrite(MOTOR_LEFT_PIN, 0);
    analogWrite(MOTOR_RIGHT_PIN, 0);
  }
}

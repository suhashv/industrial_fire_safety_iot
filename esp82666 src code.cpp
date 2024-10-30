#include <Servo.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Define the flame sensor, gas sensor, motion sensor, and LED pins
#define FLAME_SENSOR_PIN 5           // D1 is GPIO5
#define GAS_SENSOR_ANALOG_PIN A0     // Analog pin for the gas sensor
#define SERVO_PIN 2                  // D4 is GPIO2
#define MOTION_SENSOR_PIN 14         // D5 is GPIO14 for motion sensor
#define LED_PIN 4                    // D2 is GPIO4 for LED

// Wi-Fi credentials
#define WIFI_SSID "dhanush"
#define WIFI_PASSWORD "12345678"

// Firebase credentials
#define FIREBASE_HOST "https://industrialfiresafety123-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "2Psq57lJfOIKI6bv6KV1PWW6RuT8NCsyJafXYxH0"

// Create a servo object
Servo ventilationServo;

// Create Firebase objects
FirebaseData firebaseData;
FirebaseConfig firebaseConfig;

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");

  // Set up Firebase configuration
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

  // Initialize Firebase
  Firebase.begin(&firebaseConfig, NULL);
  Firebase.reconnectWiFi(true);
  Serial.println("Connected to Firebase");

  // Initialize the sensor and LED pins
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Attach the servo to the servo pin
  ventilationServo.attach(SERVO_PIN);
  Serial.println("Servo attached.");
  ventilationServo.write(0);
  Serial.println("Servo set to 0 degrees.");
}

void loop() {
  int flameSensorValue = digitalRead(FLAME_SENSOR_PIN);
  int gasSensorAnalogValue = analogRead(GAS_SENSOR_ANALOG_PIN);
  int motionDetected = digitalRead(MOTION_SENSOR_PIN);
  int servoPosition = ventilationServo.read(); // Get the current servo position

  Serial.print("Flame Sensor Value: ");
  Serial.println(flameSensorValue);

  Serial.print("Gas Sensor Analog Value: ");
  Serial.println(gasSensorAnalogValue);

  Serial.print("Motion Detected: ");
  Serial.println(motionDetected);

  Serial.print("Servo Position: ");
  Serial.println(servoPosition);

  if (Firebase.setInt(firebaseData, "/flameSensor", flameSensorValue)) {
    Serial.println("Flame sensor data sent successfully");
  } else {
    Serial.print("Failed to send flame sensor data: ");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.setInt(firebaseData, "/gasSensor", gasSensorAnalogValue)) {
    Serial.println("Gas sensor data sent successfully");
  } else {
    Serial.print("Failed to send gas sensor data: ");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.setInt(firebaseData, "/motionDetected", motionDetected)) {
    Serial.println("Motion sensor data sent successfully");
  } else {
    Serial.print("Failed to send motion sensor data: ");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.setInt(firebaseData, "/servoPosition", servoPosition)) {
    Serial.println("Servo position data sent successfully");
  } else {
    Serial.print("Failed to send servo position data: ");
    Serial.println(firebaseData.errorReason());
  }

  // Control the servo motor based on sensor values
  if (flameSensorValue == HIGH || gasSensorAnalogValue > 200) {
    Serial.println("Closing ventilation.");
    ventilationServo.write(90); // Close the ventilation
    delay(1000);  // Give time for the servo to move
  } else {
    Serial.println("Opening ventilation.");
    ventilationServo.write(0);  // Open the ventilation
    delay(1000);  // Give time for the servo to move
  }

  delay(500);
}
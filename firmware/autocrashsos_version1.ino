#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SoftwareSerial.h>  // For SIM800L communication

// Wi-Fi credentials
#define WIFI_SSID "your-ssid"
#define WIFI_PASSWORD "your-password"
#define FIREBASE_AUTH "YOUR_FIREBASE_KEY"// Firebase Configuration
#define FIREBASE_HOST "YOUR_FIREBASE_HOST URL"// Firebase Configuration


// Firebase Data Object
FirebaseData firebaseData;

// Define SIM800L communication pins
#define SIM_RX_PIN 17
#define SIM_TX_PIN 16
// Initialize software serial for SIM800L
SoftwareSerial SIM800L(SIM_RX_PIN, SIM_TX_PIN);
// Push Button
#define BUTTON_PIN 12  // Pin for the push button to simulate accident detection
#define BUZZER_PIN 13  // Pin for the buzzer

void setup() {
  Serial.begin(115200);
  SIM800L.begin(9600);  // Start communication with SIM800L

  // Connect to Wi-Fi
  WiFi.begin(IQoo_z3, Password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  // Connect to Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Connected to Firebase");

  // Set up button and buzzer pins
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button to detect accidents
  pinMode(BUZZER_PIN, OUTPUT);       // Buzzer for alerting
}
void loop() {
  String latitude = "12.9716";  // Example latitude
  String longitude = "77.5946"; // Example longitude

  // Send GPS location data to Firebase
  Firebase.setString(firebaseData, "/accident/location/latitude", latitude);
  Firebase.setString(firebaseData, "/accident/location/longitude", longitude);

  // Simulate accident detection with the push button (accident detected when button is pressed)
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Send SMS alert
    sendSMS("Accident detected! Location: " + latitude + ", " + longitude);
    digitalWrite(BUZZER_PIN, HIGH);  // Activate buzzer for 5 seconds
    delay(5000);
    digitalWrite(BUZZER_PIN, LOW);   // Deactivate buzzer
  }
  delay(1000);  // Check every second
}
void sendSMS(String message) {
  Serial.println("Sending SMS...");
  SIM800L.print("AT+CMGF=1\r");  // Set SMS to text mode
  delay(100);
  SIM800L.print("AT+CMGS=\"+XXXXXXXXXXX\"\r");  // Replace with recipient's phone number
   delay(100);
  SIM800L.print(message);  // Send message content
  delay(100);
  SIM800L.write(26);  // Send the message (CTRL+Z)
}

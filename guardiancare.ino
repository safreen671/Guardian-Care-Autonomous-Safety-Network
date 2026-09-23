/************************************************************
 * GUARDIAN CARE AUTONOMOUS SAFETY NETWORK
 * Motion Detection System for Restricted Areas
 *
 * Hardware:
 * - NodeMCU ESP8266
 * - PIR Motion Sensor
 * - Buzzer
 * - LED
 *
 * Platform:
 * - Arduino IDE
 * - Blynk IoT
 ************************************************************/

#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Guardian Care"
#define BLYNK_AUTH_TOKEN    "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// ================= WIFI =================

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ================= PIN CONFIGURATION =================

// NodeMCU pins
#define PIR_PIN     D5
#define BUZZER_PIN  D6
#define LED_PIN     D7

// ================= SETTINGS =================

const unsigned long MOTION_COOLDOWN = 5000;

unsigned long lastMotionTime = 0;
int motionCount = 0;

// ================= BLYNK TIMER =================

BlynkTimer timer;

// ======================================================
// SEND SYSTEM STATUS
// ======================================================

void sendStatus()
{
  Blynk.virtualWrite(V1, "SYSTEM ONLINE");
  Blynk.virtualWrite(V2, motionCount);

  Serial.println("Status: SYSTEM ONLINE");
  Serial.print("Motion Count: ");
  Serial.println(motionCount);
}

// ======================================================
// MOTION ALERT
// ======================================================

void motionAlert()
{
  unsigned long currentTime = millis();

  // Prevent repeated alerts
  if (currentTime - lastMotionTime < MOTION_COOLDOWN)
  {
    return;
  }

  lastMotionTime = currentTime;

  motionCount++;

  // Local alert
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);

  // Update Blynk
  Blynk.virtualWrite(V0, 1);
  Blynk.virtualWrite(V2, motionCount);

  // Blynk event notification
  Blynk.logEvent(
    "motion_alert",
    "Motion detected in restricted area!"
  );

  Serial.println("================================");
  Serial.println("⚠ MOTION DETECTED!");
  Serial.println("⚠ INTRUSION ALERT!");
  Serial.print("Motion Count: ");
  Serial.println(motionCount);
  Serial.println("================================");

  delay(1000);

  // Turn OFF local alarm
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Blynk.virtualWrite(V0, 0);
}

// ======================================================
// CHECK PIR SENSOR
// ======================================================

void checkMotion()
{
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH)
  {
    motionAlert();
  }
}

// ======================================================
// WIFI CONNECTION
// ======================================================

void checkWiFi()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi disconnected!");
    Serial.println("Reconnecting...");

    WiFi.begin(ssid, pass);

    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED && attempts < 20)
    {
      delay(500);
      Serial.print(".");
      attempts++;
    }

    Serial.println();

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("WiFi reconnected!");
      Serial.print("IP Address: ");
      Serial.println(WiFi.localIP());
    }
    else
    {
      Serial.println("WiFi reconnection failed.");
    }
  }
}

// ======================================================
// SETUP
// ======================================================

void setup()
{
  Serial.begin(115200);

  // Configure pins
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Initial state
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println();
  Serial.println("======================================");
  Serial.println(" GUARDIAN CARE AUTONOMOUS SAFETY");
  Serial.println(" NETWORK");
  Serial.println("======================================");

  // Connect WiFi + Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("System initialized.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Send status every 10 seconds
  timer.setInterval(10000L, sendStatus);

  // Check WiFi every 15 seconds
  timer.setInterval(15000L, checkWiFi);
}

// ======================================================
// MAIN LOOP
// ======================================================

void loop()
{
  Blynk.run();
  timer.run();

  checkMotion();

  delay(100);
}

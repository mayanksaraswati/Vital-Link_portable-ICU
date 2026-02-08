#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include <DHT.h>

/* ================= PINS ================= */
#define DHTPIN 4
#define DHTTYPE DHT11
#define BUZZER 27
#define LED_OK 26
#define LED_ALERT 25

MAX30105 particleSensor;
DHT dht(DHTPIN, DHTTYPE);

/* ================= VARIABLES ================= */
uint32_t irBuffer[100];
uint32_t redBuffer[100];
int32_t spo2;
int8_t validSPO2;
int32_t heartRate;
int8_t validHeartRate;

float roomTemp = 0;
float humidity = 0;

/* ================= SETUP ================= */
void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(BUZZER, OUTPUT);
  pinMode(LED_OK, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);

  dht.begin();

  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    while (1);
  }

  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x1F);
  particleSensor.setPulseAmplitudeIR(0x1F);

  digitalWrite(BUZZER, LOW);
}

/* ================= LOOP ================= */
void loop() {

  for (int i = 0; i < 100; i++) {
    while (!particleSensor.available())
      particleSensor.check();

    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample();
  }

  maxim_heart_rate_and_oxygen_saturation(
    irBuffer, 100, redBuffer,
    &spo2, &validSPO2,
    &heartRate, &validHeartRate
  );

  roomTemp = dht.readTemperature();
  humidity = dht.readHumidity();

  if (!validHeartRate || heartRate < 40 || heartRate > 180)
    heartRate = 0;
  if (!validSPO2)
    spo2 = 0;

  bool danger = (spo2 < 90 || roomTemp >= 39);

  digitalWrite(LED_OK, !danger);
  digitalWrite(LED_ALERT, danger);
  digitalWrite(BUZZER, danger);

  Serial.printf(
    "HR:%d,SpO2:%d,Temp:%.1f,Hum:%d\n",
    heartRate, spo2, roomTemp, (int)humidity
  );

  delay(1000);
}

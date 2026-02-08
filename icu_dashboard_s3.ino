#include <Wire.h>
#include <LovyanGFX.hpp>

/* ================= TFT ================= */
class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ILI9341 panel;
  lgfx::Bus_Parallel8 bus;
public:
  LGFX() {
    auto bc = bus.config();
    bc.freq_write = 20000000;
    bc.pin_wr = 4;
    bc.pin_rs = 2;
    bc.pin_d0 = 12; bc.pin_d1 = 13; bc.pin_d2 = 14; bc.pin_d3 = 15;
    bc.pin_d4 = 16; bc.pin_d5 = 17; bc.pin_d6 = 18; bc.pin_d7 = 19;
    bus.config(bc);

    auto pc = panel.config();
    pc.pin_cs = 5;
    pc.pin_rst = 21;
    pc.panel_width = 240;
    pc.panel_height = 320;
    panel.config(pc);

    panel.setBus(&bus);
    setPanel(&panel);
  }
};
LGFX tft;

/* ================= MPU6050 ================= */
#define MPU_ADDR 0x68
float axg, ayg, azg;
bool fallDetected;

/* ================= ECG ================= */
#define ECG_PIN 38

/* ================= UART ================= */
#define RXD1 41
#define TXD1 42
HardwareSerial SlaveSerial(1);

/* ================= DATA ================= */
int hr, spo2;
float roomTemp;
int humidity;
int ecgValue;

/* ================= SETUP ================= */
void setup() {
  Serial.begin(115200);
  Wire.begin(10, 11);
  SlaveSerial.begin(115200, SERIAL_8N1, RXD1, TXD1);

  tft.init();
  tft.setRotation(1);
  tft.setTextSize(2);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
}

/* ================= LOOP ================= */
void loop() {

  // MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  axg = (Wire.read() << 8 | Wire.read()) / 16384.0;
  ayg = (Wire.read() << 8 | Wire.read()) / 16384.0;
  azg = (Wire.read() << 8 | Wire.read()) / 16384.0;

  fallDetected = (abs(axg) > 2.5 || abs(ayg) > 2.5 || abs(azg) > 2.5);

  // ECG
  ecgValue = analogRead(ECG_PIN);

  // UART Data
  if (SlaveSerial.available()) {
    String data = SlaveSerial.readStringUntil('\n');
    sscanf(data.c_str(),
           "HR:%d,SpO2:%d,Temp:%f,Hum:%d",
           &hr, &spo2, &roomTemp, &humidity);
  }

  // Status
  String status = "OK";
  if (spo2 < 90 || roomTemp >= 39 || fallDetected)
    status = "DANGER";
  else if (roomTemp >= 37.5)
    status = "ALERT";

  // DISPLAY
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);

  tft.drawString("ICU MONITORING SYSTEM", 10, 5);
  tft.drawLine(0, 40, 240, 40);

  int y = 50;
  tft.drawString("MPU X:", 5, y); tft.drawFloat(axg, 2, 90, y);
  tft.drawString("HR:", 150, y); tft.drawNumber(hr, 200, y);

  y += 22;
  tft.drawString("MPU Y:", 5, y); tft.drawFloat(ayg, 2, 90, y);
  tft.drawString("SpO2:", 150, y); tft.drawNumber(spo2, 210, y);

  y += 22;
  tft.drawString("MPU Z:", 5, y); tft.drawFloat(azg, 2, 90, y);
  tft.drawString("Room T:", 150, y); tft.drawFloat(roomTemp, 1, 220, y);

  y += 22;
  tft.drawString("Fall:", 5, y);
  tft.drawString(fallDetected ? "YES" : "NO", 90, y);
  tft.drawString("Hum:", 150, y);
  tft.drawNumber(humidity, 210, y); tft.drawString("%", 235, y);

  y += 22;
  tft.drawString("ECG:", 5, y); tft.drawNumber(ecgValue, 90, y);
  tft.drawString("Status:", 150, y);
  tft.drawString(status, 215, y);

  delay(600);
}

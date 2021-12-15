#define STASSID "strengGeheim" // SSID Name
#define STAPSK  "1234567890abcdefg" // W-Lan Passwort
#define HOSTNAME  "ntp-uhr"

#define OTA // auskommentieren um OnTheAir zu Deaktivieren

#ifdef OTA
#define OTA_PASSWD "ABCDEF1234567890"
#endif

/* Display *************************/
#define displayRefreshTime_ms 200
#define ht16k33_Addr 0x75
#define Brightness 8

/* Configuration of NTP */
#define MY_NTP_SERVER "de.pool.ntp.org"
#define MY_TZ "CET-1CEST,M3.5.0,M10.5.0/3"
               
/* include ************************/
#include <Arduino.h>
#include <ESP8266WiFi.h>            // we need wifi to get internet access
#include <time.h>                   // time() ctime()
#ifdef OTA
#include <ArduinoOTA.h>
#endif
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"   // Adafruit_7segment matrix.***()

/* Globals ************************/
long displayRefresh = 0;
time_t now; // this is the epoch
tm tm; // the structure tm holds time information in a more convient way

Adafruit_7segment matrix = Adafruit_7segment();

void init_Wifi() {
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
  #ifdef OTA
  ArduinoOTA.setHostname(HOSTNAME);
  ArduinoOTA.setPassword(OTA_PASSWD);
  ArduinoOTA.begin();
  #endif
}

String kleinerNull(int value) {
  if (value < 10) {
    return "0" + String(value);
  } else {
    return String(value);
  }
}

void LED_init() {
  matrix.begin(ht16k33_Addr);
  matrix.setBrightness(Brightness);  
  matrix.writeDigitNum(0, 8);
  matrix.writeDigitNum(1, 8);
  matrix.writeDigitNum(3, 8);
  matrix.writeDigitNum(4, 8);
  matrix.writeDisplay();
}

void LED_printTime() {
  // update the structure tm with the current time
  time(&now);
  localtime_r(&now, &tm);

  // create Time gtring 06:20
  String Uhrzeit = kleinerNull(tm.tm_hour) + ":" + kleinerNull(tm.tm_min);

  #define timeDigit(s) s,Uhrzeit.substring(s,(s+1)).toInt()
  // write Time on Display
  matrix.writeDigitNum(timeDigit(0));
  matrix.writeDigitNum(timeDigit(1));
  matrix.writeDigitNum(timeDigit(3));
  matrix.writeDigitNum(timeDigit(4));

  // den Doppen Punkt blinken lassen...
  if (tm.tm_sec % 2 == 0) {
    matrix.drawColon(true);
  } else {
    matrix.drawColon(false);
  }
  matrix.writeDisplay();
}

void setup() {
  LED_init();
  
  configTime(MY_TZ, MY_NTP_SERVER);
  // --> Here is the IMPORTANT ONE LINER needed in your sketch!

  init_Wifi();
}

void loop() {
  #ifdef OTA
  ArduinoOTA.handle();
  #endif
  long newTime = millis();
  if (newTime - displayRefresh > displayRefreshTime_ms) {
    displayRefresh = newTime;
    LED_printTime();
  }
}

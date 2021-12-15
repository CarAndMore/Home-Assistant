/* ht16k33 -> 4 Digit 7 Segment 0,56 Zoll LED Anzeigemodul Clock
 * https://www.amazon.de/s?k=0%2C56%22+Ht16k33+I2c&__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&ref=nb_sb_noss
 * https://www.ebay.de/sch/i.html?_from=R40&_trksid=p2380057.m570.l1313&_nkw=0%2C56%22+Ht16k33+I2c&_sacat=0
 */
// Idee: http://werner.rothschopf.net/201802_arduino_esp8266_ntp.htm

#define STASSID "geheim"                          // set your SSID
#define STAPSK  "12345678"                        // set your wifi password

#define displayRefreshTime_ms 200
#define ht16k33_Addr 0x75
#define Brightness 8

/* Configuration of NTP */
#define MY_NTP_SERVER "at.pool.ntp.org"
#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"


/* include ************************/
#include <ESP8266WiFi.h>            // we need wifi to get internet access
#include <time.h>                   // time() ctime()
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
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
  }
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
  long newTime = millis();
  if (newTime - displayRefresh > displayRefreshTime_ms) {
    displayRefresh = newTime;
    LED_printTime();
  }
}

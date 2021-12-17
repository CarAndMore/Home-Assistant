# Meine Uhr
Arduino _esp8266_ code: [ntp_ht16k33_uhr_v1.0.6.ino](/esp_Uhr/ntp_ht16k33_uhr_v1.0.6.ino)

![modul](/img/ht16k33_clock.svg)
![ESP8266 d1 Mini](/img/esp8266_d1mini.svg)

install Libs:
- Adafruit_GFX.h
- Adafruit_LEDBackpack.h
- ArduinoOTA.h (wenn Def OTA)

## Hardware Anschluss:
<table>
  <tr>
    <th>ht16k33</th>   <th>ESP8266 (d1 Mini)</th>
  </tr>
  <tr>
    <td>+5V</td>  <td>+5V</td>
  </tr>
  <tr>
    <td>GND</td>  <td>GND</td>
  </tr>
  <tr>
    <td>SDA</td>  <td>D1 (SDA)</td>
  </tr>
  <tr>
    <td>SCL</td>  <td>D0 (SCL)</td>
  </tr>
</table>

## w-Lan Daten:
```cpp
#define STASSID "streng Geheim"
#define STAPSK  "1234567890abcdefg"
#define HOSTNAME  "ntp-uhr"

#define OTA // auskommentieren um OnTheAir zu Deaktivieren

#define OTA_PASSWD "ABCDEF1234567890" // Nur wenn OTA aktivieren
```

## I²C Divice Addr:
```cpp
#define ht16k33_Addr 0x75
```
## NTP server
Deutschland
```cpp
#define MY_NTP_SERVER "de.pool.ntp.org"
```
Österreich
```cpp
#define MY_NTP_SERVER "at.pool.ntp.org"
```
zum Umrechnen der UTC auf die konkrete Ortszeit verwendest du eine bestehende Zeitzonedefinition:
[zones.csv](https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv)

Deutschland (Europe/Berlin) => CET-1CEST,M3.5.0,M10.5.0/3
```cpp
#define MY_TZ "CET-1CEST,M3.5.0,M10.5.0/3"
```

Österreich
```cpp
#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"
```


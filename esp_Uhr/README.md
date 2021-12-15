# Meine Uhr
Arduino _esp8266_ code: [ntp_ht16k33_uhr_v1.0.6.ino](/esp_Uhr/ntp_ht16k33_uhr_v1.0.6.ino)

![modul](/img/ht16k33_clock.jpg)

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
#define STASSID "Rabenherz"
#define STAPSK  "12345678"
```

## I²C Divice Addr:
```cpp
#define ht16k33_Addr 0x75
```
## NTP server
```cpp
#define MY_NTP_SERVER "at.pool.ntp.org"
#define MY_TZ "CET-1CEST,M3.5.0/02,M10.5.0/03"0x75
```

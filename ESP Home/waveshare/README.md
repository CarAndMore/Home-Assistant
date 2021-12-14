# Waveshare 2.9 zoll  # 296 x 128

[waveshare-v1.yaml](/waveshare/waveshare-v1.yaml)

EspHome: [Waveshare E-Paper Display](https://esphome.io/components/display/waveshare_epaper.html)

## edit/add "/esphome/secret.yaml":
```yml
wifi_ssid: "fritzbox7050"
wifi_password: "abcdef1234567890"

hass_api_password: "1234567890abcdef"
hass_ota_password: "12345abcdef67890"
```

## edit IOs:
```yml
#- IOs ------------------------
spi:
  clk_pin: D0
  mosi_pin: D1
  
#- Display --------------------
display:
  - platform: waveshare_epaper
    id: e_paper
    cs_pin: D2
    dc_pin: D3
    busy_pin: D4
    reset_pin: D5
```
## edit sensor:
```yml
#- Sensoren -------------------
sensor:
  - platform: wifi_signal
    name: "waveshare-v1 Signal"
    update_interval: 30s

  - platform: homeassistant
    id: aussen_temperature
    entity_id: sensor.28_05167180e7ff_temperature
    internal: true

  - platform: homeassistant
    id: innen_temperature
    entity_id: sensor.28_051671ad09ff_temperature
    internal: true
```

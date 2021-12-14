# Wetterwarnungen in Home Assistant
*idee by* SmartHome yourself [Wetterwarnungen in Home Assistant einbinden ...](https://www.youtube.com/watch?v=yYK5giUO19E) **(YouTube)**


![keine warnung](/img/dwd_0.jpg)

add configuration.yaml

## Warnungen
```yml
sensor:
# Wetter Warnungen 
# - Meckenheim
  - platform: dwd_weather_warnings
    name: dwd_Meckenheim
    region_name: 805382032
```

Karten
```yml
camera:
  # DWD Warnungen
  - platform: generic # Warnungen: MAP Nordrhein-Westfalen
    still_image_url: https://www.dwd.de/DWD/warnungen/warnstatus/SchilderEM.jpg
    name: DWD Warnungen Nordrhein-Westfalen
  - platform: generic # Warnungen: MAP Hessen, Rheinland-Pfalz, Saarland
    still_image_url: https://www.dwd.de/DWD/warnungen/warnstatus/SchilderOF.jpg
    name: DWD Warnungen Hessen, Rheinland-Pfalz, Saarland
```

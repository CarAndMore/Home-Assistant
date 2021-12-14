# Wetterwarnungen in Home Assistant
*idee by* SmartHome yourself [Wetterwarnungen in Home Assistant einbinden ...](https://www.youtube.com/watch?v=yYK5giUO19E) **(YouTube)**


![keine warnung](/img/dwd_0.jpg)

## Home-Assistant Integration
- [DWD Weather Warnings](https://www.home-assistant.io/integrations/dwd_weather_warnings/)
- [Generic Camera](https://www.home-assistant.io/integrations/generic/)
## DWD Daten:
- [Wetterwarnung Grafik URLs](https://www.dwd.de/DE/wetter/warnungen_aktuell/objekt_einbindung/objekteinbindung.html)
- [Zellen-IDs](https://www.dwd.de/DE/leistungen/opendata/help/warnungen/cap_warncellids_csv.html)


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

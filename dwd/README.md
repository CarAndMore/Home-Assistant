# Wetterwarnungen in Home Assistant
*idee by* SmartHome yourself **(YouTube)**
- [Wetterwarnungen in Home Assistant einbinden ...](https://www.youtube.com/watch?v=yYK5giUO19E)
- [Pollenflug-Daten des DWD in Home Assistant einbinden](https://www.youtube.com/watch?v=yHI9Dt4xD4g)


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

# Pollenflug-Daten in Home Assistant

- [Polleninformationen DWD](https://www.dwd.de/DE/klimaumwelt/ku_beratung/gesundheit/pollen/pollen_node.html)
- [Pollenflug Gefahrenindex (Karte)](https://isabel.dwd.de/DE/leistungen/gefahrenindizespollen/gefahrenindexpollen.html)
- [DWD OpenData](https://www.dwd.de/DE/leistungen/opendata/opendata.html)
- [Pollen-Gefahrenindex Dokumentation](https://opendata.dwd.de/climate_environment/health/alerts/Beschreibung_pollen_s31fg.pdf) **PDF**

[dwd_pollen.yaml](/dwd/dwd_pollen.yaml)

edit: "@.partregion_id=="  

```yml
sensor:
  - platform: rest # dwd_pollen
    scan_interval: 3600
    name: dwd_pollen
    #....
    json_attributes_path:  "$..content[?(@.partregion_id==102)].Pollen"
    #......
```
- 10=Schleswig-Holstein und Hamburg
- 11=Inseln und Marschen
- 12=Geest,Schleswig-Holstein und Hamburg
- 20=Mecklenburg-Vorpommern
- 30=Niedersachsen und Bremen
- 31=Westl. Niedersachsen/Bremen
- 32=Östl. Niedersachsen
- 40=Nordrhein-Westfalen
- 41=Rhein.-Westfäl. Tiefland
- 42=Ostwestfalen
- 43=Mittelgebirge NRW
- 50=Brandenburg und Berlin
- 60=Sachsen-Anhalt
- 61=Tiefland Sachsen-Anhalt
- 62=Harz
- 70=Thüringen
- 71=Tiefland Thüringen
- 72=Mittelgebirge Thüringen
- 80=Sachsen
- 81=Tiefland Sachsen
- 82=Mittelgebirge Sachsen
- 90=Hessen
- 91=Nordhessen und hess. Mittelgebirge
- 92=Rhein-Main
- 100=Rheinland-Pfalz und Saarland
- 101=Rhein, Pfalz, Nahe und Mosel
- 102=Mittelgebirgsbereich Rheinland-Pfalz
- 103=Saarland
- 110=Baden-Württemberg
- 111=Oberrhein und unteres Neckartal
- 112=Hohenlohe/mittlerer Neckar/Oberschwaben
- 113=Mittelgebirge Baden-Württemberg
- 120=Bayern
- 121=Allgäu/Oberbayern/Bay. Wald
- 122=Donauniederungen
- 123=Bayern nördl. der Donau, o. Bayr. Wald, o. Mainfranken
- 124=Mainfranken


# Bar-Card (HACS Frontend Integration):
- [Bar-Card](https://github.com/custom-cards/bar-card)

![pollenflug](/img/dwd_1.jpg)

[Bar-Card.yaml](/dwd/Bar-Card.yaml)


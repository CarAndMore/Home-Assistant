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


```yml
sensor:
  - platform: rest # dwd_pollen
    scan_interval: 3600
    name: dwd_pollen
    resource: https://opendata.dwd.de/climate_environment/health/alerts/s31fg.json
    json_attributes_path:  "$..content[?(@.partregion_id==102)].Pollen"
    json_attributes:
      - Erle
      - Beifuss
      - Ambrosia
      - Birke
      - Esche
      - Hasel
      - Graeser
      - Roggen
    value_template: "{{ value_json.last_update }}"
```

einzel daten as template:
```yml
sensor:
  - platform: template # DWD-Pollenflug
    sensors:
      dwd_pollen_erle:
        icon_template: "mdi:tree-outline"
        friendly_name: "Erle"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Erle')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Erle')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Erle')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_beifuss:
        icon_template: "mdi:tree-outline"
        friendly_name: "Beifuss"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Beifuss')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Beifuss')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Beifuss')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_ambrosia:
        icon_template: "mdi:tree-outline"
        friendly_name: "Ambrosia"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Ambrosia')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Ambrosia')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Ambrosia')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_birke:
        icon_template: "mdi:tree-outline"
        friendly_name: "Birke"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Birke')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Birke')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Birke')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_esche:
        icon_template: "mdi:tree-outline"
        friendly_name: "Esche"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Esche')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Esche')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Esche')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_hasel:
        icon_template: "mdi:tree-outline"
        friendly_name: "Hasel"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Hasel')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Hasel')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Hasel')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_graeser:
        icon_template: "mdi:tree-outline"
        friendly_name: "Graeser"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Graeser')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Graeser')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Graeser')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}

      dwd_pollen_roggen:
        icon_template: "mdi:tree-outline"
        friendly_name: "Roggen"
        value_template: >-
          {% set dwd_state = state_attr('sensor.dwd_pollen', 'Roggen')['today'] %}
          {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
        attribute_templates:
          today: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Roggen')['today'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
          tomorrow: >-
            {% set dwd_state = state_attr('sensor.dwd_pollen', 'Roggen')['tomorrow'] %}
            {% if dwd_state == "3" %}6{% elif dwd_state == "2-3"%}5{% elif dwd_state == "2"%}4{% elif dwd_state == "1-2"%}3{% elif dwd_state == "1"%}2{% elif dwd_state == "0-1"%}1{% else %}0{% endif %}
```



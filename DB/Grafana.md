# Grafana

## Config Addon:
```yml
certfile: fullchain.pem
env_vars: []
keyfile: privkey.pem
plugins: []
ssl: false
```

auf Starten klicken, und Warten....  Warten.... 

auf der Benutzeroberfläsche
```yml
defauld_login:
  USER: "admin"
  password: "hassio"
```
## add InfuxDB
![Grafana_01](/img/Grafana_01.jpg)

![Grafana_02](/img/Grafana_02.jpg)
## datenbank
daten der [InfluxDB](/DB/InfluxDB.md) datenbank
```yml
url: http://homeassistant:8086
DB: "homeassistant"
USER: "carandmore"
password: 123456789abcdef
```
![Grafana_03](/img/Grafana_03.jpg)
![Grafana_04](/img/Grafana_04.jpg)

fast fertig.  warten bis genug Daten aufgezeichnet wurden.

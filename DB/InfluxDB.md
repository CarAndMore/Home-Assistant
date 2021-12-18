# Datenbank

## InfluxDB

```yml
auth: true
certfile: fullchain.pem
envvars: []
keyfile: privkey.pem
reporting: true
ssl: false
```
```
80/tcp:    Deaktiviert
8086/tcp:  8086
```
auf der Benutzeroberfläsche:
Add Datenbank _homeassistant_

![influxDB1 add DB](/img/influxDB1.jpg)

Add User
![influxDB add User](/img/influxDB2.jpg)

Rechte setzen **all**
![influxDB 3](/img/influxDB3.jpg)

```yml
DB: "homeassistant"
USER: "carandmore"
password: 123456789abcdef
```

## /configuration.yaml

```yml
influxdb:
  host: homeassistant
  port: 8086
  database: homeassistant
  username: carandmore
  password: 123456789abcdef
  ssl: false
  verify_ssl: false
  max_retries: 3
  default_measurement: state
  include:
    domains:
       - sensor
       - light
       - switch
       - binary_sensor
  tags:
    instance: prod
    source: hass
```

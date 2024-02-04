float Temperatura() {
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp= round(sensors.getTempCByIndex(0)); //Se obtiene la temperatura en ºC
return temp;                  
}

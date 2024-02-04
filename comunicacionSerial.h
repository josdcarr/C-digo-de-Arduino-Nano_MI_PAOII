using JsonDocumentType = StaticJsonDocument<400>;// Definicion del objeto json con tamaño de 400 bytes
// Función que devuelve un JSON
JsonDocumentType JsonMedidas(float Sensortemperatura, float Sensortds, bool SensornivelAgua,float SensorPH,float SensorORP) {
  JsonDocumentType doc;
  doc["Temperatura"] = Sensortemperatura;
  doc["TDS"] = Sensortds;
  doc["Nivel de agua"] = SensornivelAgua;
  doc["pH"] = SensorPH;
  doc["ORP"] = SensorORP;
  return doc;
}

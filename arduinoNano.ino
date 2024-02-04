// Inclusion de librerias importantes
#include <OneWire.h>      //Para comunicacion con el sensor de temperatura          
#include <DallasTemperature.h>//Para leer el sensor    
#include <ArduinoJson.h>//Para crear un json y enviarlo al esp32    
#include <Wire.h> // Comunicacion I2C
#include <LiquidCrystal_I2C.h>//Comunicacion I2C con lcd
#include "orp_grav.h"
// Establecer constantes 
//---------------------------------PH-----------------------------------------
#define PHSensorPin A0

//---------------------------------ORP-----------------------------------------

Gravity_ORP ORP = Gravity_ORP(A2);
//---------------------------------TDS-----------------------------------------
#define TdsSensorPin A1
//---------------------------------Nivel agua-----------------------------------------
#define NASensorPin 2
//-------------------------------Temperatura----------------------------------------
OneWire ourWire(3);                //Se establece el pin 3  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
//-------------------------------Perifericos----------------------------------------
//RGB
#define pinR 6
#define pinG 5

//I2C
LiquidCrystal_I2C lcd(0x27,16,2);  
#define LCD 8
//LCD
#define Buzzer 7
//------------------------------- Incluir headers
#include "TDS.h"
#include "N_agua.h"
#include "Temperatura.h"
#include "comunicacionSerial.h"
#include "perifericos.h"
#include "ph.h"
#include "ORP.h"
//--------------------------------Informacion a captar
float temperatura,orp,ph,tds;
bool agua;
bool prueba=false;
int sonido=0;
void setup() {
 Serial.begin(9600);
 pinMode(NASensorPin,INPUT);
 sensors.begin();
  lcd.init();
  lcd.backlight();
  pinMode(Buzzer, OUTPUT);  
  pinMode(pinR,OUTPUT);
  
  pinMode(pinG,OUTPUT);
  pinMode(LCD,INPUT);
  analogWrite(pinR,255);
  analogWrite(pinG,255);
}

void loop() {

tds=nivelTDS();
agua=nivelAgua();
temperatura=Temperatura();
//ph=(round(NivelpH() * 10.0) / 10.0);
ph=round(NivelpH() * 10) / 10.0;
orp=round((int)ORP.read_orp() * 10) / 10.0;
ledRGB(ph);

if(digitalRead(LCD)==1){
//if(true){
  if (sonido==0){
  pitido();  
  }
  sonido=1;
  lcdDatos(temperatura,ph,orp,tds);
  }else{
  analogWrite(pinR,0);
  analogWrite(pinG,255);
  lcd.clear();  
  lcd.setCursor(0, 0);   
  lcd.print("Bomba desconectada");
  delay(500);
  lcd.clear();  
  lcdDatos(temperatura,ph,orp,tds);
  sonido=0;
}
JsonDocumentType jsonMediciones = JsonMedidas(temperatura, tds, agua,ph,orp);
String jsonString;
serializeJson(jsonMediciones, jsonString);
  // Enviar a puerto serial
Serial.println(jsonString);//Envio por comunicacion serial

   
}

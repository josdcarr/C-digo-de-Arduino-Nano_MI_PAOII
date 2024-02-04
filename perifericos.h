

//Mostrar datos en la pantalla 
void lcdDatos(float temp, float ph, float orp, float tds){

lcd.setCursor(0, 0);    
lcd.print("Temp: ");
lcd.print(temp);
lcd.print(" C");
lcd.setCursor(0, 1);    
lcd.print("pH: ");
lcd.print(ph);
delay(1000);
lcd.clear();  
lcd.print("ORP: ");
lcd.print(orp);
lcd.setCursor(0, 1);    
lcd.print("TDS: ");
lcd.print(tds);
lcd.print(" ppm");
delay(500);
lcd.clear();
}
void pitido() {
  tone(Buzzer, 1000); // Pitido de 1Kh
  delay(1000);        
  noTone(Buzzer);     // Detener sonido
}

void ledRGB(float ph) {//255 significa brillo minimo, 0 es brillo al maximo. Se uso un led rgb tipo anodo
if(ph>8|| ph<7 ){
  
  analogWrite(pinR,0);
  analogWrite(pinG,255);


}else{
 
  analogWrite(pinG,0);
  analogWrite(pinR,255);
}
}

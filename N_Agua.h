


bool nivelAgua()
{
// read the level value of pin 7 and assign if to val
if(digitalRead(NASensorPin)==LOW)// check if the button is pressed, if yes, turn on the LED
{ return false;}
else
{ return true;}
}

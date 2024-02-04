bool nivelAgua()
{
// Detecta si hay liquidos en el pin de entrada
if(digitalRead(NASensorPin)==LOW)
{ return false;}
else
{ return true;}
}

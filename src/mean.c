// Dateiname: mean.c
// Der Funktion werden drei Zahlen vom Typ short übergeben. Die Funktion berechnet anschließend den Mittelwert und gibt diesen zurück.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 15.12.2023
// Version: 1.0

short mean(short firstNumber, short secondNumber, short thirdNumber)
{
    short result;

    result = (firstNumber + secondNumber + thirdNumber) / 3;

    return result;
}
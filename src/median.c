// Dateiname: median.c
// Der Funktion werden drei Zahlen vom Typ short übergeben. Anschließend werden die Werte einem Array numbers[] zugeordnet,
// dass nach dem Bubble-Sort Algorithmus sortiert wird. Der mittlere Wert wird zurückgegeben. Das ist der Median der drei Werte.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

short median(short firstNumber, short secondNumber, short thirdNumber)
{
    short numbers[] = {firstNumber, secondNumber, thirdNumber}; // Array zum Sortieren der Zahlen
    short temp;                                                 // Temporärer Speicher für den Bubble-Sort Algorithmus

    // numbers[] wird mit dem Bubble-Sort Algorithmus sotiert
    for (char i = 1; i < 3; i++)
    {
        for (char j = 0; j < 3 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Mittleres Element von numbers[] zurückgeben (Der Median der 3 übergebenen Zahlen)
    return numbers[1];
}

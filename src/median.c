// Dateiname: median.c
// Der Funktion werden drei Zahlen vom Typ short übergeben. Anschließend werden die Werte einem Array numbers zugeordnet,
// dass nach dem BubbleSort-Algorithmus sortiert wird. Der Mittlerewert wird zurückgegeben. Das ist der Median der drei Werte.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 15.12.2023
// Version: 1.0

short median(short firstNumber, short secondNumber, short thirdNumber)
{
    short numbers[] = {firstNumber, secondNumber, thirdNumber};
    short temp;

    // Bubble-Sort Algorithmus

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

    return numbers[1];
}
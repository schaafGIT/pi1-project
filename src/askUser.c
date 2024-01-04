// Dateiname: askUser.c
// Die Funktion fragt den User, ob für die Auswertung der Messwerte der Median oder der Mittelwert verwendet werden soll.
// Zurückgegeben wird die Variable reult, die etwa true für den Median sein kann oder false für den Mittelwert.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include <stdio.h>
#include <string.h>

char askUser()
{
    char input;    // Variable für die Eingabe des Users
    char flag = 1; // Flag für die Überprüfung, ob ein zulässiger Wert eingegeben wurde
    char result;   // Zur Speicherung der Usereingabe als Wahrheitswert

    // Erstmalige Anfragen an den User, ob der Median oder Mittelwert genutzt werden soll
    printf("\n     [   1 - Mittelwert   |   2 - Median   ]\n");
    printf("\nSoll für die Auswertung der Median oder der Mittelwert der letzten drei Messwerte genutzt werden?\n");
    printf("\n  Antwort: ");
    scanf("%c", &input);

    // Überprüfung der Eingabe
    do
    {
        if (input == '1')
        {
            // Mittelwert
            result = 1;
            flag = 0;
        }
        else if (input == '2')
        {
            // Median
            result = 0;
            flag = 0;
        }
        else
        {
            // Wenn die Eingabe unzulässig ist
            printf("\nDie Eingabe ist unzulässig! Bitte geben Sie etwa 1 für den Mittelwert oder 2 für den Median an.\n");
            printf("\nAntwort: ");
            scanf("%c", &input); // Das Erste scanf() dient zum Abfangen der Entertaste, da ansonsten der Text doppelt auftritt
            scanf("%c", &input); // Zum erneuten Einlesen der Eingabe
        }

    } while (flag);

    return result;
}

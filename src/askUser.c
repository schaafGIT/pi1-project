// Dateiname: askUser.c
// Die Funktion fragt den User, ob für die Auswertung der Messwerte der Median oder der Mittelwert verwendet werden soll.
// Zurückgegeben wird die Variable reult, die etwa true für den Median sein kann oder false für den Mittelwert.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 10.12.2023
// Version: 1.0

#include <stdio.h>
#include <string.h>
#include "stdbool.h"

bool askUser()
{
    char input; // Variable für die Eingabe des Users
    bool flag = true;
    bool result; //

    // Erstmaliges Fragen an den User, ob der Median oder Mittelwert genutzt werden soll
    printf("\n     [   1 - Mittelwert   |   2 - Median   ]\n");
    printf("\nSoll für die Auswertung der Median oder der Mittelwert der letzten drei Messwerte genutzt werden?\n");
    printf("\n  Antwort: ");
    scanf("%s", &input);

    // Überprüfung der Eingabe
    do
    {
        if (input == '1')
        {
            // Mittelwert
            result = false;
            flag = false;
        }
        else if (input == '2')
        {
            // Median
            result = true;
            flag = false;
        }
        else
        {
            // Wenn die Eingabe unzulässig ist
            printf("\nDie Eingabe ist unzulässig! Bitte geben Sie etwa 1 für den Mittelwert oder 2 für den Median an.\n");
            printf("\nAntwort: ");
            scanf("%c", &input);
        }

    } while (flag);

    return result;
}
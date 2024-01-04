// Dateiname: extractSensorIds.c
// Die Funktion extrahiert die einzelnen Sensor-IDs aus dem dynamischen Array sensors. Sie werden in einem anderen dynamischen Array
// sensorIds gespeichert. Dabei ist jede ID nur einmal enthalten. Am Ende wird sensorIds auf seine tazächliche Länge gekürzt und
// zurückgegeben. numbersOfSensors ist die Anzahl der enthaltenen Elemente in sensorIds. Die Variable wird beim Aufruf übergeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "project.h"

char *extractSensorIds(sensorData_t *sensors, int sizeOfSensors, int *numbersOfSensors)
{
    int capacity = 10;     // Anfangskapazität von sensorIds
    char *sensorIds;       // Dynamisches Array zum Speichern aller vorhandener Sensor-IDs
    *numbersOfSensors = 0; // Anzahl der in sensorIds enthaltenden Elemente
    char currentId;        // Zur Zwischenspeicherung einer Sensor-ID
    bool found;            // Zur Überprüfung, ob eine ID schon in sensorIds enthalten ist

    // Speicherreservierung für sensorIds
    sensorIds = malloc(capacity * sizeof(char));
    if (sensorIds == NULL)
    {
        printf("Fehler bei der Speicherreservierung.\n");
        return EXIT_FAILURE;
    }

    // Die vorhandenen IDs aus sensors werden in sensorIds dynamisch abgelegt
    for (int i = 0; i < sizeOfSensors; i++)
    {
        currentId = sensors[i].id;

        // Überprüft, ob die ID schon vorhanden ist
        found = false;
        for (int j = 0; j < *numbersOfSensors; j++)
        {
            if (sensorIds[j] == currentId)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            // Sicherstellen, dass genug Platz in sensorids vorhanden ist
            if (*numbersOfSensors >= capacity)
            {
                capacity += 10; // Die Kapazität von sensorIds wird um 10 Stellen erhöht
                sensorIds = (char *)realloc(sensorIds, capacity * sizeof(char));
                if (sensorIds == NULL)
                {
                    printf("Fehler bei der Speicherreservierung.\n");
                    free(sensorIds);
                    return EXIT_FAILURE;
                }
            }
            // Füge die neue ID hinzu
            sensorIds[*numbersOfSensors] = currentId;
            (*numbersOfSensors)++;
        }
    }

    // Kürze das Array auf die tatsächliche Anzahl
    sensorIds = (char *)realloc(sensorIds, *numbersOfSensors * sizeof(char));
    if (sensorIds == NULL)
    {
        printf("Fehler bei der Speicherreservierung.\n");
        free(sensorIds); // Freigabe des ursprünglichen Blocks, falls trimming fehlschlägt
        return EXIT_FAILURE;
    }

    return sensorIds;
}

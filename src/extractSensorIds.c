// Dateiname: extractSensorIds.c
// Die Funktion extrahiert die einzelnen Sensor-IDs aus dem dynamischen Array sensors. Sie werden in einem anderen dynamischen Array
// sensorIds gespeichert. Dabei ist jede ID nur einmal enthalten. Am Ende wird sensorIds auf seine tazächliche Länge gekürzt und
// zurückgegeben. numbersOfSensors ist die Anzahl der enthaltenen Elemente in sensorIds. Die Variable wird beim Aufruf übergeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 21.12.2023
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "project.h"

char *extractSensorIds(sensorData_t *sensors, int sizeOfSensors, int *numbersOfSensors)
{
    int capacity = 10;
    char *sensorIds = malloc(capacity * sizeof(char));
    *numbersOfSensors = 0; // Anzahl der in sensorIds enthaltenden Elemente
    char currentId; // Zur Zwischenspeicherung einer Sensor-ID
    bool found;

    if (sensorIds == NULL)
    {
        printf("Speicher allocation ist fehlgeschlagen.\n");
        return 1;
    }

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
            // Sicherstellen, dass genug Platz vorhanden ist
            if (*numbersOfSensors >= capacity)
            {
                capacity += 10;
                sensorIds = (char *)realloc(sensorIds, capacity * sizeof(char));
                if (sensorIds == NULL)
                {
                    fprintf(stderr, "Memory reallocation failed\n");
                    free(sensorIds);
                    return 1;
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
        printf("Fehler bei der Reallocation.\n");
        free(sensorIds); // Freigabe des ursprünglichen Blocks, falls trimming fehlschlägt
        return 1;
    }

    return sensorIds; //sensorIds wird als dynamisches Array zurückgegeben
}
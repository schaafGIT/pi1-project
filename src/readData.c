// Dateiname: readData.c
// Die Funktion liest zeilenweise aus einer Datei namens processData.txt, die dort enthaltenen Sensordaten aus.
// Die Daten werden anschließend in einem dynamischen Array sensors zeilenweise mit der Struktur sensorData_t gespeichert.
// Am Ende wird sensors auf seine tatsächliche Länge gekürzt und als Rückgabewert zurückgegeben. Die Anzahl der enthaltenen
// Elemente wird mittels der Variable sizeOfSensors übergeben. Sie muss beim Aufrufen der Funktion übergeben werden.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

sensorData_t *readData(int *sizeOfSensors)
{
    int capacity = 10;                                                               // Die Anfangskapazität von sensors
    sensorData_t *sensors = (sensorData_t *)malloc(capacity * sizeof(sensorData_t)); // Dynamisches Array für die Sensordaten
    char line[29];                                                                   // Puffer für sscanf()

    FILE *file = fopen("processData.txt", "r"); // Die Datei processData.txt wird geöffnet

    if (!file)
    {
        printf("Fehler beim Öffnen von processData.txt.\n");
        return EXIT_FAILURE;
    }

    if (sensors == NULL)
    {
        printf("Fehler bei der Speicherreservierung.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    *sizeOfSensors = 0;

    // Liest zeilenweise die Daten aus processData.txt aus und speichert diese in line
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Überprüft, ob noch genug Speicher für sensors reserviert ist
        if (*sizeOfSensors >= capacity)
        {
            capacity += 10; // Mehr Platz für die Sensoren benötigt, erweitere um 10
            sensors = (sensorData_t *)realloc(sensors, capacity * sizeof(sensorData_t));
            if (sensors == NULL)
            {
                printf("Fehler bei der Speicherreservierung.\n");
                free(sensors);
                fclose(file);
                return EXIT_FAILURE;
            }
        }

        // Daten aus den Zeilen auslesen und füge dem dynamischen Array sensors hinzufügen
        if (sscanf(line, "%c; %hd; %hd; %hd; %hd; %hd", &sensors[*sizeOfSensors].id, &sensors[*sizeOfSensors].measuredValue,
                   &sensors[*sizeOfSensors].warningLow, &sensors[*sizeOfSensors].warningHigh, &sensors[*sizeOfSensors].alarmLow,
                   &sensors[*sizeOfSensors].alarmHigh) == 6)
        {
            (*sizeOfSensors)++;
        }
        else
        {
            // Fehler beim Auslesen der Zeil, die zudem ausgegeben wird
            printf("Fehler beim auslesen der Zeile: %s", line);
        }
    }

    fclose(file);   // Die Datei processData.txt wird geschlossen
    return sensors;
}

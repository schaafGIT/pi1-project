// Dateiname: readData.c
// Die Funktion liest zeilenweise aus einer Datei namens processData.txt, die dort enthaltenen Sensordaten aus.
// Die Daten werden anschließend in einem dynamischen Array sensors zeilenweise mit der Struktur sensorData_t gespeichert.
// Am Ende wird sensors auf seine tatsächliche Länge gekürzt und als Rückgabewert zurückgegeben. Die Anzahl der enthaltenen
// Elemente wird mittels der Variable sizeOfSensors übergeben. Sie muss beim Aufrufen der Funktion übergeben werden.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 30.12.2023
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

sensorData_t *readData(int *sizeOfSensors)
{
    int capacity = 10; // Die Anfangskapazität des dynamischen Arrays sensors
    sensorData_t *sensors = (sensorData_t *)malloc(capacity * sizeof(sensorData_t));
    char line[35];

    FILE *file = fopen("processData.txt", "r"); // Die Datei processData.txt wird geöffnet
    
    if (!file)
    {
        printf("Fehler beim Öffnen von processData.txt.\n");
        return 1;
    }

    if (sensors == NULL)
    {
        printf("Fehler bei der Allocation.\n");
        fclose(file);
        return 1;
    }

    *sizeOfSensors = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (*sizeOfSensors >= capacity)
        {
            capacity += 10; // Mehr Platz für die Sensoren benötigt, erweitere um 10
            sensorData_t *temp = (sensorData_t *)realloc(sensors, capacity * sizeof(sensorData_t));
            if (temp == NULL)
            {
                printf("Speicher reallocation ist fehlgeschlagen.\n");
                free(sensors); // Speicher von sensors freigeben
                fclose(file);  // Die Datei processData.txt wird geschlossen
                return 1;
            }
            sensors = temp;
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
    return sensors; // sensors wird als dynamisches Array zurückgegeben
}

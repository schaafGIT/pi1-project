// Dateiname: processSensorData.c
// Die Funktion holt sich über die Funktion extractSensorIds() alle existierenden Sensor-IDs und speichert diese mit dem Pointer
// sensorIDs. Anschließend extrahiert die Funktion jeweils die zu jeder ID existierenden Messwerte aus dem dynamischen Array sensors.
// Die Messwerte werden immer dynamisch im Array tempMeasuredValue temporär gespeichert. Am Ende wird das dynamische Array auf seine
// tatsächliche Anzahl an enthaltenen Messwerten gekürzt und an die Funktion analyzeSensorData() übergeben, welche für die Auswertung
// zuständig ist. Anschließend wird der Speicher von tempMeasuredValue wieder freigegeben. Das macht die Funktion soft, bis jeder der
// vorhandenen Sensoren einmal ausgewertet wurde.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

void processSensorData(sensorData_t *sensors, int sizeOfSensors)
{
    int numbersOfSensors;     // Anzahl der enthaltenden Sensoren im dynamischen Array sensors
    char userInput;           // Variabel zur Speicherung der Usereingabe von askUser()
    char *sensorIds;          // Dynamisches Array für alle vorhandenen Sensor-IDs
    short *tempMeasuredValue; // Dynamisches Array, in dem alle Messwerte eines bestimmten Sensors temporär gespeichert werden
    char currentId;           // Zur Zwischenspeicherung einer Sensor-ID
    int tempCapacity;         // Kapazität von tempMeasuredValue
    int tempCount;            // Enthält die richtige Anzahl an Elementen, die in tempMeasuredValue gespeichert sind

    sensorIds = extractSensorIds(sensors, sizeOfSensors, &numbersOfSensors); // Extraktion der vorhandenen Sensor-IDs aus sensors
    userInput = askUser();                               // Anfage an den User, ob der Mittelwert oder Median genutzt werden soll

    for (int i = 0; i < numbersOfSensors; i++)
    {
        currentId = sensorIds[i]; // Bei jedem Durchlauf wird eine neue ID in currentId gespeichert
        tempCapacity = 10;        // Die Anfankskapazität von tempMeasuredValue
        tempCount = 0;            // Setzt tempCount bei jedem Durchlauf wieder auf null
        tempMeasuredValue = (short *)malloc(tempCapacity * sizeof(short));

        if (tempMeasuredValue == NULL)
        {
            printf("Fehler bei der Speicherreservierung.");
            free(sensorIds);
            return EXIT_FAILURE;
        }

        for (int j = 0; j < sizeOfSensors; j++)
        {
            if (sensors[j].id == currentId) // Überprüfung, ob der Messwert an der Stelle j von sensors zur ID aus currentId passt
            {
                // Der Platz in tempMeasuredValue wird gegebenenfalls erweitert
                if (tempCount >= tempCapacity)
                {
                    tempCapacity += 10; // Die Kapazität wird immer um 10 weitere Plätze erhöht
                    tempMeasuredValue = (short *)realloc(tempMeasuredValue, tempCapacity * sizeof(short));
                    if (tempMeasuredValue == NULL)
                    {
                        printf("Fehler bei der Speicherreservierung.\n");
                        free(tempMeasuredValue);
                        free(sensorIds);
                        return EXIT_FAILURE;
                    }
                }
                tempMeasuredValue[tempCount] = sensors[j].measuredValue; // Speichern des Messwerts des aktuellen Sensors
                tempCount++;
            }
        }

        // Reduzieren des tempMeasuredValue Arrays auf die tatsächliche Anzahl der gemessenen Werte
        tempMeasuredValue = (short *)realloc(tempMeasuredValue, tempCount * sizeof(short));
        if (tempMeasuredValue == NULL)
        {
            printf("Fehler beim freigeben des Speichers.");
            free(tempMeasuredValue);
            free(sensorIds);
            return EXIT_FAILURE;
        }

        // Verarbeitung der Sensordaten
        analyzeSensorData(sensors, sizeOfSensors, tempMeasuredValue, tempCount, numbersOfSensors, currentId, userInput);
        free(tempMeasuredValue);
    }

    free(sensorIds);
}

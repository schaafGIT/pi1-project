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
// Datum: 19.12.2023
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "project.h"

void processSensorData(sensorData_t *sensors, int sizeOfSensors)
{
    int initialCapacity = 10;
    int numbersOfSensors; // Anzahl der enthaltenden Sensoren im dynamischen Array sensors
    bool userInput; // Variabel zur Speicherung der Usereingabe von askUser()
    char *sensorIds = extractSensorIds(sensors, sizeOfSensors, &numbersOfSensors); // Dynamisches Array mit alle Sensor-IDs
    char currentId;
    int tempCapacity;
    int tempCount;

    if (sensorIds == NULL)
    {
        // Fehler bei der Extraktion der Sensor-IDs
        printf("Fehler bei der Extraktion der Sensor-IDs.");
        return 1;
    }

    userInput = askUser(); // Anfage an den User, ob der Mittelwert oder Median genutzt werden soll

    for (int i = 0; i < numbersOfSensors; i++)
    {
        currentId = sensorIds[i];
        tempCapacity = 10;
        tempCount = 0;
        short *tempMeasuredValue = (short *)malloc(tempCapacity * sizeof(short));

        if (tempMeasuredValue == NULL)
        {
            // Fehler bei der Speicherreservierung
            printf("Fehler bei der Allokation.");
            free(sensorIds);
            return 1;
        }

        for (int j = 0; j < sizeOfSensors; j++)
        {
            if (sensors[j].id == currentId)
            {
                if (tempCount >= tempCapacity)
                {
                    tempCapacity += 10;
                    tempMeasuredValue = (short *)realloc(tempMeasuredValue, tempCapacity * sizeof(short));
                    if (tempMeasuredValue == NULL)
                    {
                        // Fehler bei der Speichererweiterung
                        free(tempMeasuredValue);
                        free(sensorIds);
                        return 1;
                    }
                }
                // Speichern des measuredValue des aktuellen Sensors
                tempMeasuredValue[tempCount] = sensors[j].measuredValue;
                tempCount++;
            }
        }

        // Reduzieren des tempMeasuredValue Arrays auf die tatsächliche Anzahl der gemessenen Werte
        tempMeasuredValue = (short *)realloc(tempMeasuredValue, tempCount * sizeof(short));
        if (tempMeasuredValue == NULL)
        {
            // Fehler beim Kürzen des Arrays
            printf("Fehler beim freigeben des Speichers.");
            free(tempMeasuredValue);
            free(sensorIds);
            return 1;
        }
        // Verarbeitung der Sensordaten
        analyzeSensorData(sensors, sizeOfSensors, tempMeasuredValue, tempCount, numbersOfSensors, currentId, userInput);
        free(tempMeasuredValue);
    }
    free(sensorIds);
}

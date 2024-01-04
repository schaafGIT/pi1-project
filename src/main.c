// Dateiname: main.c
// Die Funktion erstellt zuerst eine Variable sizeOfSensors, die für das dynamische Array sensors genutzt wird. Die Variable
// gibt die Anzahl der enthaltenden Elemente von sensors an. Der Wert wird als Parameter für die aufgerufenen Funktionen genutzt.
// Es wird mit der Funktion readData() aus einer Datei processData.txt dynamisch Sensordaten ausgelesen, die in sensors gespeichert
// werden. Die Funktion processSensorData() verarbeitet die Daten anschließend und gibt das Ergebnis in der Konsole aus. Am Ende wird
// noch der benötigte Speicherbereich für sensors wieder freigegeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main()
{
    int sizeOfSensors;                                // Für Anzahl der enthaltenden Elemente im dynamischen Array sensor
    sensorData_t *sensors = readData(&sizeOfSensors); // Daten aus processData.txt auslesen
    processSensorData(sensors, sizeOfSensors);        // Daten aus processData.txt verarbeiten und ausgeben
    free(sensors);
    printf("\n");                                     // Zeilenumbruch für die Ausgabe in der Konsole

    return EXIT_SUCCESS;
}

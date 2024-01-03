// Dateiname: main.c
// Die Funktion erstellt zuerst eine Variable sizeOfSensors, die für das dynamische Array sensors genutzt wird. Die Variable
// gibt die Anzahl der enthaltenden Elemente von sensors an. Der Wert wird als Parameter für die aufgerufenen Funktionen genutzt.
// Es wird mit der Funktion readData() aus einer Datei processData.txt dynamisch Sensordaten ausgelesen, die in sensors gespeichert
// werden. Die Funktion processSensorData() verarbeitet die Daten anschließend und gibt das Ergebnis in der Konsole aus. Am Ende wird
// noch der benötigte Speicherbereich für sensors wieder freigegeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 02.01.2024
// Version: 1.0

#include <stdio.h>
#include "project.h"

int main()
{
    int sizeOfSensors; // Die Anzahl der enthaltenden Elemente im dynamischen Array sensor
    sensorData_t *sensors = readData(&sizeOfSensors);
    processSensorData(sensors, sizeOfSensors);
    free(sensors);
    printf("\n");
    
    return 0;
}
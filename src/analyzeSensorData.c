// Dateiname: analyzeSensorData.c
// Die Funktion erzeugt zuerst eine Varable temp vom Typ output_t, die zur temporären Speicherung genutzt wird. Dort wird sowohl
// die ID des aktuellen Sensors gespeichert, die jeweiligen Grenzwerte und die Zählervariablen für das Überschreiten der Grenzwerte.
// Zuerst werden die ID und die Grenzwerte des passenden Sensors an temp übergeben. Daraufhin werden die Zählervariablen auf null
// gesetzt. Nur werden die Messwerte mit den Grenzwerten verglichen und anschließend an writeData() übergeben, welche die Messwerte
// auf der Konsole ausgeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#include "project.h"

void analyzeSensorData(sensorData_t *sensors, int size, short *tempMeasuredValue, int CountOfTempMeasuredValue, int numbersOfSensors, int currentId, char userInput)
{
    outputData_t temp; // Zur temporären Speicherung und der späteren Ausgabe
    short value;       // Zum Speichern des Rückgabewerts von mean() oder median()

    // Beschaffung der Grenzwerte für den jeweiligen Sensor
    for (int i = 0; i < size; i++)
    {
        if (sensors[i].id = currentId)
        {
            temp.id = currentId;
            temp.warningLow = sensors[i].warningLow;
            temp.warningHigh = sensors[i].warningHigh;
            temp.alarmLow = sensors[i].alarmLow;
            temp.alarmHigh = sensors[i].alarmHigh;
            break;
        }
    }

    // Zählervariabeln werden mit null initialisiert
    temp.countWarningHigh = 0;
    temp.countWarningLow = 0;
    temp.countAlarmHigh = 0;
    temp.countAlarmLow = 0;

    // Auswertung der Messwerte
    for (int i = 0; i < CountOfTempMeasuredValue - 2; i++) // Überprüft alle Messwerte außer Messwert 1 und 2
    {   
        // Berechnung des Median oder Mittelwerts
        if (userInput)
        {
            value = mean(*(tempMeasuredValue + i), *(tempMeasuredValue + (i + 1)), *(tempMeasuredValue + (i + 2)));
        }
        else
        {
            value = median(*(tempMeasuredValue + i), *(tempMeasuredValue + (i + 1)), *(tempMeasuredValue + (i + 2)));
        }

        // Den berechneten Wert value mit den Grenzwerten vergleichen
        if (value >= temp.warningHigh)
        {
            temp.countWarningHigh++;
        }
        else if (value <= temp.warningLow)
        {
            temp.countWarningLow++;
        }
        else if (value > temp.alarmHigh)
        {
            temp.countAlarmHigh++;
        }
        else if (value < temp.alarmLow)
        {
            temp.countAlarmLow++;
        }
    }

    for (int i = 0; i < 2; i++) // Der 1 und 2 Messwert wird überprüft (hier können keine 3 letzte Messwerte verwendet werden)
    {
        if (tempMeasuredValue[i] >= temp.warningHigh)
        {
            temp.countWarningHigh++;
        }
        else if (tempMeasuredValue[i] <= temp.warningLow)
        {
            temp.countWarningLow++;
        }
        else if (tempMeasuredValue[i] > temp.alarmHigh)
        {
            temp.countAlarmHigh++;
        }
        else if (tempMeasuredValue[i] < temp.alarmLow)
        {
            temp.countAlarmLow++;
        }
    }

    // Ausgabe der Ergebnisse auf der Konsole
    writeData(temp);
}

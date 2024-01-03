// Dateiname: analyzeSensorData.c
// Die Funktion erzeugt zuerst eine Varable temp vom Typ output_t, die zur temporären Speicherung genutzt wird. Dort wird sowohl
// die ID des aktuellen Sensors gespeichert, die jeweiligen Grenzwerte und die Zählervariablen für das Überschreiten der Grenzwerte.
// Zuerst werden die ID und die Grenzwerte des passenden Sensors an temp übergeben. Daraufhin werden die Zählervariablen auf null
// gesetzt. Nur werden die Messwerte mit den Grenzwerten verglichen und anschließend an writeData() übergeben, welche die Messwerte
// auf der Konsole ausgeben.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 27.12.2023
// Version: 1.0

#include "stdbool.h"
#include "project.h"

void analyzeSensorData(sensorData_t *sensor, int size, short *tempMeasuredValue, int CountOfTempMeasuredValue, int numbersOfSensors, int currentId, bool userInput)
{
    outputData_t temp; // Zur temporenren Speicherung und der späteren Ausgabe
    short value;       // Zum Speichern des Rückgabewerts von mean() oder median()

    // Beschaffung der Grenzwerte
    for (int i = 0; i < size; i++)
    {
        if (sensor[i].id = currentId)
        {
            temp.id = currentId;
            temp.warningLow = sensor[i].warningLow;
            temp.warningHigh = sensor[i].warningHigh;
            temp.alarmLow = sensor[i].alarmLow;
            temp.alarmHigh = sensor[i].alarmHigh;
            break;
        }
    }

    // Auswertung der Messdaten
    temp.countWarningHigh = 0;
    temp.countWarningLow = 0;
    temp.countAlarmHigh = 0;
    temp.countAlarmLow = 0;

    if (CountOfTempMeasuredValue <= 2) // Wenn nur 1 oder 2 Messwerte vorliegen (hier keine 3 letzte Messwerte verwendet werden)
    {
        for (int i = 0; i < CountOfTempMeasuredValue; i++)
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
    }
    else // Wenn mehr als 2 Messwerte vorliegen
    {
        // Wenn nur 1 oder 2 Messwerte vorliegen
        for (int i = 0; i < CountOfTempMeasuredValue - 2; i++)
        {
            // Berechnung des Median oder Mittelwerts
            if (userInput)
            {
                value = median(*tempMeasuredValue + i, *tempMeasuredValue + (i + 1), *tempMeasuredValue + (i + 2));
            }
            else
            {
                value = mean(tempMeasuredValue + 1, tempMeasuredValue + (i + 1), tempMeasuredValue + (i + 2));
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

        // Der 1 und 2 Messwert wird überprüft (hier keine 3 letzte Messwerte verwendet werden)
        for (int i = 0; i < 2; i++)
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
    }

    writeData(temp); // Ausgabe der Ergebnisse auf der Konsole
}

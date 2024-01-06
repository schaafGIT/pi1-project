// Dateiname: writeData.c
// Der Funktion wird eine Varable vom Typ outputData_t übergeben, die in der struct.h definiert ist.
// Nun gibt die Funktion immer die Sensor-ID aus und die dazugehörigen gezählten Grenzüberschreitungen
// in der Konsole aus.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 06.01.2024
// Version: 1.0

#include <stdio.h>
#include "project.h"

void writeData(outputData_t data)
{
    printf("------------------------------------------------------------------------------------------\n\n");
    printf("   #%c", data.id);
    printf(" - Warning Low: %hd", data.countWarningLow);
    printf("    Warning High: %hd", data.countWarningHigh);
    printf("    Alarm Low: %hd", data.countAlarmLow);
    printf("    Alarm High: %hd\n\n", data.countAlarmHigh);
}

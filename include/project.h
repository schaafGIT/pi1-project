// Dateiname: project.h
// Die Header-Datei enthält zwei Strukturen für die Verarbeitung der Sensordaten.
// Autoren:
//              Basher Allosh / 11224028
//              Oliver Schaaf / 11225476
// Datum: 04.01.2024
// Version: 1.0

#ifndef PROJECT_H
#define PROJECT_H

// Strukturen
typedef struct
{
    unsigned char id;
    short measuredValue;
    short warningLow;
    short warningHigh;
    short alarmLow;
    short alarmHigh;

} sensorData_t;

typedef struct
{
    char id;
    short warningLow;
    short warningHigh;
    short alarmLow;
    short alarmHigh;
    int countWarningLow;
    int countWarningHigh;
    int countAlarmLow;
    int countAlarmHigh;

} outputData_t;

// Funktionen
short mean(short firstNumber, short secondNumber, short thirdNumber);
short median(short firstNumber, short secondNumber, short thirdNumber);
void processSensorData(sensorData_t *sensors, int sizeOfSensors);
sensorData_t *readData(int *sizeOfSensors);
void writeData(outputData_t data);
void analyzeSensorData(sensorData_t *sensor, int size, short *tempMeasuredValue, int CountOfTempMeasuredValue, int numbersOfSensors, int currentId, char userInput);
char *extractSensorIds(sensorData_t *sensors, int sizeOfSensors, int *numbersOfSensors);

#endif

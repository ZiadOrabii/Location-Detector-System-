#include "GPS_module.h"
#include <string.h>

volatile char gpsSentence[GPS_BUFFER_SIZE];

volatile char latitudeRaw[20];
volatile char longitudeRaw[20];
volatile char latDirection, lonDirection;

volatile float latitudeDecimal = 0.0;
volatile float longitudeDecimal = 0.0;

void processGPSSentence(void) {
    uint8_t field = 0, i = 0, j = 0;
    for (i = 0; gpsSentence[i] != '\0'; i++) {
        if (gpsSentence[i] == ',') {
            field++;
            j = 0;
            continue;
        }

        if (field == 2) { // Latitude
            latitudeRaw[j++] = gpsSentence[i];
            latitudeRaw[j] = '\0';
        }
        else if (field == 3) { // N/S
            latDirection = gpsSentence[i];
        }
        else if (field == 4) { // Longitude
            longitudeRaw[j++] = gpsSentence[i];
            longitudeRaw[j] = '\0';
        }
        else if (field == 5) { // E/W
            lonDirection = gpsSentence[i];
        }
    }
}

static float convertToDecimalDegrees(volatile char *rawData, uint8_t isLongitude) {
    float value = 0.0;
    int degrees = 0;
    float minutes = 0.0;

    int i = 0;
    while (rawData[i] != '.' && rawData[i] != '\0') {
        i++;
    }

    if (isLongitude) {
        degrees = (rawData[0] - '0') * 100 + (rawData[1] - '0') * 10 + (rawData[2] - '0');
        for (int j = 3; j < i; j++) {
            minutes = minutes * 10 + (rawData[j] - '0');
        }
    } else {
        degrees = (rawData[0] - '0') * 10 + (rawData[1] - '0');
        for (int j = 2; j < i; j++) {
            minutes = minutes * 10 + (rawData[j] - '0');
        }
    }

    int k = i + 1;
    float frac = 0.0;
    float divisor = 10.0;
    while (rawData[k] != '\0') {
        frac += (rawData[k] - '0') / divisor;
        divisor *= 10.0;
        k++;
    }
    minutes += frac;

    value = degrees + (minutes / 60.0);

    return value;
}

void extractLatLong(void) {
    latitudeDecimal = convertToDecimalDegrees(latitudeRaw, 0);
    if (latDirection == 'S') {
        latitudeDecimal = -latitudeDecimal;
    }

    longitudeDecimal = convertToDecimalDegrees(longitudeRaw, 1);
    if (lonDirection == 'W') {
        longitudeDecimal = -longitudeDecimal;
    }
}

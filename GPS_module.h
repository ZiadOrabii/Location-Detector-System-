#ifndef GPS_MODULE_H
#define GPS_MODULE_H

#include <stdint.h>

#define GPS_BUFFER_SIZE 120

extern volatile char gpsSentence[GPS_BUFFER_SIZE];
extern volatile float latitudeDecimal;
extern volatile float longitudeDecimal;
extern volatile uint32_t gpsIndex;

extern volatile char latitudeRaw[20];
extern volatile char longitudeRaw[20];
extern volatile char latDirection;
extern volatile char lonDirection;

void processGPSSentence(void);
void extractLatLong(void);

#endif // GPS_MODULE_H

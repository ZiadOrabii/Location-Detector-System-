#ifndef DISTCALC_H
#define DISTCALC_H
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "tm4c123gh6pm.h"
#include <stdio.h>


#define EARTH_RADIUS 6371000.0  // Earth radius in meters
#define THRESHOLD 30// Maximum distance in meters

// Structure to store location data
typedef struct {
    char name[30];
    double latitude;
    double longitude;
} Location;


 extern double min_distance ;
 extern const char* nearest_place ;
extern double lat;
extern double lon;
// Function to find the nearest location within a given threshold

 
double haversine(double lat1, double lon1, double lat2, double lon2);
double toRadians(double degree);

const char* find_nearest_location(double latitude, double longitude); 




#endif

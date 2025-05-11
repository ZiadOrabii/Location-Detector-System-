#include "Calculate_Distance.h"


#define M_PI 3.14159265358979323846

// Convert degrees to radians
double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

// Haversine formula to calculate distance between two coordinates
double haversine(double lat1, double lon1, double lat2, double lon2) 
	{
    double a, c;
    double dLat = toRadians(lat2 - lat1);
    double dLon = toRadians(lon2 - lon1);
    lat1 = toRadians(lat1);
    lat2 = toRadians(lat2);

    a = sin(dLat / 2.0) * sin(dLat / 2.0) +
        cos(lat1) * cos(lat2) * sin(dLon / 2.0) * sin(dLon / 2.0);
    
    c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    return EARTH_RADIUS * c;
}



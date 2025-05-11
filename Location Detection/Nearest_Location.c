#include  "Calculate_Distance.h"
#define M_PI 3.14159265358979323846


double min_distance = 100; // Start with a value higher than the threshold
 const char* nearest_place = " WAITING ";
 double lat;
 double lon;
// List of predefined locations
Location locations[] = {
   {"Credit", 30.0635980, 31.2783555},
   {"Racing Team", 30.0631253, 31.2790277},
   {"Masged",30.0647148, 31.2802209},
   {"Hall A", 30.0642761, 31.2802518},
	 {"Hall C", 30.0637619, 31.2804942},	
	{"Modargat", 30.0640742, 31.2791216},
	{"Luban Workshop",30.0633609, 31.2797281},
};
 
// Function to find the nearest location within a given threshold
const char* find_nearest_location(double latitude, double longitude)
{
		int i;
		min_distance = 100;
		// nearest_place = "WAITING";
    for (i = 0; i < sizeof(locations) / sizeof(locations[0]); i++) {
			
        double distance = haversine(latitude, longitude, locations[i].latitude, locations[i].longitude);
		
        if (distance <= THRESHOLD && distance < min_distance) {
            	min_distance = distance;
            nearest_place = locations[i].name;
					lat=locations[i].latitude;
					lon=locations[i].longitude;
        }
				
		
    }
	return nearest_place ;
}




// {"OLD Bulding", 30.06492055742478, 31.278995260813254},
		// {"library" , 30.065266511815746, 31.280195602761456},
		//{"Nafora" , 30.065602242935654, 31.27839688833153},
	//	{"Gate 2 " , 30.064626841221965, 31.277556887165314},
		//{"Gate 3", 30.063979933945937, 31.27793031943942},
		//{"Tak3ebt msaha" , 30.065293939931998, 31.277876095767876}, 
		//{"Tak3ebt 123",30.065710978747, 31.279127757341556}
#include <string.h>
#include "date_time.h"

void get_day(int day, char *str)
{
    switch(day){
    case 0:
	str = "SUN";
	break;
    case 1:
	str = "MON";
	break;
    case 2:
	str = "TUE";
	break;
    case 3:
	str = "WED";
	break;
    case 4:
	str = "THU";
	break;
    case 5:
	str = "FRI";
	break;
    default:
	str = "SAT";
	break;
    }
}

void get_time_of_day(int hour, char *str)
{
    if (hour >=4 && hour < 10) {
	strcpy(str, "MORNING");
    } else if (hour >= 10 && hour < 18) {
	strcpy(str, "DAY");
    } else {
	strcpy(str, "NIGHT");
    }
}

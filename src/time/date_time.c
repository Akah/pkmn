#include <string.h>
#include "date_time.h"

void get_day(int day, char *str)
{
    switch(day){
    case 0:
	strcpy(str, "SUNDAY");
	break;
    case 1:
	strcpy(str, "MONDAY");
	break;
    case 2:
	strcpy(str, "TUESDAY");
	break;
    case 3:
	strcpy(str, "WEDNESDAY");
	break;
    case 4:
	strcpy(str, "THURSDAY");
	break;
    case 5:
	strcpy(str,"FRIDAY");
	break;
    default:
	strcpy(str, "SATURDAY");
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

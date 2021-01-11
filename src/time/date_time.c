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

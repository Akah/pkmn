#include <stdio.h>
#include <time.h>

time_t t;

char *current_day()
{
    t = time(NULL);
    struct tm *tm = localtime(&t);
    char *day_string[11];

    switch (tm->tm_wday) {
    case 0:
	*day_string = "SUNDAY";
    case 1:
	*day_string = "MONDAY";
    case 2:
	*day_string = "TUESDAY";
    case 3:
	*day_string = "WEDNESDAY";
    case 4:
	*day_string = "THURSDAY";
    case 5:
	*day_string = "FRIDAY";
    case 6:
	*day_string = "SATURDAY";
    default:
	*day_string = "N/A";
    }

    return *day_string;
}

char *current_time()
{
    t = time(NULL);
    char *time_string = "00:00";
    struct tm *tm = localtime(&t);
    sprintf(time_string, "%d:%d", tm->tm_hour, tm->tm_min);
    return time_string;
}



#include <SDL2/SDL.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#include "utils.h"

void _utils_debug(char* msg)
{
    char t_str[51];
    time_t t;
    struct tm* tm;
    t = time(NULL);
    tzset();
    strftime(t_str, sizeof(t_str) - 1, "%FT%T", localtime(&t));
    printf("[%s]: %s\n", t_str, msg);
}

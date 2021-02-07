#include "common.h"
#include "console.h"
#include "utils.h"

/**
 * ref: https://stackoverflow.com/a/9210560
 */
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result) {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token) {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int read_console()
{
    for (;;) {
	char input[128];

	printf("$ ");
	fgets(input, 128, stdin);
	//dirty fix to remove \n from end of last input
	char** buffer = str_split(str_split(input, (char)10)[0], ' ');

	int i;
        for (i = 0; *(buffer + i); i++)
        {
            printf("[%d]%s\n", i, *(buffer + i));
            //free(*(buffer + i));
        }
	// TODO: error handling for input
	// TODO: default handling for input

	char msg[40];
	if (strcmp(buffer[0], "add") == 0) {
	    if (buffer[1] && buffer[2]) {
		printf("%d + %d = %d\n",
		       atoi(buffer[1]),
		       atoi(buffer[2]),
		       atoi(buffer[1]) + atoi(buffer[2]));
	    } else {
		printf("not enough parameters passed for function\n");
	    }
	    continue;
	}

	if (strcmp(buffer[0], "print") == 0) {
	    if (strcmp(buffer[1], "quit") == 0) {
		sprintf(msg, "%s: %d", buffer[1], quit);
		_utils_debug(msg);
	    }
	    continue;
	}

	if (strcmp(buffer[0], "set") == 0) {
	    if (strcmp(buffer[1], "quit") == 0) {
		quit = atoi(buffer[2]);
		sprintf(msg, "%s: %d", buffer[1], quit);
		_utils_debug(msg);
	    }
	    continue;
	}

	sprintf(msg, "No command called %s", buffer[0]);
	_utils_debug(msg);
    }

    return 0;
}

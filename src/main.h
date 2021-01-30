#include "common.h"

#ifdef WINDOWS
int WinMain(int argc, char *argv[]);
#else
int main(int argc, char *argv[]);
#endif

void main_loop();

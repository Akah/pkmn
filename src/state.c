#include "common.h"
#include "state.h"

void set_current_state(enum states new_state)
{
    printf("old state %d\n", state->current_state);
    state->current_state = new_state;
    printf("current state %d\n", state->current_state);
}

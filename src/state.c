#include "common.h"
#include "state.h"
#include "utils.h"

void set_current_state(enum states new_state)
{
    char current_state_string[64];
    sprintf(current_state_string, "old state %d\n", state->current_state);
    _utils_debug(current_state_string);
    state->current_state = new_state;
    sprintf(current_state_string, "current state %d\n", state->current_state);
    _utils_debug(current_state_string);
}

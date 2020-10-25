#include "common.h"
#include "state.h"

void set_current_state(State *pState, enum states new_state)
{
    printf("old state %d\n", pState->current_state);
    pState->current_state = new_state;
    printf("current state %d\n", pState->current_state);
}

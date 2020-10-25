#ifndef STATE_H
#define STATE_H

enum states {
    OVERWORLD,
    MENU,
    INTRO,
    START_MENU
};

enum start_menu_items {
    NEW_GAME,
    CONTINUE,
    SETTINGS
};

enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

enum menu_items {
    POKEDEX,
    POKEMON,
    BAG,
    PLAYER,
    OPTIONS,
    SAVE,
    EXIT
};

struct character {
    int x_pos;
    int y_pos;
    int moving;
    enum direction direction;
};

typedef struct {
    enum start_menu_items items;
} Start_menu;

typedef struct {
    int active;
} Overworld;

typedef struct {
    enum states current_state;
    Overworld overworld;
    Start_menu start_menu;
    int test;
} State;

#endif


#ifndef UI_H
#define UI_H

#include <raylib.h>

// this is jist me defining states

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_TOURNAMENT
} GameState;

//  Function prototypes
void DrawGraphicalMenu(void);
GameState UpdateGraphicalMenu(void);

#endif

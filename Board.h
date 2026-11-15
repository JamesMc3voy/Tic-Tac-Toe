#ifndef UI_H
#define UI_H
#ifndef BOARD_H
#define BOARD_H
#include <raylib.h>

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_TOURNAMENT
} GameState;

void DrawGraphicalMenu(void);
GameState UpdateGraphicalMenu(void);


void DrawBoard(int start_x_vert, int start_y_vert, int start_x_horiz, int start_y_horiz, int n);

#endif
#endif

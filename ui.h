#ifndef UI_H
#define UI_H

#include <raylib.h>

// this is jist me defining states

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_TOURNAMENT
} GameState;
int show_main_menu(void);
int choose_board_size(void);  //I added this because of the Implicit definition error
//  Function prototypes
void DrawGraphicalMenu(void);
GameState UpdateGraphicalMenu(void);

#endif

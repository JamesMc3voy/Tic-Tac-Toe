#ifndef UI_H
#define UI_H

#include <raylib.h>
#include <stdbool.h>
// Added HUD and Menu button declarations so main.c can draw them cleanly
void DrawGameHUD(int roundNumber, int score1, int score2, int isTournament);
bool UpdateAndDrawMenuButton(void);
typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_TOURNAMENT
} GameState;

GameState UpdateGraphicalMenu(void);
void DrawGraphicalMenu(void);



#endif

#include <raylib.h>
#include "ui.h"

// Define Menu Options
static Rectangle btnPvP = { 350, 300, 300, 50 };
static Rectangle btnTournament = { 350, 370, 300, 50 };
static Rectangle btnQuit = { 350, 440, 300, 50 };

void DrawGraphicalMenu(void)
{
    Vector2 mousePos = GetMousePosition();

    // Title & Subtitle
    DrawText("TIC TAC TOE", 345, 120, 40, DARKBLUE);

    // 1. PvP Button (changes color on hover)
    Color colPvP = CheckCollisionPointRec(mousePos, btnPvP) ? SKYBLUE : LIGHTGRAY;
    DrawRectangleRec(btnPvP, colPvP);
    DrawText("   Free Play", btnPvP.x + 70, btnPvP.y + 15, 20, DARKGRAY);

    // 2. Tournament Button
    Color colTourn = CheckCollisionPointRec(mousePos, btnTournament) ? SKYBLUE : LIGHTGRAY;
    DrawRectangleRec(btnTournament, colTourn);
    DrawText("Tournament Mode", btnTournament.x + 55, btnTournament.y + 15, 20, DARKGRAY);

    // 3. Quit Button
    Color colQuit = CheckCollisionPointRec(mousePos, btnQuit) ? MAROON : RED;
    DrawRectangleRec(btnQuit, colQuit);
    DrawText("Quit Game", btnQuit.x + 95, btnQuit.y + 15, 20, WHITE);
}

GameState UpdateGraphicalMenu(void)
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mousePos = GetMousePosition();

        if (CheckCollisionPointRec(mousePos, btnPvP)) {
            return STATE_PLAYING;
        }
        else if (CheckCollisionPointRec(mousePos, btnTournament)) {
            return STATE_TOURNAMENT;
        }
        else if (CheckCollisionPointRec(mousePos, btnQuit)) {
            CloseWindow();
        }
    }
    return STATE_MENU;
}

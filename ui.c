#include <raylib.h>
#include <stdio.h>
#include "ui.h"

static Rectangle btnPvP = { 350, 300, 300, 50 };
static Rectangle btnTournament = { 350, 370, 300, 50 };
static Rectangle btnQuit = { 350, 440, 300, 50 };

// Soft colors for cards, borders, and buttons
static const Color BG_CARD        = { 255, 255, 255, 255 };
static const Color BORDER_COLOR   = { 203, 213, 225, 255 };
static const Color TITLE_COLOR    = { 30, 41, 59, 255 };
static const Color SUBTITLE_COLOR = { 100, 116, 139, 255 };
static const Color BTN_PRIMARY    = { 59, 130, 246, 255 };
static const Color BTN_HOVER      = { 37, 99, 235, 255 };
static const Color BTN_QUIT       = { 239, 68, 68, 255 };
static const Color BTN_QUIT_HOVER = { 220, 38, 38, 255 };

// Draws a rounded box with a soft shadow and thin border
static void DrawRoundedBox(Rectangle rect, float roundness, Color fill, Color border) {
    DrawRectangleRounded((Rectangle){ rect.x + 2, rect.y + 3, rect.width, rect.height }, roundness, 8, Fade(BLACK, 0.08f));
    DrawRectangleRounded(rect, roundness, 8, fill);
    DrawRectangleRoundedLinesEx(rect, roundness, 8, 1.5f, border);
}

// Draws a button with hover color and centered text
static void DrawMenuButton(Rectangle rect, const char *text, Color fill, Color hoverFill, Color textColor) {
    bool hovered = CheckCollisionPointRec(GetMousePosition(), rect);
    DrawRoundedBox(rect, 0.25f, hovered ? hoverFill : fill, hovered ? hoverFill : BORDER_COLOR);

    int fontSize = 20;
    int textX = (int)(rect.x + (rect.width - MeasureText(text, fontSize)) / 2.0f);
    int textY = (int)(rect.y + (rect.height - fontSize) / 2.0f);
    DrawText(text, textX, textY, fontSize, textColor);
}

void DrawGraphicalMenu(void)
{
    // Centered the title and added a short subtitle below it
    const char *title = "TIC TAC TOE";
    DrawText(title, (1000 - MeasureText(title, 44)) / 2, 120, 44, TITLE_COLOR);

    const char *subtitle = "Choose a mode";
    DrawText(subtitle, (1000 - MeasureText(subtitle, 20)) / 2, 175, 20, SUBTITLE_COLOR);

    // Added a rounded container box behind the three menu buttons
    Rectangle panel = { 325.0f, 280.0f, 350.0f, 230.0f };
    DrawRoundedBox(panel, 0.08f, BG_CARD, BORDER_COLOR);

    DrawMenuButton(btnPvP, "Freeplay", BTN_PRIMARY, BTN_HOVER, WHITE);
    DrawMenuButton(btnTournament, "Tournament Mode", BTN_PRIMARY, BTN_HOVER, WHITE);
    DrawMenuButton(btnQuit, "Quit Game", BTN_QUIT, BTN_QUIT_HOVER, WHITE);
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

// Draws the round, score, and return hint in a matching rounded card
void DrawGameHUD(int roundNumber, int score1, int score2, int isTournament)
{
    Rectangle hudCard = { 16.0f, 14.0f, 310.0f, 102.0f };
    DrawRoundedBox(hudCard, 0.14f, BG_CARD, BORDER_COLOR);

    char roundText[50];
    char scoreText[50];
    sprintf(roundText, "Round: %d (%s)", roundNumber, isTournament ? "Tournament" : "Freeplay");
    sprintf(scoreText, "Score - X: %d | O: %d", score1, score2);

    DrawText(roundText, 28, 24, 18, TITLE_COLOR);
    DrawText(scoreText, 28, 50, 18, TITLE_COLOR);
    DrawText("Press ESC to return to Menu", 28, 80, 15, SUBTITLE_COLOR);
}

// Draws a clickable Menu button on the game screen and returns true when clicked
bool UpdateAndDrawMenuButton(void)
{
    Rectangle menuBtn = { 850.0f, 20.0f, 120.0f, 44.0f };
    Color hoverBg = { 226, 232, 240, 255 };
    DrawRoundedBox(menuBtn, 0.22f, CheckCollisionPointRec(GetMousePosition(), menuBtn) ? hoverBg : BG_CARD, BORDER_COLOR);

    const char *label = "Menu";
    int textX = (int)(menuBtn.x + (menuBtn.width - MeasureText(label, 20)) / 2.0f);
    int textY = (int)(menuBtn.y + (menuBtn.height - 20) / 2.0f);
    DrawText(label, textX, textY, 20, TITLE_COLOR);

    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), menuBtn);
}


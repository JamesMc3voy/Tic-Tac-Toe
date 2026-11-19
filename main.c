#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// Include headers
#include "Board.h"
#include "Buttons.h"
#include "MouseClicks.h"
#include "Winner.h"
#include "ui.h"

int main()
{
    // 1. Initialize the Raylib graphical window first
    InitWindow(1000, 900, "Tic Tac Toe - Member 3 UI");
    SetTargetFPS(60);

    GameState state = STATE_MENU;

    // Board setup variables
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;
    int n = 3; // Default board size (can be changed via board size buttons)
    int turn = 1;
    int winner = 4;
    // Inside main() where variables are initialized:
    int scoreX = 0;
    int scoreO = 0;
    int roundNumber = 1;
    char scoreText[50];
    char roundText[50];

    BoardSquares BoardSize[2];
    BoardSquares Buttons[4 * 4]; // Max amount of squares
    BoardSquares players[2]; // Select player/bot buttons

    BoardButtons(Buttons, n);
    BoardSizeButtons(BoardSize);
    SelectPlayerButtons(players);

    while (!WindowShouldClose())
    {
        if (state == STATE_MENU)
        {
            // Check for graphical menu clicks
            state = UpdateGraphicalMenu();                         // I REMOVED show_main_menu and choose_board_size it caused the errors and moved InitWindow to the beginning

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawGraphicalMenu();
            EndDrawing();
        }
        else if (state == STATE_PLAYING)
        {
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = STATE_MENU;
            }

            // Handle user interactions
            BoardSizeSelect(BoardSize, Buttons, &n);

            // Check winner (assuming CheckWinner3x3 updates 'winner': 1 for X, 2 for O, 3 for draw, 4 for ongoing)
            CheckWinner3x3(Buttons, n, &winner);

            // If a round is won or drawn (assuming 3 is draw, or you check for draw conditions)
            if (winner == 1 || winner == 2 || winner == 3)
            {
                if (winner == 1) scoreX++;
                if (winner == 2) scoreO++;

                roundNumber++;

                // Reset the board and state for the next round
                BoardButtons(Buttons, n);
                turn = 1;
                winner = 4;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawBoardButtons(Buttons, n);
            GameSquareSelect(Buttons, n, &turn);
            DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n);
            DrawBoardSizeButtons(BoardSize);
            DrawSelectPlayerButtons(players);

            // Display Rounds and Scores on screen
            sprintf(roundText, "Round: %d", roundNumber);
            sprintf(scoreText, "Score - X: %d | O: %d", scoreX, scoreO);
            DrawText(roundText, 20, 60, 20, DARKGRAY);
            DrawText(scoreText, 20, 90, 20, DARKGRAY);

            DrawText("Press ESC to return to Menu", 20, 20, 18, GRAY);

            EndDrawing();
        }
            }

            // Handle user interactions
            BoardSizeSelect(BoardSize, Buttons, &n);

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawBoardButtons(Buttons, n);
            GameSquareSelect(Buttons, n, &turn);
            DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n);
            DrawBoardSizeButtons(BoardSize);
            DrawSelectPlayerButtons(players);
            CheckWinner3x3(Buttons, n, &winner);

            DrawText("Press ESC to return to Menu", 20, 20, 18, GRAY);

            EndDrawing();
        }
        else if (state == STATE_TOURNAMENT)
        {
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = STATE_MENU;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("TOURNAMENT MODE", 320, 300, 30, DARKGREEN);
            DrawText("Press ESC to return to Menu", 360, 360, 18, GRAY);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}

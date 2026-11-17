#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

//include headers
#include "Board.h"
#include "Buttons.h"
#include "MouseClicks.h"
#include "Winner.h"
#include "ui.h" //I've Added my new Ui things - malek.

int main()
{

    // 1. Run your console UI menu first!
    int choice = show_main_menu();

    if (choice == 5) {
        printf("Quitting game.\n");
        return 0;
    }

    int board_choice = choose_board_size(); // Returns 3 or 4
    int n = board_choice;

    // 2. Now launch the Raylib graphical window with the chosen settings
    //co ordinates for top left of board
    InitWindow(1000, 900, "Tic Tac Toe - Member 3 UI");
    SetTargetFPS(60);

    GameState state = STATE_MENU;

    // Board setup variables
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;
    //int n =3;//line 24 board choice
    int turn = 1;
    int winner = 4;                            //I Maintained your code to be 99.9% the same so all your logic is the same - malek

    BoardSquares BoardSize[2];
    BoardSquares Buttons[4 * 4]; // this is the max amount of squares we can have
    BoardSquares players[2]; // only two buttons to choose from

    //created raylib window, size 900x900
    InitWindow(1000,900,"Tic Tac Toe");

    BoardButtons(Buttons, n);
    BoardSizeButtons(BoardSize);

    while (!WindowShouldClose())
    {
        if (state == STATE_MENU)
        {
            // Check for menu clicks
            state = UpdateGraphicalMenu();
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


            DrawSelectPlayerButtons(players);
            BoardSizeSelect(BoardSize, Buttons, &n);

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawBoardButtons(Buttons, n);
            GameSquareSelect(Buttons, n, &turn);
            DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n);
            DrawBoardSizeButtons(BoardSize);
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

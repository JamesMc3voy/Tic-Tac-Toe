#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "Board.h"
#include "Buttons.h"
#include "MouseClicks.h"
#include "Winner.h"
#include "ui.h" // Include your UI header

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
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;
    int turn = 1;
    int winner;

    InitWindow(1000, 900, "Tic Tac Toe");
    BoardSquares BoardSize[2];
    BoardSquares Buttons[Max_N * Max_N];

    BoardButtons(Buttons, n);
    BoardSizeButtons(BoardSize);

    while(!WindowShouldClose())
    {
        BoardSizeSelect(BoardSize, Buttons, &n);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawBoardButtons(Buttons, n);
        GameSquareSelect(Buttons, n, &turn);
        DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n);
        DrawBoardSizeButtons(BoardSize);

        CheckWinner3x3(Buttons, n, &winner);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

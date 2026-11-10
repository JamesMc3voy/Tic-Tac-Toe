#include <stdio.h>
#include <stdlib.h>
#include<raylib.h>

#include"Board.h"

int main()
{
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;

    InitWindow(900,900,"Tic Tac Toe");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawBoard(start_x_vert,start_y_vert,start_x_horiz,start_y_horiz);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

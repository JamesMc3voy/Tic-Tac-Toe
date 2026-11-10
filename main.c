#include <stdio.h>
#include <stdlib.h>
#include<raylib.h>

int main()
{

    InitWindow(900,900,"Tic Tac Toe");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include"Board.h"
#include"Buttons.h"

int main()
{
    //Co-ordibnates for the top left of the board
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;

    //created raylib window, size 900x900
    InitWindow(900,900,"Tic Tac Toe");

    while(!WindowShouldClose())
    {
        BeginDrawing(); //enbled drawing
        ClearBackground(RAYWHITE); // cleared background

        BoardButtons();//Call squares for each box on the board

        DrawBoard(start_x_vert,start_y_vert,start_x_horiz,start_y_horiz); //called board function to draw the board

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

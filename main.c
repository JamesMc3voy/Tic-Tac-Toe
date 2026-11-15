#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#include"Board.h"
#include"Buttons.h"
#include"MouseClicks.h"
#include"Winner.h"

int main()
{
    //Co-ordibnates for the top left of the board
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;
    int n =3;
    int turn = 1;
    int winner; //0 draw, 1 player 1 and 2 is player 2, 4= no outcome yet

    //created raylib window, size 900x900  // test for matthew
    InitWindow(1000,900,"Tic Tac Toe");
    BoardSquares BoardSize[2];
    BoardSquares Buttons[Max_N*Max_N];

    BoardButtons(Buttons,n);//Call squares for each box on the board
    BoardSizeButtons(BoardSize);

    while(!WindowShouldClose())
    {
        BoardSizeSelect(BoardSize,Buttons,&n);// call the fuction change board size

        BeginDrawing(); //enbled drawing

        ClearBackground(RAYWHITE); // cleared background

        DrawBoardButtons(Buttons,n);//call the funtion to draw the buttons for the user to choose

        GameSquareSelect(Buttons, n, &turn);//call the funtion to check if a box was chosen

        DrawBoard(start_x_vert,start_y_vert,start_x_horiz,start_y_horiz,n); //called board function to draw the board

        DrawBoardSizeButtons(BoardSize);//draw the size selection Buttons

        CheckWinner3x3(Buttons, n, &winner);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}

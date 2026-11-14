#include<raylib.h>
#include"Buttons.h"
void BoardButtons(BoardSquares Buttons[])  // create the boxes for the structure
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            Buttons[i*n+j].box = (Rectangle){100+100*i,100+100*j,100,100};
            Buttons[i*n + j].state = 0;
        }
    }
}

void DrawBoardButtons(BoardSquares Buttons[])
{
    for(int k = 0; k<n*n; k++)
    {
        DrawRectangleRec(Buttons[k].box,WHITE);//Draw white Squares between the boxes of the board
        int Centre_x = Buttons[k].box.x +50;//Determine the centre of the boxes
        int Centre_y = Buttons[k].box.y +50;
    }
}//prints row by column


//board size buttons

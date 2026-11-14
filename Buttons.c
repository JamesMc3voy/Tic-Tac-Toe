#include<raylib.h>
#include"Buttons.h"
void BoardButtons(BoardSquares Buttons[],int n)  // create the boxes for the structure
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

void DrawBoardButtons(BoardSquares Buttons[],int n)
{
    for(int k = 0; k<n*n; k++)
    {
        DrawRectangleRec(Buttons[k].box,WHITE);//Draw white Squares between the boxes of the board
        int Centre_x = Buttons[k].box.x +50;//Determine the centre of the boxes
        int Centre_y = Buttons[k].box.y +50;
    }
}//prints row by column


void BoardSizeButtons(BoardSquares BoardSize[])//create the squares
{
    for(int i = 0; i<2; i++)
    {
        BoardSize[i].box = (Rectangle){600+100*i*2,100,100,50};
        BoardSize[i].state = 0; //0 is not selected, 1 is selected
    }
}

void DrawBoardSizeButtons(BoardSquares BoardSize[])//draw the buttons for the size selection
{
    const char *Labels[2] = {"3x3","4x4"};//possible texts for either box
    for(int i =0; i<2; i++)
    {
        DrawRectangleRec(BoardSize[i].box, RED);
        DrawText(Labels[i],BoardSize[i].box.x + 25, BoardSize[i].box.y +12, 24, WHITE);//write the text for the box
    }
}

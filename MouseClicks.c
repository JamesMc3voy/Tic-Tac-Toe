#include "Buttons.h"
#include"Board.h"
void BoardSizeSelect(BoardSquares BoardSize[], BoardSquares Buttons[], int *n)
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 Cursor = GetMousePosition();
            if (CheckCollisionPointRec(Cursor, BoardSize[0].box)) {*n = 3; BoardButtons(Buttons, *n);}// check if the cursor was pressed within the box
            //check both boxes, and assign the appropriate value to n and give n to the other funtions that are needed
            if (CheckCollisionPointRec(Cursor, BoardSize[1].box)) { *n = 4; BoardButtons(Buttons, *n); }
        }
}

void GameSquareSelect(BoardSquares Buttons[],int n,int *turn)//check eack box on the board whetehr its free and if the user clicks it
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))//is cursor clicked
        {
            Vector2 Cursor = GetMousePosition();//find the cursor
            for(int k=0;k<n*n;k++)
            {
                if (CheckCollisionPointRec(Cursor, Buttons[k].box))//check if cursor was in the box when clicked
                {
                    if(Buttons[k].state ==0)//if the box is free
                    {
                        Buttons[k].state = *turn;//update the stae for whoever turn it was
                        *turn = 3 - *turn;//update the turn
                    }
                }
            }
        }
    for (int i =0;i<n*n;i++)
    {
        int Centre_x = Buttons[i].box.x +50;//Determine the centre of the boxes
        int Centre_y = Buttons[i].box.y +50;
        switch(Buttons[i].state){//using the for loop above, check the state of eack box, and draw the apprporiate move
        case 1:
            DrawX(Centre_x,Centre_y);//call the draw x func6tion
            break;
        case 2:
            DrawO(Centre_x,Centre_y);//call the draw O function
            break;
        case 0://do nothing
            default:
        }
    }
}

void PlayerSelect(BoardSquares players[],int *p)
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 Cursor = GetMousePosition();
            if (CheckCollisionPointRec(Cursor, players[0].box));
            if (CheckCollisionPointRec(Cursor, players[1].box));
        }
}

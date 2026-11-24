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
    }
}//prints column by row


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

void SelectPlayerButtons(BoardSquares players[])// the boxes are created and stored in the box strucyt before drawn
{
    for(int i =0; i<2; i++)
    {
        players[i].box = (Rectangle){600 + 100*i*2,200,100,50};
        players[i].state = 0;
    }
}

void DrawSelectPlayerButtons(BoardSquares players[])//buttons for player mode Bot or palyer are drawn
{
    const char *Labels[2] = {"Player","Bot"};//possible texts for either box
    for(int i =0; i<2; i++)
    {
        DrawRectangleRec(players[i].box, BLUE);
        DrawText(Labels[i],players[i].box.x + 22, players[i].box.y +12, 20, WHITE);//write the text for the box
    }
}

//Buttons to select difficulty level are being created through the struct BoardSquares
void SelectDifficultyButtons(BoardSquares Difficulty[])
{
    for(int i=0;i<3;i++)
    {
        Difficulty[i].box = (Rectangle){600 + 75*i*1.5,300,85,50};
        Difficulty[i].state = 0;
    }
}

// drawing the select difficulty buttons
void DrawSelectDifficultyButtons(BoardSquares Difficulty[])
{
    const char *Labels[3] = {"Easy","Medium", "Hard"};//possible texts for the boxes
    for(int i =0;i<3;i++)
    {
        DrawRectangleRec(Difficulty[i].box, GREEN);
        DrawText(Labels[i],Difficulty[i].box.x + 15, Difficulty[i].box.y +12, 20, WHITE);
    }
}

void SelectRoundsButtons(BoardSquares SelectRounds[])
{
    for(int i=0;i<3;i++)
    {
        SelectRounds[i].box = (Rectangle){600+75*i*1.5,420,85,50};
        SelectRounds[i].state = 0;
    }
}

void DrawSelectRoundsButtons(BoardSquares SelectRounds[])
{
    const char *Labels[3] = {"1","3", "5"};//possible texts for the boxes
    for(int i =0;i<3;i++)
    {
        DrawRectangleRec(SelectRounds[i].box, PURPLE);
        DrawText(Labels[i],SelectRounds[i].box.x + 15, SelectRounds[i].box.y +12, 20, WHITE);
    }
}
///might remove the New Game Button - change it to reset
void CreateNewGameBtn(BoardSquares NewGameBtn[])//create the box from struct
{
    NewGameBtn[1].box = (Rectangle){600,600,130,60};
    NewGameBtn[1].state = 0;
}

void DrawNewGameBtn(BoardSquares NewGameBtn[])//draw the box
{
    DrawRectangleRec(NewGameBtn[1].box, ORANGE);
    DrawText("Reset",NewGameBtn[1].box.x +30, NewGameBtn[1].box.y +15, 25, WHITE);
}

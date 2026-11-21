#ifndef BUTTONS_H
#define BUTTONS_H

#include <raylib.h>

typedef struct
{
    Rectangle box;
    int state; // 0 is empty, 1 is x, 2 is o
}BoardSquares;

void BoardButtons(BoardSquares Buttons[],int n);//create the squares

void DrawBoardButtons(BoardSquares Buttons[],int n);//draw the squares

void BoardSizeButtons(BoardSquares BoardSize[]);//create the squares to choose board size

void DrawBoardSizeButtons(BoardSquares BoardSize[]);// draw the buttons to choose size of the board

void SelectPlayerButtons(BoardSquares players[]);//create the boxes for player mode (bot or player)

void DrawSelectPlayerButtons(BoardSquares players[]);//draw the boxes for player mode

void SelectDifficultyButtons(BoardSquares Difficulty[]);//create the difficulty select buttons

void DrawSelectDifficultyButtons(BoardSquares Difficulty[]);//draw the difficulty select buttons

void SelectRoundsButtons(BoardSquares SelectRounds[]);//create the number of rounds select buttons

void DrawSelectRoundsButtons(BoardSquares SelectRounds[]);//draw the number of rounds select buttons

#endif

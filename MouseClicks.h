#ifndef MOUSECLICKS_H
#define MOUSECLICKS_H

void BoardSizeSelect(BoardSquares BoardSize[], BoardSquares Buttons[], int *n);//initialise the board select function
// as the draw board and board buttons are affected by the selections we will use bouth structures here

void GameSquareSelect(BoardSquares Buttons[],int n,int *turn);//initailaise the selecting of squares for the game

void PlayerSelect(BoardSquares players[], int *p);//detect clicks for player mode select boxes

#endif

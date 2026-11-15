#ifndef BUTTONS_H
#define BUTTONS_H

#include <raylib.h>

#define Max_N 4

typedef struct
{
    Rectangle box;
    int state; // 0 is empty, 1 is x, 2 is o
}BoardSquares;

void BoardButtons(BoardSquares Buttons[],int n);//create the squares

void DrawBoardButtons(BoardSquares Buttons[],int n);//draw the squares

void BoardSizeButtons(BoardSquares BoardSize[]);//create the squares to choose board size

void DrawBoardSizeButtons(BoardSquares BoardSize[]);// draw the buttons to choose size of the board

void DrawX(int x, int y);
void DrawO(int x, int y);
  // added these here because of an error he compiler is throwing an "implicit declaration" warning/error because the file containing this loop doesn't know where DrawX and DrawO are defined. -Malek-
#endif

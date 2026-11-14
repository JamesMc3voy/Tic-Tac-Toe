#ifndef BUTTONS_H
#define BUTTONS_H

#include <raylib.h>

#define n 3

typedef struct
{
    Rectangle box;
    int state; // 0 is empty, 1 is x, 2 is o
}BoardSquares;

void BoardButtons(BoardSquares Buttons[]);

void DrawBoardButtons(BoardSquares Buttons[]);

//void BoardSizeButtons(void);

#endif

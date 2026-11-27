//3X3 Easy Mode
#include <stdio.h>
#include "EasyAI3.h"
#include "Board.h"
#include <stdlib.h>

// Returns 1 (X wins), 2 (O wins), 3 (draw), 4 (still going)
static int EvalBoard(const int b[9])
{
    static const int lines[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}

    };

    for (int i = 0; i < 8; i++)          //Win Checker
    {
        int a = b[lines[i][0]];
        if (a != 0 && a == b[lines[i][1]] && a == b[lines[i][2]])
            return a;
    }
    for (int i = 0; i < 9; i++)
        if (b[i] == 0)
        return 4;

    return 3;

}
static int EasyAI(const int board[9])
{
    int empty[9], count = 0;
    for (int i = 0; i < 9; i++)
        if (board[i] == 0) empty[count++] = i;

    return count ? empty[rand() % count] : -1;
}


void EasyAI3(BoardSquares Buttons[], int n, int *turn)
{
    if (n != 3 || *turn != 2) return;   // only works on 3x3

    int b[9];
    for (int i = 0; i < 9; i++) b[i] = Buttons[i].state;

    if (EvalBoard(b) != 4) return;      // game over

    int move = EasyAI(b);
    if (move != -1)
    {
        Buttons[move].state = 2;
        *turn = 1;
    }
}

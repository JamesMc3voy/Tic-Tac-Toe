#include <stdio.h>
#include "MedAI4.h"
#include "Board.h"
#include <stdlib.h>

// Returns 1 (X wins), 2 (O wins), 3 (draw), 4 (still going)
static int EvalBoard(const int b[16])
{
    static const int lines[10][4] = {
        {0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15},
        {0,4,8,12},{1,5,9,13},{2,6,10,14},{3,7,11,15},
        {0,5,10,15},{3,6,9,12}


    };

    for (int i = 0; i < 10; i++)          //Win Checker
    {
        int a = b[lines[i][0]];
        if (a != 0 && a == b[lines[i][1]] && a == b[lines[i][2]] && a == b[lines[i][3]])
            return a;
    }
    for (int i = 0; i < 16; i++)
        if (b[i] == 0)
        return 4;

    return 3;

}

static int Blocker(const int board[16], int player)
{
    static const int lines[10][4] = {
        {0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15},
        {0,4,8,12},{1,5,9,13},{2,6,10,14},{3,7,11,15},
        {0,5,10,15},{3,6,9,12}

    };

    for (int i = 0; i < 10; i++)
    {
        int a = lines[i][0], b = lines[i][1], c = lines[i][2], d = lines[i][3];

        if (board[a] == player && board[b] == player && board[c] == player && board[d] == 0) return d;
        if (board[a] == player && board[b] == player && board[d] == player && board[c] == 0) return c;
        if (board[a] == player && board[d] == player && board[c] == player && board[b] == 0) return b;
        if (board[d] == player && board[b] == player && board[c] == player && board[a] == 0) return a;


    }
    return -1;
}

static int MedAI(const int board[16])
{
    int move;



    move = Blocker(board, 1);
    if (move != -1) return move;


    int empty[16], count = 0;
    for (int i = 0; i < 16 ; i++)
        if (board[i] == 0) empty[count++] = i;

    return count ? empty[rand() % count] : -1;
}



void MedAI4(BoardSquares Buttons[], int n, int *turn)
{
    if (n != 4 || *turn != 2) return;   // only works on 4x4
    int b[16];
    for (int i = 0; i < 16; i++) b[i] = Buttons[i].state;

    if (EvalBoard(b) != 4) return;      // game over

    int move = MedAI(b);
    if (move != -1)
    {
        Buttons[move].state = 2;
        *turn = 1;
    }
}

//3X3 Hard Mode

#include <stdio.h>
#include "HardAI3.h"
#include "Board.h"


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

// O (2) maximizes, X (1) minimizes
static int Minimax(int b[9], int numMaximizing, int depth)
{
    int result = EvalBoard(b);

    if (result == 1) return depth - 10;   // X wins
    if (result == 2) return 10 - depth;   // O wins
    if (result == 3) return 0;            // draw

    int best = numMaximizing ? -1000 : 1000;

    for (int i = 0; i < 9; i++)
    {
        if (b[i] == 0)
        {
            b[i] = numMaximizing ? 2 : 1;
            int score = Minimax(b, !numMaximizing, depth + 1);
            b[i] = 0;

            if (numMaximizing  && score > best) best = score;
            if (!numMaximizing && score < best) best = score;
        }
    }
    return best;
}

static int BestMove(const int board[9])
{
    int b[9];
    for (int i = 0; i < 9; i++) b[i] = board[i];

    int bestScore = -1000, move = -1;

    for (int i = 0; i < 9; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 2;
            int score = Minimax(b, 0, 1);   // X's turn next
            b[i] = 0;

            if (score > bestScore)
            {
                bestScore = score;
                move = i;
            }
        }
    }
    return move;
}

void HardAI3(BoardSquares Buttons[], int n, int *turn)
{
    if (n != 3 || *turn != 2) return;   // only works on 3x3
    int b[9];
    for (int i = 0; i < 9; i++) b[i] = Buttons[i].state;

    if (EvalBoard(b) != 4) return;      // game over

    int move = BestMove(b);
    if (move != -1)
    {
        Buttons[move].state = 2;
        *turn = 1;
    }
}

//4x4 Hard Mode
#include <stdio.h>
#include "HardAI4.h"
#include "Board.h"

// Returns 1 (X wins), 2 (O wins), 3 (draw), 4 (still going)
static int EvalBoard(const int b[16])
{
    static const int lines[16][4] = {
        {0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15},
        {0,4,8,12},{1,5,9,13},{2,6,10,14},{3,7,11,15},
        {0,5,10,15},{3,6,9,12}
    };

    for (int i = 0; i < 10; i++)                                                                //Win Checker
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

// O (2) maximizes, X (1) minimizes
static int Minimax(int b[16], int numMaximizing, int depth)
{
    int result = EvalBoard(b);

    if (result == 1) return depth - 100;   // X wins
    if (result == 2) return 100 - depth;   // O wins
    if (result == 3) return 0;            // draw
    if (depth >= 6)
        return 0;

    int best = numMaximizing ? -100 : 100;

    for (int i = 0; i < 16; i++)
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

static int BestMove(const int board[16])
{
    int b[16];
    for (int i = 0; i < 16; i++) b[i] = board[i];

    int bestScore = -1000, move = -1;

    for (int i = 0; i < 16; i++)
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

void HardAI4(BoardSquares Buttons[], int n, int *turn)
{
    if (n != 4 || *turn != 2) return;   // 3x3 only, O's turn only

    int b[16];
    for (int i = 0; i < 16; i++) b[i] = Buttons[i].state;

    if (EvalBoard(b) != 4) return;      // game already over

    int move = BestMove(b);
    if (move != -1)
    {
        Buttons[move].state = 2;
        *turn = 1;
    }
}

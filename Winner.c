#include "Buttons.h"
void CheckWinner3x3(BoardSquares Buttons[], int n, int *winner)
{
    //diagonal one
    int diag1square1 = Buttons[0].state;
    int diag1square3 = Buttons[8].state;

    int diagmiddle = Buttons[4].state;

    //diagonoal two
    int diag2square1 = Buttons[2].state;
    int diag2square3 = Buttons[6].state;
    //Check Columns
    for(int i=0; i<3;i++)
    {
        *winner = 4; //no outcome
        int square1col = Buttons[i*3].state;//create a variable for each square in the rows or columns
        int square2col = Buttons[i*3+1].state;
        int square3col = Buttons[i*3+2].state;

        int square1row = Buttons[i].state;
        int square2row = Buttons[i+3].state;
        int square3row = Buttons[i+6].state;

        //check columns
        if(square1col != 0 && square1col == square2col && square2col == square3col)

        {
            *winner = (square1col ==1) ? 1:2;
        }

        //check rows
        if(square1row != 0 && square1row == square2row && square2row == square3row)

        {
            *winner = (square1row ==1) ? 1:2;
        }

        //check Diagnols
        if(diag1square1 != 0 && diag1square1 == diag1square3 && diag1square1 == diagmiddle)
        {
            *winner = (diag1square1 ==1) ? 1:2;
        }
        if(diag2square1 != 0 && diag2square1 == diag2square3 && diag2square1 == diagmiddle)
        {
            *winner = (diag2square1 ==1) ? 1:2;
        }

    }
}

void CheckWinner4x4(BoardSquares Buttons[], int n, int *winner)
{
    //diaganol 1
    int diag1square1_4x4 = Buttons[0].state;
    int diag1square2_4x4 = Buttons[5].state;
    int diag1square3_4x4 = Buttons[10].state;
    int diag1square4_4x4 = Buttons[15].state;

    //diaganol 2
    int diag2square1_4x4 = Buttons[3].state;
    int diag2square2_4x4 = Buttons[6].state;
    int diag2square3_4x4 = Buttons[9].state;
    int diag2square4_4x4 = Buttons[12].state;

    for(int i =0; i<n*n; i++)
    {
        *winner = 4; //no outcome
        int square1col_4x4 = Buttons[i*4].state;//create a variable for each square in the rows or columns in a for loop
        int square2col_4x4 = Buttons[i*4 +1].state;
        int square3col_4x4 = Buttons[i*4 +2].state;
        int square4col_4x4 = Buttons[i*4 +3].state;

        int square1row_4x4 = Buttons[i].state;
        int square2row_4x4 = Buttons[i+4].state;
        int square3row_4x4 = Buttons[i+8].state;
        int square4row_4x4 = Buttons[i+12].state;

        //check columns
        if(square1col_4x4 != 0 && square1col_4x4 == square2col_4x4 && square2col_4x4 == square3col_4x4 && square3col_4x4 == square4col_4x4)

        {
            *winner = (square1col_4x4 ==1) ? 1:2;
        }

        //check rows
        if(square1row_4x4 != 0 && square1row_4x4 == square2row_4x4 && square2row_4x4 == square3row_4x4 && square3row_4x4 == square4row_4x4)

        {
            *winner = (square1row_4x4 ==1) ? 1:2;
        }
        //check Diagnols
        if(diag1square1_4x4 != 0 && diag1square1_4x4 == diag1square2_4x4 && diag1square2_4x4 == diag1square3_4x4 && diag1square3_4x4 == diag1square4_4x4)
        {
            *winner = (diag1square1_4x4 ==1) ? 1:2;
        }
        if(diag2square1_4x4 != 0 && diag2square1_4x4 == diag2square2_4x4 && diag2square2_4x4 == diag2square3_4x4 && diag2square3_4x4 == diag2square4_4x4)
        {
            *winner = (diag2square1_4x4 ==1) ? 1:2;
        }
    }
}

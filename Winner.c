#include "Buttons.h"
void CheckWinner3x3(BoardSquares Buttons[], int n, int *winner)
{
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


        if(square1col !=0 && square1col == square2col && square2col == square3col)

        //check columns
        if(square1col != 0 && square1col == square2col && square2col == square3col)

        {
            *winner = (square1col ==1) ? 1:2;
        }

        if(square1row!=0 && square1row == square2row && square2row == square3row)

        //check rows
        if(square1row != 0 && square1row == square2row && square2row == square3row)

        {
            *winner = (square1col ==1) ? 1:2;
        }
    }

}

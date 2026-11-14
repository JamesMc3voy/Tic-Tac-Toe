#include "Buttons.h"
void CheckWinner3x3(BoardSquares Buttons[], int n, int *winner)
{
    //Check Columns
    for(int i=0; i<3;i++)
    {
        int square1 = Buttons[i*3].state;
        int square2 = Buttons[i*3+1].state;
        int square3 = Buttons[i*3+2].state;

        if(square1 !=0 && square1 == square2 && square2 == square3)
        {
            if(square1 == 1)
            {
                *winner = 1;
            }
            else
            {
                *winner = 2;
            }
        }
    }

}

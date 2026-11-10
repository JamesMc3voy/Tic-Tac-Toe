#include<raylib.h>

void BoardButtons(void)
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0;j<3;j++)
        {
            DrawRectangleLines(100+ 100*i,100+100*j,100,100,RED);// prints squares within the boxes on the board to act as buttons
        }
    }
}//prints row by column

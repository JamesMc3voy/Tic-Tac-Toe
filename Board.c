#include<raylib.h>
//Board Function
void DrawBoard(int start_x_vert,int start_y_vert,int start_x_horiz,int start_y_horiz)
{
    for(int i = 0; i<3-1; i++)
    {
        //Vertical Lines - DrawlineEx with start and end co-ordinates, line thickness and colour for both vertical and horizontal lines
        DrawLineEx((Vector2){start_x_vert + 100*i,start_y_vert},(Vector2){start_x_vert +100*i,start_y_vert +100*3-1},5,BLACK);
        //Horizontal Lines
        DrawLineEx((Vector2){start_x_horiz,start_y_horiz+100*i},(Vector2){start_x_horiz +100*3-1,start_y_horiz+100*i},5, BLACK);
    }
}

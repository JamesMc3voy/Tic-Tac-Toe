#include "Buttons.h"
void BoardSizeSelect(BoardSquares BoardSize[], BoardSquares Buttons[], int *n)
{
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 Cursor = GetMousePosition();
            if (CheckCollisionPointRec(Cursor, BoardSize[0].box)) {*n = 3; BoardButtons(Buttons, *n);}// check if the cursor was pressed within the box
            //check both boxes, and assign the appropriate value to n and give n to the other funtions that are needed
            if (CheckCollisionPointRec(Cursor, BoardSize[1].box)) { *n = 4; BoardButtons(Buttons, *n); }
        }
}

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// Include headers
#include "Board.h"
#include "Buttons.h"
#include "MouseClicks.h"
#include "Winner.h"
#include "ui.h"

int main()
{
    // Initialize the Raylib graphical window first
    InitWindow(1000, 900, "Tic Tac Toe");
    SetExitKey(KEY_NULL); // Prevent ESC from closing the window , it says press esc to go back but it always exits
    SetTargetFPS(60);

    GameState state = STATE_MENU;

    // Board setup variables: coordinar=tes for top left corner of box
    int start_x_vert = 200;
    int start_y_vert = 100;
    int start_x_horiz = 100;
    int start_y_horiz = 200;
    int n = 3; // Default board size (can be changed via board size buttons)
    int turn = 1; //begin with palyer 1
    int winner = 4; // 4 is no outcome yet, 3 is draw, 2 is player 2 win and 1 is player 1 win

    // changes ScoreX and ScoreO to score 1 and score 2, as palyer 1 will always be x so when they swith whoever was x is now o
    //better to track by palyer, not by piece, i think
    int score1 = 0; // track scores for player 1
    int score2 = 0; // track scores for player 1
    int roundNumber = 1; //tracking rounds
    char scoreText[50];
    char roundText[50];

    //initialising arrays for boxes
    BoardSquares BoardSize[2]; // 2 is the number of boxes needed for this array 3x3 or 4x4
    BoardSquares Buttons[4 * 4]; // 4 is Max amount of squares
    BoardSquares players[2]; //  2 is the number of boxes that will be created: Select player/bot buttons
    BoardSquares Difficulty[3]; // 3 because easy,medium, hard
    BoardSquares SelectRounds[3];// 3 because rounds: 1,3,5

    //create the boxes here before drawing them
    BoardButtons(Buttons, n);
    BoardSizeButtons(BoardSize);
    SelectPlayerButtons(players);
    SelectDifficultyButtons(Difficulty);
    SelectRoundsButtons(SelectRounds);

    while (!WindowShouldClose())
    {
        if (state == STATE_MENU)
        {
            // Check for graphical menu clicks
            state = UpdateGraphicalMenu(); // I REMOVED show_main_menu and choose_board_size it caused the errors and moved InitWindow to the beginning

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawGraphicalMenu();
            EndDrawing();
        }

        // Freeplay and Tournament both use the board. Tournament also shows the round buttons.
        else if (state == STATE_PLAYING || state == STATE_TOURNAMENT)
        {
            if (IsKeyPressed(KEY_ESCAPE))
            {
                state = STATE_MENU;
            }

            BoardSizeSelect(BoardSize, Buttons, &n); // check what square the user chose on the board
            if(n == 3) //whether its a 3x3 or 4x4 board, use appropriate check conditions
            {
                CheckWinner3x3(Buttons, n, &winner);  // Check winner 3x3
            }
            else
            {
                CheckWinner4x4(Buttons, n,&winner);
            }


            // If a round is won or drawn
            if (winner == 1 || winner == 2 || winner == 3)
            {
                if (winner == 1) score1++;
                if (winner == 2) score2++;

                roundNumber++;

                // Reset the board and state for the next round
                BoardButtons(Buttons, n);
                turn = 1;
                winner = 4;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawBoardButtons(Buttons, n); //draws the squares for the board that the user will click
            DrawBoardSizeButtons(BoardSize);//draw the buttons for the 3x3 or 4x4 board
            DrawSelectPlayerButtons(players); // draw the buttons for the player or bot game modes

            ///change to only appear when bot is pressed
            DrawSelectDifficultyButtons(Difficulty);//draw the difficulty select buttons
            DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n); // draw the board

            GameSquareSelect(Buttons, n, &turn);//checks where the user clicks on the board

            // Round choice is only for Tournament
            if (state == STATE_TOURNAMENT)
            {
                DrawSelectRoundsButtons(SelectRounds);
                DrawText("Select Number of Rounds",600,370,30,BLACK);
            }

            // Display Rounds and Scores on screen
            sprintf(roundText, "Round: %d", roundNumber);
            sprintf(scoreText, "Score - X: %d | O: %d", score1, score2);
            DrawText(roundText, 20, 60, 20, DARKGRAY);
            DrawText(scoreText, 20, 90, 20, DARKGRAY);

            DrawText("Press ESC to return to Menu", 20, 20, 18, GRAY);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}

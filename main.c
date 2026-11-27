#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

// Include headers
#include "Board.h"
#include "Buttons.h"
#include "MouseClicks.h"
#include "Winner.h"
#include "ui.h"

static void ResetMatchState(BoardSquares Buttons[], int n, int *turn, int *winner, int *score1, int *score2, int *roundNumber)
{
    BoardButtons(Buttons, n);   // I added this function trying to make going back reset the game
    *turn = 1;             // you can possibly connect it to the reset button when its fully working
    *winner = 4;
    if (score1) *score1 = 0;
    if (score2) *score2 = 0;
    if (roundNumber) *roundNumber = 1;
}

int main()
{
    // Initialize the Raylib graphical window first
    InitWindow(1000, 900, "Tic Tac Toe");
    SetExitKey(KEY_NULL); // Prevent ESC from closing the window , it says press esc to go back but it always exits
    SetTargetFPS(60);

    GameState state = STATE_MENU;

    // Board setup variables: coordinates for top left corner of box
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

    // Getting the Robot Face
    int animFrames = 0;
    Image botGif = LoadImageAnim("bot_face.gif", &animFrames); // Loads all face frames
    Texture2D botTex = LoadTextureFromImage(botGif);      // GPU texture for drawing

    unsigned int nextFrameDataOffset = 0;
    int currentAnimFrame = 0;
    int frameDelay = 6;   // Speed control of the guy movement: higher = slower, lower = faster
    int frameCounter = 0;

    //initialising arrays for boxes
    BoardSquares BoardSize[2]; // 2 is the number of boxes needed for this array 3x3 or 4x4
    BoardSquares Buttons[4 * 4]; // 4 is Max amount of squares
    BoardSquares players[2]; //  2 is the number of boxes that will be created: Select player/bot buttons
    BoardSquares Difficulty[3]; // 3 because easy,medium, hard
    BoardSquares SelectRounds[3];// 3 because rounds: 1,3,5
    BoardSquares ResetBtn[1];

    //create the boxes here before drawing them
    BoardButtons(Buttons, n);
    BoardSizeButtons(BoardSize);
    SelectPlayerButtons(players);
    SelectDifficultyButtons(Difficulty);
    SelectRoundsButtons(SelectRounds);
    CreateNewGameBtn(ResetBtn);

    while (!WindowShouldClose())
    {
        if (state == STATE_MENU)
        {
            // Check for graphical menu clicks
            state = UpdateGraphicalMenu(); // I REMOVED show_main_menu and choose_board_size it caused the errors and moved InitWindow to the beginning

            BeginDrawing();
            ClearBackground((Color){ 241, 245, 249, 255 });
            DrawGraphicalMenu();
            EndDrawing();
        }

        // Freeplay and Tournament both use the board. Tournament also shows the round buttons.
        else if (state == STATE_PLAYING || state == STATE_TOURNAMENT)
        {
            if (IsKeyPressed(KEY_ESCAPE)|| ResetBtn[0].state == 1)///reset button not working rn
            {
                // CHANGED: Reset board, scores, and round when leaving to menu so X/O don't stay
                ResetMatchState(Buttons, n, &turn, &winner, &score1, &score2, &roundNumber);
                state = STATE_MENU;
                ResetBtn[0].state = 0;
            }

            // CHANGED: Handle clicks on the 1, 3, and 5 round buttons in Tournament mode
            if (state == STATE_TOURNAMENT)
            {
                SelectRoundsMouseClick(SelectRounds);
            }

            // CHANGED: arget rounds from selected round button (defaults to 1)
            int targetRounds = 1;
            if (SelectRounds[1].state == 1) targetRounds = 3;
            else if (SelectRounds[2].state == 1) targetRounds = 5;

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

                // CHANGED: Stop advancing past targetRounds in Tournament mode (e.g., stays on round 1 for 1-round button)
                if (!(state == STATE_TOURNAMENT && roundNumber >= targetRounds))
                {
                    roundNumber++;
                }

                // Reset the board and state for the next round
                BoardButtons(Buttons, n);
                turn = 1;
                winner = 4;
            }

            BeginDrawing();
            ClearBackground((Color){ 241, 245, 249, 255 });;
            DrawBoardButtons(Buttons, n); //draws the squares for the board that the user will click
            DrawBoardSizeButtons(BoardSize);//draw the buttons for the 3x3 or 4x4 board
            DrawSelectPlayerButtons(players); // draw the buttons for the player or bot game modes
            DrawNewGameBtn(ResetBtn);

            PlayerSelect(players);
            GameSquareSelect(Buttons, n, &turn);//checks where the user clicks on the board
            ResetBtnClicked(ResetBtn);
            DrawBoard(start_x_vert, start_y_vert, start_x_horiz, start_y_horiz, n); // draw the board
            DrawText("Board Size",600,80,20,BLACK);
            DrawText("Player Mode", 600,180,20,BLACK);

            if (players[1].state == 1)
            {
                DrawText("Difficulty Level",600,270,20,BLACK);
                DrawText("Opponent Hacked Facecam:", 620, 492, 20, BLACK);
                DrawSelectDifficultyButtons(Difficulty);//draw the difficulty select buttons

                // Put the simple animated GIF snippet here
                if (animFrames > 0 && ++frameCounter >= frameDelay)
                {
                    frameCounter = 0;
                    currentAnimFrame = (currentAnimFrame + 1) % animFrames;
                    UpdateTexture(botTex, (unsigned char *)botGif.data + botGif.width * botGif.height * 4 * currentAnimFrame);
                }
                if (animFrames > 0) DrawTexture(botTex, 620, 520, WHITE);
            }

            if (state == STATE_TOURNAMENT) // Round choice is only for Tournament
            {
                DrawSelectRoundsButtons(SelectRounds);
                DrawText("Select Number of Rounds",600,370,30,BLACK);
            }

            // Display Rounds and Scores on screen
            sprintf(roundText, "Round: %d", roundNumber);
            sprintf(scoreText, "Score - X: %d | O: %d", score1, score2);
            DrawText(roundText, 60, 600, 30, DARKGRAY);
            DrawText(scoreText, 60, 650, 30, DARKGRAY); // I changed locations of the Score card - Malek

            DrawText("Press ESC to return to Menu", 20, 20, 18, GRAY);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}

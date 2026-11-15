#include <stdio.h>
#include "ui.h"

int read_int(char prompt[], int min, int max)
{
    char buffer[100];   // holds one line the player types
    int value;
    char extra;         // catches junk after the number, like "3abc"

    while (1)           // repeat until we return a good answer
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            return min;     // input ended (Ctrl+Z)--- stops an infinite loop
        }

        // sscanf returns how many things it read. We want exactly 1: the number.
        if (sscanf(buffer, "%d %c", &value, &extra) == 1
            && value >= min && value <= max)
        {
            return value;   // good answer, we're done
        }

        printf("Invalid input. Enter a number from %d to %d.\n", min, max);
    }
}
int show_main_menu(void)
{
    printf("\n=== TIC TAC TOE ===\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n");
    printf("3. Tournament\n");
    printf("4. How to play\n");
    printf("5. Quit\n");
    return read_int("Choose 1-5: ", 1, 5);
}

int choose_board_size(void)
{
    printf("\nBoard size:\n");
    printf("1. 3x3\n");
    printf("2. 4x4\n");
    int choice = read_int("Choose 1-2: ", 1, 2);

    if (choice == 1)
    {
        return 3;       // returns the real size, so later code can use it directly
    }
    return 4;
}

int choose_difficulty(void)
{
    printf("\nDifficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Tough\n");
    return read_int("Choose 1-3: ", 1, 3);
}

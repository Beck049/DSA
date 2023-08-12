#include "Minesweeper.h"

int main()
{
    int width = 0, height = 0, mine = 0;

    width  = enter_width (16, 10);
    height = enter_height(16, 10);
    mine   = enter_mine  (90, 30);
 // printf("%d %d %d", width, height, mine);

// open the map for game
    int *map = (int*)calloc(width*height*2,sizeof(int));
                            // use two digit to form a block ( status, opened? )
    init_game(map, width, height, mine);
    print_ans(map, width, height);

    int row, col; // i, j //
    int over = 0;
    int opt = 0;
    while( over != 1)
    {
    option:
        printf("Your option (1)Open (2)Flag :");
        scanf("%d", &opt);
        if(check_input(opt, 2, 1) == 1)
        {
            goto option;
        }
        
        switch(opt)
        {
            case 1:
                printf("Position to open (row, column) :");
                scanf("%d %d", &row, &col);
                if(check_input(col, width-1 , 0) == 1)
                {
                    break;
                }
                if(check_input(row, height-1, 0) == 1)
                {
                    break;
                }
                over = open(map, row, col, width, height);
                go_through(map, row, col, width, height);
                print_map(map, width, height);
                break;

            case 2:
                printf("Position to flag / unflag (row, column) :");
                scanf("%d %d", &row, &col);
                if(check_input(col, width-1 , 0) == 1)
                {
                    break;
                }
                if(check_input(row, height-1, 0) == 1)
                {
                    break;
                }
                over = flag(map, row, col, width, height);
                break;
        }

        if(over != 1)
        {
            over = check_mine(map, width, height, mine);
        }
    }
}
///////////////////////////////////////////////////////////////////////

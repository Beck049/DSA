#include "Minesweeper.h"

void go_through(int* map, int row, int col, int width, int height)
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if( map[(j*width + i)*2 +1] == 1 && map[(j*width + i)*2] == 0 )// opened && is blank
            {
                if(j == 0 && i == 0) // if 左上角
                {
                    // 9
                    map[((j+1)*width + (i+1))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                }
                else if(j == 0 && i == width-1) // if 右上角
                {
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                    // 7
                    map[((j+1)*width + (i-1))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                }
                else if(j == height-1 && i == 0) // if 左下角
                {
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 3
                    map[((j-1)*width + (i+1))*2 +1] = 1;
                }
                else if(j == height-1 && i == width-1) // if 右下角
                {
                    // 1
                    map[((j-1)*width + (i-1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                }
                else if(i == 0) // if 第一列
                {
                    // 9
                    map[((j+1)*width + (i+1))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 3
                    map[((j-1)*width + (i+1))*2 +1] = 1;
                }
                else if(j == 0) // if 第一排
                {
                    // 9
                    map[((j+1)*width + (i+1))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                    // 7
                    map[((j+1)*width + (i-1))*2 +1] = 1;
                }
                else if(j == height-1) // if 最後一排
                {
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 3
                    map[((j-1)*width + (i+1))*2 +1] = 1;
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                    // 1
                    map[((j-1)*width + (i-1))*2 +1] = 1;
                }
                else if(i == width-1) // if 最後一列
                {
                    // 1
                    map[((j-1)*width + (i-1))*2 +1] = 1;
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                    // 7
                    map[((j+1)*width + (i-1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                }
                else
                {
                    // 9
                    map[((j+1)*width + (i+1))*2 +1] = 1;
                    // 8
                    map[((j+1)*width + i)*2 +1] = 1;
                    // 6
                    map[(j*width + (i+1))*2 +1] = 1;
                    // 2
                    map[((j-1)*width + (i))*2 +1] = 1;
                    // 3
                    map[((j-1)*width + (i+1))*2 +1] = 1;
                    // 4
                    map[((j)*width + (i-1))*2 +1] = 1;
                    // 7
                    map[((j+1)*width + (i-1))*2 +1] = 1;
                    // 1
                    map[((j-1)*width + (i-1))*2 +1] = 1;
                }
            }
        }
    }
}

int check_mine(int* map, int width, int height, int mine)
{
    int count = 0;
    int flaged_mine = 0;
    // winning condition
    // 1. open all the avaliable block
    // 2. flag all the mine

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            // 1. open all the avaliable block
            // if isOpened
            if( map[(j*width + i)*2 +1] == 1 )
            {
                count++;
            }
            // 2. flag all the mine
            // if isFlaged && isBomb , ++
            else if( map[(j*width + i)*2 +1] == -1 && map[(j*width + i)*2 ] == -1 )
            {
                flaged_mine++;
            }
            // if isFlaged && isNotBomb , --
            else if( map[(j*width + i)*2 +1] == -1 && map[(j*width + i)*2 ] != -1 )
            {
                flaged_mine--;
            }
        }
    }
    
// winning conditions
    // 1. open all the avaliable block
    if(count == width*height - mine)
    {
        printf("You Win !!");
        print_ans(map, width, height);
        return 1;
    }
    // 2. flag all the mine
    if(flaged_mine == mine)
    {
        printf("You Win !!");
        print_ans(map, width, height);
        return 1;
    }

    return 0;
}
int open(int* map, int row, int col, int width, int height)
{
    if( map[(row*width + col)*2 +1] == 0 ) // not opened yet
    {
        if( map[(row*width + col)*2] == -1 ) // a bomb
        {
            printf("You Lose ...");
            return 1;
        }
        else if( map[(row*width + col)*2] == 0 ) // value 0
        {
            map[(row*width + col)*2 +1] = 1;
    ////
            if(row == 0 && col == 0) // if 左上角
                {
                    // printf("left up\n");
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 0 && col == width-1) // if 右上角
                {
                    // printf("right up\n");
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                }
                else if(row == height-1 && col == 0) // if 左下角
                {
                    // printf("left down\n");
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                }
                else if(row == height-1 && col == width-1) // if 右下角
                {
                    // printf("right down\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                }
                else if(col == 0) // if 第一列
                {
                    // printf("col = 0\n");
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 0) // if 第一排
                {
                    // printf("row = 0\n");
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == height-1) // if 最後一排
                {
                    // printf("row = 9\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                }
                else if(col == width-1) // if 最後一列
                {
                    // printf("col = 9\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                }
                else
                {
                    // printf("other\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
    ////
        }
        else // = value
        {
            map[(row*width + col)*2 +1] = 1;
        }
    }
    else if( map[(row*width + col)*2 +1] == -1 ) // flag
    {
        printf(RED "Already flaged ...\n" RST);
    }
    else if( map[(row*width + col)*2 +1] == 1 ) // open
    {
        printf(RED "Already opened ...\n" RST);
    }

//  printf("%d %d = %d\n", row, col, map[(row*width + col)*2 +1]);
//  print_map(map, width, height);
    return 0;
}
int flag(int* map, int row, int col, int width, int height)
{
    if( map[(row*width + col)*2 +1] == 0 )
    {
        map[(row*width + col)*2 +1] = -1;
    }
    else if( map[(row*width + col)*2 +1] == -1 )
    {
        map[(row*width + col)*2 +1] = 0;
    }
    else if( map[(row*width + col)*2 +1] == 1 )
    {
        printf(RED "Already opened ...\n" RST);
    }

    print_map(map, width, height);
    return 0;
}
int init_game(int* map, int width, int height, int mine)
{
    set_mine(map, width, height, mine);
    // print_ans(map, width, height);
    set_number(map, width, height, mine);
    print_map(map, width, height);
    return 0;
}
int set_number(int* map, int width, int height, int mine)
{
    int count = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            count = 0;
            if( map[(j*width+i)*2] == 0)
            {
                if(j == 0 && i == 0) // if 左上角
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 0 && i == width-1) // if 右上角
                {
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == height-1 && i == 0) // if 左下角
                {
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == height-1 && i == width-1) // if 右下角
                {
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(i == 0) // if 第一列
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 )
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 0) // if 第一排
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == height-1) // if 最後一排
                {
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(i == width-1) // if 最後一列
                {
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
            }
        }
    }

    return 0;
}
int set_mine(int* map, int width, int height, int mine)
{
    int temp = 0;
    srand(time(NULL));

    for(int i = 0; i < mine; i)
    {
        temp = rand() % (width*height);
        // printf("%d ", temp);
        if( map[temp*2] != -1 )
        {
            map[temp*2] = -1;
            i++;
        /*
            if(i % 5 == 0)
            {
                printf("\n");
            }
        */
        }
        
    }

    return 0;
}
int enter_width (int max, int min)
{
    int value;
    do
    {
        printf("Please enter the width       (10-16) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);

    return value;
}
int enter_height(int max, int min)
{
    int value;
    do
    {
        printf("Please enter the height      (10-16) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);
    
    return value;
}
int enter_mine  (int max, int min)
{
    int value;
    do
    {
        printf("Please enter the mine number (30-90) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);
    
    return value;
}
int check_input (int value, int max, int min)
{
    if(value < min || value > max)
    {
        printf(RED "ERROR\n" RST);
        return 1;
    }
    else
    {
        return 0;
    }
}
void print_ans(int* map, int width, int height)
{
    printf("   ");
    for(int i = 0; i < width; i++)
    {
        printf("%02d ", i);
    }
    printf("\n---");

    for(int i = 0; i < width; i++)
    {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        printf("%02d|", i);
        for(int j = 0; j < width; j++)
        {
            if( map[(i*width+j)*2] == -1)
            {
                printf(RED "%2d " RST, map[(i*width+j)*2] );
            }
            else
            {
                printf("%2d ", map[(i*width+j)*2] );
            }
        }
        printf("\n");
    }
}
void print_map(int* map, int width, int height)
{
    printf("   ");
    for(int i = 0; i < width; i++)
    {
        printf("%02d ", i);
    }
    printf("\n---");

    for(int i = 0; i < width; i++)
    {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        printf("%02d|", i);
        for(int j = 0; j < width; j++)
        {
            if( map[(i*width+j)*2 +1] == 0 ) // closed
            {
                printf(" * ");
            }
            else if( map[(i*width+j)*2 +1] == -1 ) // flaged
            {
                printf(RED " F " RST);
            }
            else if( map[(i*width+j)*2 +1] == 1 ) // opened
            {
                if( map[(i*width+j)*2] == 0 )
                {
                    printf("   ");
                }
                else if( map[(i*width+j)*2] == 1 )
                {
                    printf(BL "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 2 )
                {
                    printf(GRN "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 3 )
                {
                    printf(LRED "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 4 )
                {
                    printf(MGT "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 5 )
                {
                    printf(YLW "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 6 )
                {
                    printf(CYN "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 7 )
                {
                    printf(LMGT "%2d " RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 8 )
                {
                    printf(GRY "%2d " RST, map[(i*width+j)*2] );
                }
                else
                {
                    printf("%2d ", map[(i*width+j)*2] );
                }
            }
        }
        printf("\n");
    }
}
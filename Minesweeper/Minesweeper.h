#include <stdio.h> 
#include <math.h>            
#include <ctype.h>    
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>	
#include <time.h>

#define ASCII_ESC "\033"

#define BOLD ASCII_ESC"[1m"
#define FLASH ASCII_ESC"[5m"

#define RST ASCII_ESC"[0m"
#define RED ASCII_ESC"[31m"
#define GRN ASCII_ESC"[32m"
#define YLW ASCII_ESC"[33m"
#define BL ASCII_ESC"[34m" 
#define MGT ASCII_ESC"[35m"
#define CYN ASCII_ESC"[36m"
#define WHT ASCII_ESC"[37m"
#define GRY ASCII_ESC"[90m"
#define LRED ASCII_ESC"[91m"
#define LGRN ASCII_ESC"[92m"
#define LYLW ASCII_ESC"[93m"
#define LBL ASCII_ESC"[94m"
#define LMGT ASCII_ESC"[95m"
#define LCYN ASCII_ESC"[96m"
#define LWHT ASCII_ESC"[97m"

int enter_width (int, int); //(max, min)
int enter_height(int, int); //(max, min)
int enter_mine  (int, int); //(max, min)

int check_input (int, int, int); // check the input values (value, max, min)

int init_game (int*, int, int, int);// set mine, set number, print map
int set_mine  (int*, int, int, int);// randomly choose different numberto set the mine
int set_number(int*, int, int, int);// for every not mine block, check how many mines around

int open (int*, int, int, int, int);// if is mine then lose
                                    // if blank then open the block around
int flag (int*, int, int, int, int);

void go_through(int*, int, int, int, int);// in case some space didn't open
                                          // fix some bug for function "open"

int check_mine(int*, int, int, int);// check if wins, else keep going

void print_map(int*, int, int); // closed(0) , flaged(-1) , opened(1)
void print_ans(int*, int, int); // print answers (numbers, blank, bomb==-1)

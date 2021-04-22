#include <assert.h>  
#include <ctype.h>   
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  

#define MISTAKE_MINE_FOUND 1
#define MISTAKE_CHOSEN_SPACE 2
#define NO_MISTAKES 3
#define COLUMNS 10
#define ROWS 10
#define UNSTOPEED_SPACE '.'
#define CHOSEN_SPACE ' '
#define MINE '*'
#define NUMBER_OF_MINES \
20 
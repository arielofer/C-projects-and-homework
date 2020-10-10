#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//size of the board
#define N 12
#define MAX_STRING_LENGTH N-1

//typedefs
typedef struct {
	int x;
	int y;
}Coordinate;

//protos
char* get_string();
void board_build(char board[][N]);
void print_board(char board[][N]);
void word_search(char board[][N], char* word);
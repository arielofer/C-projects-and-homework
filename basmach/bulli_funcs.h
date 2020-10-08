#pragma once
#define N 10

typedef struct {
	int x_pos;
	int y_pos;
}character;

void board_build(char board[][N], character* bulliman, character* snail_bear, int* food);
void print_board(char board[][N], character* bulliman, character* snail_bear, int food);
void move_bulli(char board[][N], character* bulliman, int* last_move, int* food_left);
void update_food(int* food_left, int last_move);
void move_snail_bear(char board[][N], character* bulliman, character* snail_bear, char* last_place);
int is_bear_next_to_bulli(char board[][N], character* bulliman, character* snail_bear);
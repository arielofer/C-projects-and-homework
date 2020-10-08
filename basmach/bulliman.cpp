#define _CRT_SECURE_NO_WARNINGS
#include "bulli_funcs.h"


/*int main() {
	int food_left = 0;//keep track of score
	int last_move = -1;//keep track of last move
	int bulli_is_alive = 1;
	char board[N][N];//game board
	character bulliman{ 0,0 };
	character snail_bear{ 0,0 };
	char snail_bear_last_cell = '.';
	//build phase
	board_build(board, &bulliman, &snail_bear, &food_left);
	print_board(board, &bulliman, &snail_bear, food_left);
	//update phase
	while (food_left && bulli_is_alive) {
		move_bulli(board, &bulliman, &last_move, &food_left);
		move_snail_bear(board, &bulliman, &snail_bear, &snail_bear_last_cell);
		print_board(board, &bulliman, &snail_bear, food_left);
		if (is_bear_next_to_bulli(board, &bulliman, &snail_bear))
			bulli_is_alive = 0;
	}
	return 0;
}*/
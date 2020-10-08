#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "bulli_funcs.h"
#include <stdlib.h>
#include <stdio.h>
#define N 10

//clear screen
void clrscreen() {
	system("@cls||clr");
}

//board initializer
//actual board is 1-100
void board_build(char board[][N], character* bulliman, character* snail_bear, int* food) {
	//setup kir bitachon
	for (int i = 0; i < N; i++) {
		board[0][i] = board[i][0] = '#';
		board[i][N - 1] = board[N - 1][i] = '#';
	}
	//setup walls
	int x, y;
	printf("enter wall coordinates:\n");
	scanf("%d %d", &x, &y);
	while (x != 0 || y != 0) {
		if ((x >= 1 && x <= N-2) && (y >= 1 && y <= N-2))
			board[y][x] = '*';
		else
			printf("invalid coordinates for a wall!\n");
		printf("enter wall coordinates:\n");
		scanf("%d %d", &x, &y);
	}
	//add food
	for (int i = 1; i <= N - 2; i++)
		for (int j = 1; j <= N-2; j++)
			if (board[i][j] != '*') {
				board[i][j] = '.';
				(*food)++;
			}
	//insert bulliman
	printf("enter bulliman coordinates:\n");
	scanf("%d %d", &(bulliman->x_pos), &(bulliman->y_pos));
	while (true) {
		if ((bulliman->x_pos >= 1 && bulliman->x_pos <= N - 2) &&
			(bulliman->y_pos >= 1 && bulliman->y_pos <= N - 2) &&
			board[bulliman->y_pos][bulliman->x_pos] != '*'){
			board[bulliman->y_pos][bulliman->x_pos] = 'B';
			break;
		}
		else {
			printf("invalid coordinates for bulliman!\n");
			printf("enter bulliman coordinates:\n");
			scanf("%d %d", &(bulliman->x_pos), &(bulliman->y_pos));
		}
	}
	(*food)--;
	//insert snail bear
	printf("enter snail bear coordinates:\n");
	scanf("%d %d", &(snail_bear->x_pos), &(snail_bear->y_pos));
	while (true) {
		if ((snail_bear->x_pos >= 1 && snail_bear->x_pos <= N - 2) &&
			(snail_bear->y_pos >= 1 && snail_bear->y_pos <= N - 2) &&
			board[snail_bear->y_pos][snail_bear->x_pos] != '*') {
			board[snail_bear->y_pos][snail_bear->x_pos] = 'D';
			break;
		}
		else {
			printf("invalid coordinates for snail bear!\n");
			printf("enter snail bear coordinates:\n");
			scanf("%d %d", &(snail_bear->x_pos), &(snail_bear->y_pos));
		}
	}
	(*food)--;
}

void print_board(char board[][N], character *bulliman, character *snail_bear, int food_left){
	
	clrscreen();//get rid of old output
	printf("food left: %d\n", food_left);
	board[bulliman->y_pos][bulliman->x_pos] = 'B';
	board[snail_bear->y_pos][snail_bear->x_pos] = 'D';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %c", board[i][j]);
		printf("\n");
	}

}


void update_food(int* food_left, int last_move) {
	if (last_move >= 0 && last_move < 5)
		(*food_left)--;
}


void move_bulli(char board[][N], character* bulliman, int* last_move, int* food_left) {
	board[bulliman->y_pos][bulliman->x_pos] = ' ';//delete bulli from current pos
	int move;
	int bulli_x = bulliman->x_pos;
	int bulli_y = bulliman->y_pos;
	scanf("%d", &move);
	switch (move)
	{
	case 1://right
		if (board[bulli_y][bulli_x + 1] != '#' &&
			board[bulli_y][bulli_x + 1] != '*') {
			bulliman->x_pos++;
			if (board[bulli_y][bulli_x + 1] != ' ')
				update_food(food_left, move);
		}
		*last_move = move;
		break;
	case 2://left
		if (board[bulli_y][bulli_x - 1] != '#' &&
			board[bulli_y][bulli_x - 1] != '*') {
			bulliman->x_pos--;
			if (board[bulli_y][bulli_x - 1] != ' ')
				update_food(food_left, move);
		}
		*last_move = move;
		break;
	case 3://up
		if (board[bulli_y - 1][bulli_x] != '#' &&
			board[bulli_y - 1][bulli_x] != '*') {
			bulliman->y_pos--;
			if (board[bulli_y - 1][bulli_x] != ' ')
				update_food(food_left, move);
		}
		*last_move = move;
		break;
	case 4://down
		if (board[bulli_y + 1][bulli_x] != '#' &&
			board[bulli_y + 1][bulli_x] != '*') {
			bulliman->y_pos++;
			if (board[bulli_y + 1][bulli_x] != ' ')
				update_food(food_left, move);
		}
		*last_move = move;
		break;
	case 0:
		switch (*last_move)
		{
		case 1://right
			if (board[bulli_y][bulli_x + 1] != '#' &&
				board[bulli_y][bulli_x + 1] != '*') {
				bulliman->x_pos++;
				if (board[bulli_y][bulli_x + 1] != ' ')
					update_food(food_left, *last_move);
			}
			break;
		case 2://left
			if (board[bulli_y][bulli_x - 1] != '#' &&
				board[bulli_y][bulli_x - 1] != '*') {
				bulliman->x_pos--;
				if (board[bulli_y][bulli_x - 1] != ' ')
					update_food(food_left, *last_move);
			}
			break;
		case 3://up
			if (board[bulli_y - 1][bulli_x] != '#' &&
				board[bulli_y - 1][bulli_x] != '*') {
				bulliman->y_pos--;
				if (board[bulli_y - 1][bulli_x] != ' ')
					update_food(food_left, *last_move);
			}
			break;
		case 4://down
			if (board[bulli_y + 1][bulli_x] != '#' &&
				board[bulli_y + 1][bulli_x] != '*') {
				bulliman->y_pos++;
				if (board[bulli_y + 1][bulli_x] != ' ')
					update_food(food_left, *last_move);
			}
			break;
		}
		break;
	default:
		printf("invalid move");
		*last_move = move;
	}
}


//void snail_bear_last_cell(char board[][N], character* snail_bear, char* last_cell) {
//
//}


void move_snail_bear(char board[][N],character* bulliman, character* snail_bear, char* last_place){

	int bulli_x = bulliman->x_pos;
	int bulli_y = bulliman->y_pos;
	int bear_x = snail_bear->x_pos;
	int bear_y = snail_bear->y_pos;

	board[bear_y][bear_x] = *last_place;//delete snail_bear pos

	//where to move bear
	int bear_x_shift = bulli_x - bear_x;
	int bear_y_shift = bulli_y - bear_y;

	//move right
	if (bear_x_shift>0 && board[bear_y][bear_x+1] != '#' && board[bear_y][bear_x + 1] != '*')
		snail_bear->x_pos++;
	//move left
	else if(bear_x_shift<0 && board[bear_y][bear_x - 1] != '#' && board[bear_y][bear_x - 1] != '*')
		snail_bear->x_pos--;
	//move down
	if (bear_y_shift > 0 && board[bear_y + 1][bear_x] != '#' && board[bear_y + 1][bear_x] != '*')
		snail_bear->y_pos++;
	//move up
	else if (bear_y_shift < 0 && board[bear_y - 1][bear_x] != '#' && board[bear_y - 1][bear_x] != '*')
		snail_bear->y_pos--;

	*last_place = board[snail_bear->y_pos][snail_bear->x_pos];
}


int is_bear_next_to_bulli(char board[][N], character* bulliman, character* snail_bear) {
	int bulli_x = bulliman->x_pos;
	int bulli_y = bulliman->y_pos;
	int bear_x = snail_bear->x_pos;
	int bear_y = snail_bear->y_pos;
	
	int bear_x_shift = bulli_x - bear_x;
	int bear_y_shift = bulli_y - bear_y;

	if (bear_x_shift == 1 && bear_y_shift == 1)//above to the right
		return 1;
	else if (bear_x_shift == -1 && bear_y_shift == 1)//above to the left
		return 1;
	else if (bear_x_shift == 1 && bear_y_shift == -1)//below to the right
		return 1;
	else if (bear_x_shift == -1 && bear_y_shift == -1)//below to the left
		return 1;
	else if (!bear_x_shift && bear_y_shift == 1)//above
		return 1;
	else if (!bear_x_shift && bear_y_shift == -1)//below
		return 1;
	else if (bear_x_shift == 1 && !bear_y_shift)//right
		return 1;
	else if (bear_x_shift == -1 && !bear_y_shift)//left
		return 1;
	else
		return 0;
}
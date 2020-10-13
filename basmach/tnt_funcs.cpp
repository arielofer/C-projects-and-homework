#include "tnt_funcs.h"

//direction array
dir_array moves[5] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

//clear screen
void clr_screen() {
	system("@cls||clr");
}

//-----------------------------------------------------------------------------
//								Board Build
//								-----------
//
// General : The function gets a matrix(board) and an int n(number of trons), 
//   inserts safety walls around the matrix and inserts n trons to the matrix using
//   coordinets from user input.
//
// Parameters :
// board (In)
// n (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void board_build(int board[][N + 2], int n) {
	//setup kir bitachon
	for (int i = 0; i < N + 2; i++)
		board[N * 2 + 1][i] = board[0][i] = -1;

	for (int i = 0; i < N * 2 + 2; i++)
		board[i][N + 1] = board[i][0] = -1;

	//insert trons
	int x, y;
	for (int i = 0; i < n; i++) {
		printf("enter tron coordinates:\n");
		scanf("%d %d", &x, &y);
		
		if ((x >= 1 && x <= N * 2) && (y >= 1 && y <= N - 2))
			board[x][y]++;
		else
		{
			printf("invalid coordinates for a tron!\n");
			i--;
		}
	}
}

//-----------------------------------------------------------------------------
//								print Board
//								-----------
//
// General : The function gets a matrix(board) and prints it. 
//
// Parameters :
// board (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void print_board(int board[][N + 2]) {

	clr_screen();//get rid of old output
	for (int i = 0; i < N * 2 + 2; i++) {
		for (int j = 0; j < N + 2; j++)
			printf(" %d", board[i][j]);
		printf("\n");
	}
}

//-----------------------------------------------------------------------------
//								Control Trof
//								------------
//
// General : The function gets a matrix(board), then gets user input to
//	move the Trof (theoreticly) around the matrix to eat the trons.
//
// Parameters :
// board (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void con_trof(int board[][N + 2])
{
	int trof_x, trof_y, amount_steps, move_arr_index;

	while (true)
	{
		printf("enter trof coordinates:\n");
		scanf("%d %d", &trof_x, &trof_y);
		
		if ((trof_x >= 1 && trof_x <= N * 2) && (trof_y >= 1 && trof_y <= N))
			break;
		else
			printf("invalid coordinates for trof!\n");
	}

	//check if there are trons in initial pos
	if (board[trof_x][trof_y] > 0)
	{
		if (board[trof_x][trof_y] <= 2)
		{
			printf("in pos %d, %d trof met %d and ate them\n", trof_x, trof_y,
				board[trof_x][trof_y]);
			board[trof_x][trof_y] = 0;
		}
		else
		{
			printf("in pos %d, %d trof met %d and died\n", trof_x, trof_y,
				board[trof_x][trof_y]);
			return; //exit;
		}
	}
	
	printf("enter amount of steps and direction for trof:\n");
	scanf("%d %d", &amount_steps, &move_arr_index);
	while (amount_steps != 0 && move_arr_index != 0)
	{
		for (int i = 0; i < amount_steps; i++)
		{
			if (board[trof_x + moves[move_arr_index].ncol][trof_y + moves[move_arr_index].nline] != -1)
			{
				trof_x += moves[move_arr_index].ncol;
				trof_y += moves[move_arr_index].nline;

				if (board[trof_x][trof_y])
				{
					if (board[trof_x][trof_y] <= 2)
					{
						printf("in pos %d, %d trof met %d and ate them\n", trof_x, trof_y,
							board[trof_x][trof_y]);
						getchar();
						board[trof_x][trof_y] = 0;
					}
					else
					{
						printf("in pos %d, %d trof met %d and died\n", trof_x, trof_y,
							board[trof_x][trof_y]);
						getchar();
						return; //exit;
					}
				}
			}
			else
			{
				printf("cant walk outside of the planet!\n");
				break;
			}
		}

		printf("enter amount of steps and direction for trof:\n");
		scanf("%d %d", &amount_steps, &move_arr_index);
	}

	printf("trof became tired\n");
}
#include "tnt_funcs.h"

int main()
{
	int board[N * 2 + 2][N + 2] = { 0 }, num_of_trons;
	
	printf("enter number of trons:\n");
	scanf("%d", &num_of_trons);
	board_build(board, num_of_trons);
	print_board(board);
	con_trof(board);

	return 0;
}
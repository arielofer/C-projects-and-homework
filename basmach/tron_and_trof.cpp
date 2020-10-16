#include "tnt_funcs.h"

//-----------------------------------------------------------------------------
// tron & trof
// -----------
//
// General : The program builds the tron planet and moves the trof
//			 around according to user input.
//
// Input : number of trons.
//
// Process : insert number of trons to the matrix according to user input
//			 coordinets, then according to user input scan the matrix.
//
// Output : Prints status of trof in the end of the scan(dead or tired).
//
//-----------------------------------------------------------------------------
// Programmer : Ariel Ofer
// Date : 13.10.2020
//-----------------------------------------------------------------------------
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
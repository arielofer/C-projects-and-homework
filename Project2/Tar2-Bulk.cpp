#define _CRT_SECURE_NO_WARNINGS
#include "Bulk_funcs.h"

int main()
{
	char board[N][N], *str;

	printf("enter %d characters to initialize the board\n", (N-2)*(N-2));
	board_build(board);
	print_board(board);

	//word search
	printf("enter word to search: ");
	getchar();
	str = get_string();
	word_search(board, str);

	return 0;
}
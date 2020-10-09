#define _CRT_SECURE_NO_WARNINGS
#include "Bulk_funcs.h"

//clear screen
void clrscreen() {
	system("@cls||clr");
}

//direction array
Coordinate moves[8] = { {-1, 1}, {0, 1}, {1, 1},
			 {-1, 0},         {1, 0},
			 {-1, -1},{0, -1},{1, -1} };


//-----------------------------------------------------------------------------
//								Board Build
//								-----------
//
// General : The function gets a matrix(the board), and inserts chararcters 
//	recieved from the users into the matrix
//
// Parameters :
// Board (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void board_build(char board[][N])
{
	char chr;
	//setup kir bitachon
	for (int i = 0; i < N; i++)
	{
		board[0][i] = board[i][0] = '#';
		board[i][N - 1] = board[N - 1][i] = '#';
	}

	//insert characters
	for (int i = 1; i < N - 1; i++)
	{
		for (int k = 1; k < N - 1; k++)
		{
			scanf(" %c", &chr);
			if (chr >= 65 && chr <= 90) chr += 32;
			board[i][k] = chr;
		}
	}
}

//-----------------------------------------------------------------------------
//								Get String
//								----------
//
// General : The function gets input from user, builds a dynamic 
//	string and return it
//
// Parameters :
//
// Return Value : a pointer to a dynamic string.
//
//-----------------------------------------------------------------------------
char* get_string()
{
	char chr;
	int len = 1;
	char* str = NULL;
	str = (char*)realloc(str, sizeof(char) * (len + 1));
	chr = getchar();
	str[len - 1] = chr;
	while (chr != '\n')
	{
		chr = getchar();
		++len;
		str = (char*)realloc(str, sizeof(char) * (len + 1));
		str[len - 1] = chr;
		if (len == MAX_STRING_LENGTH) break;
	}
	str[len - 1] = '\0';
	return str;
}

//-----------------------------------------------------------------------------
//								Print Board
//								-----------
//
// General : The function gets a matrix(the board), and prints it
//
// Parameters :
// board (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void print_board(char board[][N])
{
	clrscreen();//get rid of old output
	
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++)
			printf(" %c", board[i][j]);
		printf("\n");
	}
}
//-----------------------------------------------------------------------------
//								Check is word
//								-------------
//
// General : The function gets a matrix(the board),a word, the location of the
//   first letter in the matrix and a direction array, and checks if the word
//   appears after that letter in the matrix.
//
// Parameters :
// board (In)
// word (In)
// pos (In)
// moves(In)
//
// Return Value : 1 if the word was found, 0 if not
//
//-----------------------------------------------------------------------------
int CheckIsWord(char board[][N], char* word, Coordinate pos, Coordinate moves[])
{
	int i, j, shift_x = 0, shift_y = 0;
	char let;

	let = word[1];
	if (let >= 65 && let <= 90) let += 32;
	
	//find if the next letter is around the first one
	for (i = 0; i < 8; i++)
	{
		if (let == board[pos.x + moves[i].x][pos.y + moves[i].y])
		{
			shift_x = moves[i].x;
			shift_y = moves[i].y;
			pos.x += shift_x;
			pos.y += shift_y;
			break;
		}
	}

	if (!shift_x && !shift_y) return 0;
	else //keep scanning the matrix in the same direction
	{
		for (j = 2; j < strlen(word); j++)
		{
			let = word[j];
			if (let >= 65 && let <= 90) let += 32;

			if (let == board[pos.x + shift_x][pos.y + shift_y])
			{
				pos.x += shift_x;
				pos.y += shift_y;
			}
			else break;
		}

		if (j == strlen(word)) return 1;
		else return 0;
	}
}

//-----------------------------------------------------------------------------
//								Word Search
//								-----------
//
// General : The function gets a matrix(the board) and a word, and prints
//   the location of the first letter if it exists in the matrix, if not
//   the function prints "Not found".
//
// Parameters :
// board (In)
// word (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void word_search(char board[][N], char* word)
{
	char let;
	Coordinate pos = {-1, -1};
	int found = 0;

	for (int i = 1; i < N-1; i++)
	{
		let = word[0];
		if (let >= 65 && let <= 90) let += 32;

		for (int j = 1; j < N-1; j++)
		{
			if (let == board[i][j])
			{
				pos.x = i, pos.y = j;
				found = CheckIsWord(board, word, pos, moves);
			}

			if (found)
			{
				printf("[%d][%d]", pos.x-1, pos.y-1);
				return; //dont continue searching
			}
		}
	}

	printf("word not found");
}
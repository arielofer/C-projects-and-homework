#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void gameplay(int mat[][N]) {
	int player1, player2;
	player1 = player2 = 0;
	int row, col;
	srand(time(NULL));
	while (player1 < 1000 && player2 < 1000) {
		//player 1
		row = rand() % (N + 1 - 1) + 1;
		col = rand() % (N + 1 - 1) + 1;
		printf("player1 rolled %d %d, which is worth %d points\n", row, col, mat[row - 1][col - 1]);
		player1 += mat[row - 1][col - 1];
		printf("player1 is at %d\n", player1);
		if (player1 >= 1000)
			break;
		//player 2
		row = rand() % (N + 1 - 1) + 1;
		col = rand() % (N + 1 - 1) + 1;
		printf("player2 rolled %d %d, which is worth %d points\n", row, col, mat[row - 1][col - 1]);
		player2 += mat[row - 1][col - 1];
		printf("player2 is at %d\n", player2);
	}

	printf("%s won!\n", (player1 > player2) ? "player1" : "player2");
}


//int main() {
//	int mat[N][N]={20,30,10,50,100,10,40,90,1,25,50,100,20,30,10,50,100,10,40,90,1,25,50,100,1};
//	gameplay(mat);
//
//	return 0;
//}
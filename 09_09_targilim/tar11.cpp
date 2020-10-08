#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 6

void getUpperLeft(int mat[][N], int n, int* row, int* col) {
	for (int i = n - 1, j = n - 1; i >= 0 && j >= 0; i--, j--) {
		if (!mat[i][n - 1] && mat[i + 1][n - 1])
			*row = i+1;
		if (!mat[n - 1][j] && mat[n - 1][j + 1])
			*col = j+1;
	}
}


int main() {
	int mat[N][N] = {{0,0,0,0,0,0},
					 {0,0,1,1,1,1},
					 {0,0,1,1,1,1},
					 {0,0,1,1,1,1},
					 {0,0,1,1,1,1},
					 {0,0,1,1,1,1}
	};

	int row, col;
	getUpperLeft(mat, 6, &row, &col);
	printf("%d %d", row, col);

	return 0;
}
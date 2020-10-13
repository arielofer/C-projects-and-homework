#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 4

int isbig(int mat[][N + 2], int i, int j) {
	for (int k = i - 1; k <= i + 1; k++) {
		for (int w = j - 1; w <= j + 1; w++)
			if (w != j || k != i)
				if (mat[k][w] > mat[i][j])
					return 0;
	}
	return 1;
}

int countisbig(int mat[][N + 2]) {
	int count = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++)
			count += isbig(mat, i, j);
	}
	return count;
}

void not_main() {
	int mata[N][N] = { {8,2,13,4},
					   {6,7,8,9},
					   {10,20,12,13},
					   {1,2,3,4}};

	int matb[N + 2][N + 2];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			matb[i + 1][j + 1] = mata[i][j];
	}

	for (int i = 0; i < N + 2; i++) {
		matb[0][i] = matb[i][0] = -1;
		matb[i][N + 1] = matb[N + 1][i] = -1;
	}

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++)
			printf("%d ", matb[i][j]);
		printf("\n");
	}	

	printf("\n%d", countisbig(matb));
}
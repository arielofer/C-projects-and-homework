#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4

int IsRow(int A[][N], int row) {
	int count;
	for (int j = 1; j <= 4; j++) {
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (A[row][i] == j) {
				count++;
			}
		}
		if (count != 1)
			return 0;
	}
	return 1;
}


int IsCol(int A[][N], int col) {
	int count;
	for (int j = 1; j <= 4; j++) {
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (A[i][col] == j) {
				count++;
			}
		}
		if (count != 1)
			return 0;
	}
	return 1;
}


int Is2x2(int A[][N], int r, int c) {
	int count;
	for (int i = 1; i <= 4; i++) {
		count = 0;
		for (int j = 0; j <= 1; j++) {
			if (A[r][c + j] == i)
				count++;
		}
		int temp = r + 1;
		for (int j = 0; j <= 1; j++) {
			if (A[temp][c + j] == i)
				count++;
		}
		if (count != 1)
			return 0;
	}
	return 1;
}


int isQuarter(int mat[][N]) {
	return Is2x2(mat, 0, 0) && Is2x2(mat, 0, 2) && Is2x2(mat, 2, 0) && Is2x2(mat, 2, 2);
}

int isSoduko(int mat[][N]) {
	int ok = 1;
	for (int i = 0; i < 4; i++) {
		ok = IsRow(mat, i) && IsCol(mat, i);
		if (!ok)
			return ok;
	}
	ok = isQuarter(mat);
	return ok;
}


//int main() {
//	int mat[N][N] = { {1,2,3,4},
//					  {3,4,2,1},
//					  {2,1,4,3},
//					  {4,3,1,2}
//					};
//	printf("%d\n", IsRow(mat, 0));
//	printf("%d\n", IsCol(mat, 1));
//	printf("%d\n", Is2x2(mat, 0, 2));
//	printf("%d\n", isQuarter(mat));
//	printf("%d", isSoduko(mat));
//
//	return 0;
//}
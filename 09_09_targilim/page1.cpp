#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 4
#define M 4
//tar1
void max_in_row(int mat[][M], int arr[]) {
	int max;
	for (int i = 0; i < N; i++) {
		max = mat[i][0];
		for (int j = 1; j < M; j++) {
			if (max < mat[i][j])
				max = mat[i][j];
		}
		arr[i] = max;
	}
}

//yona solve
int maxrow(int A[M]) {
	int max = 0;
	for (int i = 0; i < M; i++) {
		if (A[i] > A[max])
			max = i;
	}
	return A[max];
}


void maxall(int mat[][4], int arr[]) {
	for (int i = 0; i < 3; i++) {
		arr[i] = maxrow(mat[i]);
	}
}

//tar2
void check_mat_for_negative(int mat[][M]) {
	int is_negative = 1, is_typ = 1;

	for (int i = 0; i < M; i++) {//main alachson
		if (mat[i][i] != 0){
			is_typ = 0;
			break;
		}
	}

	for (int i = 0; i < M; i++) {//secondery
		if (mat[i][M - (i + 1)] != 0) {
			is_typ = 0;
			break;
		}
	}

	for (int i = 0; i < M; i++) {//check other cells
		for (int j = 0; j < M; j++) {
			if (i != j && i + j != M - 1) {
				if (mat[i][j] >= 0) {
					is_negative = 0;
					break;
				}
			}
		}
	}
	if (is_negative && is_typ)
		printf("ok");

}

//tar3
void hekef(int mat[][M]) {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		sum += mat[0][i] + mat[M - 1][i];;
	}
	for (int i = 1; i < M - 1; i++) {
		sum += mat[i][0] + mat[i][M - 1];
	}
	printf("hekef is %d", sum);
}

//tar4
void complete_mirror(int mat[][M]) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			mat[j][i] = mat[i][j];
		}
	}
}
//tar5
int ribua_kesem(int mat[][M]) {
	int sum = 0, sum1 = 0, sum2 = 0;
	for (int i = 0; i < M; i++) {
		sum += mat[i][i];
		sum1 += mat[i][M - (i + 1)];
	}
	if (sum != sum1)
		return 0;
	for (int i = 0; i < M; i++) {
		sum1 = sum2 = 0;
		for (int j = 0; j < M; j++) {
			sum1 += mat[i][j];
			sum2 += mat[j][i];
		}
		if (sum1 != sum || sum2 != sum)
			return 0;
	}
	return 1;
}
//tar6
int factorial(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}
int n_above_k(int n, int k){
	return factorial(n) / (factorial(k) * factorial(n - k));
}
void pascal(int mat[][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= i; j++) {
			mat[i][j] = n_above_k(i, j);
		}
	}
}
//tar6
int symmetry(int A[M][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != A[j][i])
				return 0;
		}
	}
	return 1;
}
//int main() {
//	//int mat[N][M] = { {5,3,1,2},{8,5,6,9}, {4,8,3,8} };
//	//int arr[N];
//	//max_in_row(mat, arr);
//	//maxall(mat, arr);
//	//for (int i = 0; i < N; i++) {
//	//		printf("%d", arr[i]);
//	//}
//
//	//int mat1[M][M] = { {3},{5,6}, {7,8,9}, {2,1,0,4} };
//	//check_mat_for_negative(mat1);
//	//hekef(mat1);
//	//complete_mirror(mat1);
//	/*for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			printf("%d ",mat1[i][j]);
//		}
//		printf("\n");
//	}*/
//	/*int mat2[3][3] = { {6,1,8}, {7,5,3}, {2,9,4} };
//	if (ribua_kesem(mat2))
//		printf("ok\n");
//	int mat3[6][6];*/
//	/*pascal(mat3);
//	for (int i = 0; i < 6; i++) {
//		for (int j = 0; j <= i; j++) {
//			printf("%d ",mat3[i][j]);
//		}
//		printf("\n");
//	}*/
//	int mat5[N][M] = { {3,5,7,2}, {5,6,8,1}, {7,8,9,0},{2,1,0,4} };
//	if (symmetry(mat5))
//		printf("ok");
//
//	return 0;
//}
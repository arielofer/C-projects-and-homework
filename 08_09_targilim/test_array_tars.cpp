#include "array_tars.h"
#include <stdio.h>


//int main() {
//
//	//tar1
//	/*int arr[14] = { 0, 22, 1, 45, 7, 0, 1 };
//	int arr2[] = { 45, 30, 1, 7, 0, 0, 1 };
//	int* ptr; int len = 7; ptr = &len;
//	add_arrays(arr, ptr, arr2, 7);
//	for (int i = 0; i < *ptr; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	//2
//	int arr3[] = { 0, 22, 1, 45, 7, 0, 1 };
//	int arr4[7];*/
//	int len; //ptr = &len;
//	/*common_vals(arr3, ptr, arr2, len, arr4);
//	for (int i = 0; i < *ptr; i++) {
//		printf("%d ", arr4[i]);
//	}
//	printf("\n");*/
//	//3
//	/*int A[] = { 1,2,5,7,8,11 };
//	int B[] = { 2,3,4,6,9 };
//	int C[11];
//	fuse_and_sort(A, 6, B, 5, C);
//	for (int i = 0; i < 11; i++) {
//		printf("%d ", C[i]);
//	}
//	printf("\n");*/
//	int D[7] = { 1,12,51,7,8,1,0 };
//	int E[7] = {};
//	len = 7;
//	sort_by_insert(D, len, E);
//	//insert(D, len, 3);
//	for (int i = 0; i < len; i++) {
//		printf("%d ", E[i]);
//	}
//	printf("\n");
//	//tar5
//	//bubble_sort(D,0, 7);
//	//tar6
//	sort_range(D,7, 2, 5);
//	for (int i = 0; i < len; i++) {
//		printf("%d ", D[i]);
//	}
//	printf("\n");
//	//tar7
//	int num = 293316;
//	int dig_arr[10] = {0,0,0,0,0,0,0,0,0};
//	count_digs(num, dig_arr);
//	for (int i = 0; i < 10; i++) {
//		printf("%d : %d,", i, dig_arr[i]);
//	}
//	printf("\n");
//	//tar8
//	int F[] = { 2,3,4,4,4,5,5,6,2,1,1,1,1,5,4 };
//	int max = biggest_rezef(F, sizeof(F) / sizeof(int));
//	printf("max is: %d\n", max);
//	//tar9
//	printf("%s", all_diff(D, 7) ? "all diff\n" : "not\n");
//	//tar10
//	int A[] = { 2,3,1 };
//	int B[] = { 3,5,10,2,3,1 };
//	printf("%s", is_contained(B, 6, A, 3) ? "ok\n" : "not contained\n");
//	printf("%s", is_rezef_contained(B, 6, A, 3) ? "ok\n" : "not contained\n");
//	return 0;
//}
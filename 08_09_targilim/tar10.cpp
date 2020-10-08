#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ole_yored(int arr[], int n) {
	for (int i = 0; i <= n - 2; i++) {
		if (arr[i] > arr[i + 1])
			return arr[i];
	}
}


//int main() {
//	int arr[] = { 10, 22, 24, 45, 50, 30, 21, 20, 3 };
//	printf("%d", ole_yored(arr, sizeof(arr) / sizeof(int)));
//
//	return 0;
//}
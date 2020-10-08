#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define length 9

int find_change(int arr[], int n, int start) {
	for (int i = start; i < n-1; i++) {
		if (arr[i] % 2 == 0 && arr[i + 1] % 2 != 0)
			return i;
	}
	return length;
}


//int main() {
//	int arr[] = { 10, 22, 16, 45, 7, 30, 1, 28, 3 };
//	int answers[length];
//	int index = find_change(arr, length, 0);
//	int j = 0;
//	while (index != length) {
//		answers[(j)++] = index;
//		index = find_change(arr, length, index + 1);
//	}
//	printf("%d", answers[rand() % ((j-1) + 1 - 0) + 0]);
//
//	return 0;
//}
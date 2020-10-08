#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void grades(int arr[]) {
	int length = 7, temp;
	for (int i = 1; i < length; i++) {
		for (int k = i; k > 0; k--) {
			if (arr[k] > arr[k - 1]) {
				temp = arr[k-1];
				arr[k - 1] = arr[k];
				arr[k] = temp;
			}
		}
	}
}


//int main() {
//	int arr[] = { 10, 22, 15, 45, 7, 30, 1 };
//	grades(arr);
//	for (int i = 0; i < 7; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
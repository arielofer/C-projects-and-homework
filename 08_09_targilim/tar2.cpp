#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void print_min_index(int arr[],int length) {
	int min = arr[0];
	int i;
	for (i = 1; i < length; i++) {
		if(arr[i] < min)
			min = arr[i];
	}

	for (i = 0; i < length; i++) {
		if(arr[i] == min)
			printf("%d ", i + 1);
	}
}


//int main() {
//	int arr[] = { 5, 6, 10, 13, 4, 6, 7, 4 };
//	print_min_index(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}
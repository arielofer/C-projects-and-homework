#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define n 5


void create_new_array(int arr1[],int arr2[], int *length) {
	for (int i=0;i<n;i++)
	{
		if (arr1[i] % 2 == 0)
			arr2[(*length)++] = arr1[i];
	}
}


//int main() {
//	int length = 0;
//	int arr[] = { 1, 2, 5, 10, 6};
//	int new_arr[n];
//
//	create_new_array(arr, new_arr, &length);
//	printf(" %c", '[');
//	for (int i = 0; i < length; i++) {
//		printf(" %d,", new_arr[i]);
//	}
//	printf(" %c", ']');
//
//	return 0;
//}
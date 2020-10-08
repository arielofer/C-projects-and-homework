#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void seder_yored(int arr[], int length) {
	int current = 1, max, index;
	max = index = current;
	for (int i = 0; i < length -1; i++) {
		if (arr[i] >= arr[i + 1]) {
			current++;
		}
		else
		{
			if (max < current) {
				max = current;
				index = (i + 1) - (current - 1);
			}
			current = 1;
		}
		if (max < current) {
			max = current;
			index = (i + 1) - (current - 2);
		}
	}
	printf("%d", index);
}


//int main() {
//	int arr[]{ 4, 3, 2, 5, 6, 4};
//	seder_yored(arr, (sizeof(arr) / sizeof(arr[0])));
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void trips2() {
	int num1, num2, num3, super_max = -99999, super_max_index = 0;
	float avg_of_trips = 0;
	for (int i = 1; i <= 6; i++) {
		scanf("%d,%d,%d", &num1, &num2, &num3);
		int max = num1;
		int arr[2]{ num2, num3 };
		for (int j = 0; j < 2; j++) {
			if (arr[j] > max)
				max = arr[j];
		}
		if (super_max < max) {
			super_max = max;
			super_max_index = i;
		}

		printf("max number is: %d \n", max);
		if (max >= 0)
			printf("sqrt is: %d \n", (int)sqrt(max));
		else
			printf("no sqrt\n");
	}
	printf("absolute max is: %d and triplet index is: %d \n", super_max, super_max_index);
}


//int main() {
//	trips2();
//
//	return 0;
//}
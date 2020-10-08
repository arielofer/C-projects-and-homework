#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int dig_sum(int num) {
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}


int maximum_sum() {
	int N, num, sum, max_num, max_sum;
	scanf("%d", &N);
	scanf("%d", &num);
	max_sum = sum = dig_sum(num);
	max_num = num;
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		sum = dig_sum(num);
		if (max_sum < sum) {
			max_sum = sum;
			max_num = num;
		}
	}

	return max_num;
}


//int main() {
//	printf("max num is: %d", maximum_sum());
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int tur(int N) {
	int sum = 1;
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0)
			sum -= i;
		else
			sum += i;
	}

	return sum;
}

int tur2(int N) {
	return ((N % 2 == 0) ? (N / 2 * -1) : (N / 2 + 1));
}

//int main() {
//	int num;
//	printf("enter a number\n");
//	scanf("%d", &num);
//	printf("sum is %d", tur(num));
//	printf("sum is %d", tur2(num));
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void nekuda(float num) {
	int counter = 0;
	while (num > 1) {
		counter++;
		num /= 10;
	}

	printf("%d", counter);
}


//int main() {
//	float num;
//	printf("enter a real number\n");
//	scanf("%f", &num);
//	nekuda(num);
//
//	return 0;
//}
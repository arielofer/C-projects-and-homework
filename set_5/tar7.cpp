#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int shr(int bin) {
	int temp = bin;
	while (temp) {
		if (temp % 10 != 1 && temp % 10 != 0) {
			printf("non binary");
			return 0;
		}
		temp /= 10;
	}
	return bin / 10;
}


void divide(int bin, int times) {
	if (times <= 4) {
		for (int i = 0; i < times; i++)
			bin = shr(bin);
		printf("%d", bin);
	}
	else
		printf("error");
}
//int main() {
//	int num, times;
//	scanf("%d %d", &num, &times);
//	divide(num, times);
//
//	return 0;
//}
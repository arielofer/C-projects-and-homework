#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void perfect_num_check(int num) {
	int perfect_num = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0)
			perfect_num += i;
	}
	printf("%s", perfect_num == num ? "perfect num": "not perfect");
}


//int main() {
//	int num;
//	printf("enter a number\n");
//	scanf("%d", &num);
//	perfect_num_check(num);
//
//	return 0;
//}
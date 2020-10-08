#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int rand_in_range(int num1, int num2) {
	if (num1 > num2)
		return rand() % (num1 + 1 - num2) + num2;
	else
		return rand() % (num2 + 1 - num1) + num1;
}


void rand_o_five() {
	int num1, num2, rnd = 0;
	scanf("%d %d", &num1, &num2);
	while (num1 != -999 && num2 != -999) {
		for (int i = 0; i < 5; i++) {
			rnd = rand_in_range(num1, num2);
			printf("rand is %d\n", rnd);
		}
		scanf("%d %d", &num1, &num2);
	}
}
//int main() {
//	rand_o_five();
//
//	return 0;
//}
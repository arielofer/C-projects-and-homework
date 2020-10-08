#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void akrai() {
	int six_count = 0, min = 999;
	for (int i = 0; i < 50; i++) {
		int num = rand() % (6 + 1 - 1) + 1;
		printf("%d \n", num);
		if (num == 6)
			six_count++;
		if (num < min)
			min = num;
	}
	printf("numer of times 6 appeared: %d, minimum number: %d \n", six_count, min);
}


//int main() {
//	akrai();
//}
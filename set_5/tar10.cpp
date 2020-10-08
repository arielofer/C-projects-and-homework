#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void special_three_dig() {
	for (int i = 100; i < 1000; i++) {
		if ((i / 100) + (i / 10 % 10) == (int)pow(i % 10, 2))
			printf("%d\n", i);
	}
}


//int main() {
//	special_three_dig();
//
//	return 0;
//}
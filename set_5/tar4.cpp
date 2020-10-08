#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int perfect_num_check(int num) {
	int perfect_num = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0)
			perfect_num += i;
	}
	return (perfect_num == num ? 1 : 0);
}


void prfct_print() {
	for (int i = 1; i <= 10000; i++) {
		if (perfect_num_check(i))
			printf("%d\n", i);
	}
}

//int main() {
//	prfct_print();
//
//	return 0;
//}
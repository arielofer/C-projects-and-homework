#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int dig_count(int num, int dig_to_find) {
	int counter = 0;
	while (num) {
		if (num % 10 == dig_to_find)
			counter++;
		num /= 10;
	}

	return counter;
}


//int main() {
//	int num, dig;
//	printf("enter a number and a digit to look for\n");
//	scanf("%d %d", &num, &dig);
//	printf("digit %d is in %d %d times", dig, num, dig_count(num, dig));
//
//	return 0;
//}
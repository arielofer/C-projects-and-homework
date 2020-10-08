#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void reverse(long int num) {
	long int rev = 0, dig_count = 0;
	while (num) {
		/*if (num % 10 == 0)
			zero_count++;*/
		dig_count++;
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	int rev_dig_count = 0, temp = rev;
	while (temp) {
		rev_dig_count++;
		temp /= 10;
	}
	for (int i = 0; i < (dig_count - rev_dig_count); i++)
		printf("0");
	printf("%ld", rev);
}


//int main() {
//	long int num;
//	scanf("%ld", &num);
//	reverse(num);
//
//	return 0;
//}
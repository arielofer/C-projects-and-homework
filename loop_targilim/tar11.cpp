#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void sfarot_and_sum(int num) {
	int digits = 0, sum = 0,temp = num;
	if (temp > 0) {
		while (temp) {
			digits++;
			sum += temp % 10;
			temp /= 10;
		}
		printf("%d has %d digits and they\'re sum is %d", num, digits, sum);
	}
	else
		printf("invalid input");
}


//int main() {
//	int num;
//	scanf("%d", &num);
//	sfarot_and_sum(num);
//
//	return 0;
//}
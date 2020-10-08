#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int diff_dig(int num) {
	if (num > 0) {
		int temp, dig;
		while (num) {
			temp = num;
			dig = temp % 10;
			temp /= 10;
			while (temp) {
				if (temp % 10 == dig)
					return 0;
				temp /= 10;
			}
			num /= 10;
		}
		return 1;
	}
	else {
		printf("error - not a natural number");
		return 0;
	}
}


void count_diff_dig() {
	int num, count = 0;
	scanf("%d", &num);
	while (diff_dig(num)) {
		count++;
		scanf("%d", &num);
	}
	printf("%d, %d before him", num, count);
}


//int main() {
//	count_diff_dig();
//
//	return 0;
//}
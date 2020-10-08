#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int palindrom(int num) {
	int rev = 0, temp = num;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}

	return rev;
}


int special_num(int num) {
	int rev = palindrom(num);
	return (rev == num * 4);
}


int main() {
	int count = 0;
	for (int i = 1000; i < 1000000; i++) {
		if (special_num(i)) {
			printf("%d\n", i);
			count++;
		}
	}
	printf("%d", count);

	return 0;
}
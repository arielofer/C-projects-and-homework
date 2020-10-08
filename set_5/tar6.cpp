#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void dig_appear(int num, int dig) {
	int i = 1;
	int found = 0;
	while(num){
		if (num % 10 == dig) {
			printf("%d ", i);
			found = 1;
		}
		i++;
		num /= 10;
	}
	if (!found)
		printf("0");
	printf("\n");
}


void dig_lookup() {
	int num;
	scanf("%d", &num);
	for (int j = 0; j <= 9; j++) {
		printf("%d: ", j);
		dig_appear(num, j);
	}
}


//int main() {
//	dig_lookup();
//
//	return 0;
//}
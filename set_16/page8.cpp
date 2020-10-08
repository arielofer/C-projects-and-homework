#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int* create_vector(int num1, int num2) {
	int* vcr, len = 1, temp, sum;
	vcr = (int*)calloc(len, sizeof(int));
	vcr[len - 1] = -1;
	for (int i = 0; i <= num1; i++) {
		sum = 0;
		temp = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == num2) {
			vcr = (int*)realloc(vcr, ++len * sizeof(int));
			vcr[len - 2] = i;
		}
	}
	vcr[len - 1] = -1;
	return vcr;
}


int main() {
	int num1, num2, * vector;
	scanf("%d %d", &num1, &num2);
	vector = create_vector(num1, num2);
	for (int i = 0; vector[i] != -1; i++) {
		printf("%d, ", vector[i]);
	}

	return 0;
}
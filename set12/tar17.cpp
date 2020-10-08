#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


int num_len(int num) {
	int length = 0;
	while (num) {
		length++;
		num /= 10;
	}

	return length;
}

void create_num(int num1, int num2, int new_num[]) {
	int i, dig = 0;
	int length1 = num_len(num1), length2 = num_len(num2);
	for (i = 0; num1; i++) {
		dig = num1 / pow(10, length1 - 1 - i);
		new_num[i] = dig;
		num1 -= dig * pow(10, length1 - 1 - i);
	}
	for (int j = 0; num2; i++, j++) {
		dig = num2 / pow(10, length2 - 1 - j);
		new_num[i] = dig;
		num2 -= dig * pow(10, length2 - 1 - j);
	}
}


//int main() {
//	int num1 = 9876, num2 = 54321;
//	int arr[10];
//	create_num(num1, num2, arr);
//	for (int i = 0; i < 9; i++)
//		printf("%d", arr[i]);
//
//	return 0;
//}
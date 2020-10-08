#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int build_nums_and_sum(char arr[]) {
	int num1, num2;num1 = num2 = 0;
	int wheight1, wheight2;
	wheight1 = wheight2 = 0;
	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] % 2 == 0) {
			num1 = num1 + int(arr[i] - '0') * int(pow(10, wheight1));
			wheight1++;
		}
		else {
			num2 = num2 + int(arr[i] - '0') * int(pow(10, wheight2));
			wheight2++;
		}
	}
	return num1 + num2;
}


//int main() {
//	//num1 = 5315
//	//num = 224
//	char arr[] = "50321245";
//	printf("%d", build_nums_and_sum(arr));
//
//	return 0;
//}
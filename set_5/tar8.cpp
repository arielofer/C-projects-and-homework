#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int threequel(int num1, int num2, int num3) {
	if (num1 == num2 && num2 == num3)
		return 1;
	return 0;
}


void times_of_three(int N) {
	if (N >= 3) {
		for (int i = 3; i <= N; i = i + 3) {
			printf("%d\n", i);
		}
	}
	else
		printf("number is smaller then 3\n");
}


int dig_count(int num) {
	int counter = 1;
	num /= 10;
	while (num) {
		counter++;
		num /= 10;
	}

	return counter;
}


int build_num() {
	int num=0;
	char dig;
	scanf(" %c", &dig);
	while (dig != '*') {
		num = num * 10 + (int)(dig - '0');
		scanf(" %c", &dig);
	}

	return num;
}


int palin(int num) {
	int rev = 0, temp = num;
	while (temp) {
		rev = rev * 10 + temp % 10;
		temp /= 10;
	}

	return (rev == num);
}


void swap(int* num1, int* num2) {
	int temp;
	if (*num2 > * num1) {
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}
}


int value_bigger_then_next(int arr[], int length) {
	int counter = 0;
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] < arr[i + 1])
			counter++;
	}
	return counter;
}


int double_digit(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] < 10 || arr[i] > 99)
			return 0;
	}

	return 1;
}


void triangle(int N) {
	for (int i = 0; i < (N - 1); i++)
		printf("  ");
	printf("%d\n", 1);
	for (int i = 2; i <= N; i++) {
		int j;
		for (int j = 0; j < (N - i); j++)
			printf("  ");
		for (j = i ; j > 1; j--)
			printf("%d ", j);
		printf("%d ", 1);
		for (j = 2; j <= i; j++)
			printf("%d ", j);
		printf("\n");
	}
}


/*int main() {
	//tar1
	printf("tar1:\n");
	printf("%s", threequel(1, 1, 1)?"equel\n":"not equel\n");//equel
	printf("%s", threequel(2, 2, 1) ? "equel\n" : "not equel\n");//not equel
	//tar2
	printf("tar2:\n");
	times_of_three(10);//3 6 9
	times_of_three(1);//number is smaller then 3
	//tar3
	printf("tar3:\n");
	printf("%d\n", dig_count(100));//3
	printf("%d\n", dig_count(2));//1
	//tar4
	printf("tar4:\n");
	printf("%d\n", build_num());
	//tar5
	printf("tar5:\n");
	printf("%s", palin(121121) ? "simetri\n" : "not simetri\n");//simetri
	printf("%s", palin(121321) ? "simetri\n" : "not simetri\n");//not simetri
	//tar6
	printf("tar6:\n");
	int num1 = 5, num2 = 7;
	swap(&num1, &num2);
	printf("%d, %d\n", num1, num2);//7, 5
	swap(&num1, &num2);
	printf("%d, %d\n", num1, num2);//7, 5
	//tar7
	printf("tar7:\n");
	const int length = 6;
	int arr[length] = {2, 1, 0, 5, 6, 7};
	printf("%d\n", value_bigger_then_next(arr, length));//2 
	//tar8
	printf("tar8:\n");
	arr[0] = 11; arr[1] = 23;
	printf("%s", double_digit(arr, length) ? "true\n" : "false\n");//false
	arr[2] = 34; arr[3] = 90; arr[4] = 67; arr[5] = 10;
	printf("%s", double_digit(arr, length) ? "true\n" : "false\n");//true
	//tar9
	triangle(9);

	return 0;
}*/
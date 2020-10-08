#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(void) {
	int a = 9, b = 5;
	printf("a=%d b=%d result=%d\n", a, b, a+ ++b);
	printf("a=%d b=%d result=%d\n", a, b, --a-b++);
	printf("a=%d b=%d result=%d\n", a, b, a+++b);
	printf("a=%d b=%d result=%d\n", a, b,-a +b++);
	
	printf("\tmuse\tHORS\navada\n");

	int x = 12, y = 9;
	printf("%d\n", y += x * y + 5 % 2);

	printf("\123\105\122\123");

	return 0;
}
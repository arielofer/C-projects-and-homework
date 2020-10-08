#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void negative() {
	int num, index = 1;
	printf("enter numbers to check, negative to stop\n");
	scanf("%d", &num);
	while (num >= 0) {
		index++;
		scanf("%d", &num);
	}

	printf("negative number: %d at place %d\n", num, index);
}


//int main() {
//	negative();
//
//	return 0;
//}
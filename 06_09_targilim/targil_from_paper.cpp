#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void seder_ole(int N) {
	int last, num, sum =0, min1, min2, min_diff, middle;
	scanf("%d", &last);
	scanf("%d", &num);
	sum += last + num;
	min_diff = num - last;// if min_diff is 
	min1 = last;
	min2 = num;
	middle = num;// in case n = 3

	for (int i = 3; i <= N; i++) {
		scanf("%d", &num);
		sum += num;
		if (num - last < min_diff) {
			min_diff = num - last;
			min2 = num;
			min1 = last;
		}
		if ((N + 1) / 2 == i)
			middle = num;

		last = num;
	}
	printf("avg: %d\n", sum / N);
	printf("smallest diff:%d, numbers are %d and %d\n", min_diff, min1, min2);
	printf("middle num: %d", middle);
}


//int main() {
//	int num;
//	printf("enter series number\n");
//	scanf("%d", &num);
//	seder_ole(num);
//}
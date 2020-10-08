#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void get_num(int N) {
	int pos_count = 0, neg_count = 0, temp, pos_sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp > 0) {
			pos_count++;
			pos_sum += temp;
		}
		if (temp < 0)
			neg_count++;
	}

	printf("pos = %d, neg=%d, avg of pos= %f", pos_count, neg_count, (float)(pos_sum / pos_count));
}

//int main(void) {
//	get_num(5);
//
//	return 0;
//}
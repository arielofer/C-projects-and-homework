#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void rezef_ole() {
	int rezef_max = 0, current_rezef = 1;
	int num, max;
	scanf("%d", &num);
	max = num;
	while (num > 0) {
		current_rezef = 1;
		scanf("%d", &num);
		while (num > max) {
			current_rezef++;
			max = num;
			scanf("%d", &num);
		}
		if (rezef_max < current_rezef)
			rezef_max = current_rezef;
		max = num;
	}

	printf("max rezef is %d", rezef_max);
}


void reuven_solve() {
	int last, num;
	scanf("%d", &last);
	int max = 0, mone = 1;
	while (1) {
		scanf("%d", &num);
		if (num <= 0)
			break;
		if (num > last)
			mone++;
		else
		{
			if (mone > max)
				max = mone;
			mone = 1;
		}
		last = num;
	}
	if (mone > max)
		max = mone;
}
int main() {
	rezef_ole();

	return 0;
}
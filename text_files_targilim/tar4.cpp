#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//writing a list of numbers to a text file and reading
//printing the avg
int no_i_am_your_main() {
	FILE* f;
	int num, sum = 0, counter = 0, rc;
	f = fopen("numbers.txt", "wt");
	int x = fprintf(f, "%d %d %d %d %d", 2, 10, 4, 5, 2);

	fclose(f);

	f = fopen("numbers.txt", "rt");
	rc = fscanf(f, "%d", &num);
	while (rc != EOF) {
		printf("the read numbers are %d rc=%d\n", num, rc);
		sum += num;
		counter++;
		rc = fscanf(f, "%d", &num);
	}

	printf("sum is: %d avg is: %f", sum, float(sum / num));
	_fcloseall();

	return 0;
}
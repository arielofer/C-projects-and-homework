#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void calc_family(int fam_num) {
	int boys, girls, sum_of_girls=0;
	for (int i = 0; i < fam_num; i++) {
		printf("enter number of boys and girls seperated by ,\n");
		scanf("%d", &boys);
		scanf("%d", &girls);
		sum_of_girls += girls;
		printf("the number of boys and girls is %s\n", (boys == girls) ? "equal" : "not equal");
		printf("number of children:%d\n", boys + girls);
	}
	printf("avg of girls is %f", (float)(sum_of_girls / fam_num));
}


//int main(void) {
//	calc_family(3);
//
//	return 0;
//}
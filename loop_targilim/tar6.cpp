#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void seker(int fam_amount) {
	int fam_members;
	int min_fam_members = 999, min_fam_members_index = 1, fam_members_sum = 0;
	int even_fam_members_counter = 0;

	for (int i = 1; i <= fam_amount; i++) {
		printf("enter the number of family members\n");
		scanf("%d", &fam_members);
		fam_members_sum += fam_members;
		if (min_fam_members >= fam_members) {
			min_fam_members = fam_members;
			min_fam_members_index = i;
		}
		if (fam_members % 2 == 0)
			even_fam_members_counter++;
	}
	printf("family with min number of memebers is %d, avg of members is %d\n",
		   min_fam_members_index, fam_members_sum / fam_amount);
	printf("amount of fam with even members is %d", even_fam_members_counter);
}


//int main() {
//	seker(5);
//
//	return 0;
//}
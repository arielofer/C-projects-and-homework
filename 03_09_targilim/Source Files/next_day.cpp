#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int next_day(int day, int month, int year) {
	
	if (1 <= month && month <= 12) {
		switch (month) {
		case 2:
			if (day > 28 || day < 1) {
				printf("invalid date, exiting");
				break;
			}
			if (day == 28) {
				day = 1;
				++month;
				break;
			}
			else {
				++day;
				break;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30 || day < 1) {
				printf("invalid date, exiting");
				break;
			}
			if (day == 30) {
				day = 1;
				++month;
				break;
			}
			else {
				++day;
				break;
			}
		case 12:
			if (day > 31 || day < 1) {
				printf("invalid date, exiting");
				break;
			}
			if (day == 31) {
				day = 1;
				month = 1;
				++year;
				break;
			}
			else {
				++day;
				break;
			}
		default:
			if (day > 31 || day < 1) {
				printf("invalid date, exiting");
				break;
			}
			if (day == 31) {
				day = 1;
				++month;
				break;
			}
			else {
				++day;
				break;
			}
		}
		printf("%d/%d/%d", day, month, year);
	}
	else
		printf("invalid date");

	return 0;
}


//int main(void) {
//	int day, month, year;
//	printf("enter a date divided by /\n");
//	scanf("%d/%d/%d", &day, &month, &year);
//	next_day(day, month, year);
//}
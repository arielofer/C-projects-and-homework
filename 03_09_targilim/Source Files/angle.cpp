#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void angle_type(int zavit) {
	if (0 < zavit && zavit <= 180) {
		switch (zavit) {
			case 180:
				printf("shtucha");
				break;
			case 90:
				printf("yeshara");
				break;
			default:
				printf("%s", zavit > 90 ? "keha" : "hada");
		}
	}
	else
		printf("meow");
}

//int main(void) {
//	int zavit;
//	scanf("%d", &zavit);
//	angle_type(zavit);
//
//	return 0;
//}
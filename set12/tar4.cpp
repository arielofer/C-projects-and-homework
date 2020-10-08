#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void triangle(char str[]){
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j <= i; j++)
			printf(" %c", str[j]);
		printf("\n");
	}
}


//int main() {
//	char str[6] = "gouba";
//	triangle(str);
//
//	return 0;
//}
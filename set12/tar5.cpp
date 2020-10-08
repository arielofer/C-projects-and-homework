#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void sivuv(char str[], int N) {
	char temp;
	char str_copy[6]; strcpy(str_copy, str);
	for (int i = 0; i < N; i++) {
		temp = str[strlen(str) - 1];
		for (int j = strlen(str) - 2; j >= 0; j--)
			str[j + 1] = str[j];
		str[0] = temp;
	}
	printf("%s\n", str);
	printf("%s", strcmp(str, str_copy) ? "not equel" : "equel");
}


//int main() {
//	char str[6] = "gouba";
//	sivuv(str, 5);
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void remove_astrix(char str[]) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '*') {
			for (int j = i; j < strlen(str); j++)
				str[j] = str[j+1];
			i--;
		}
	}
	printf("%s", str);
}


//int main() {
//	char str[] = "comp*u**te*rs";
//	remove_astrix(str);
//
//	return 0;
//}
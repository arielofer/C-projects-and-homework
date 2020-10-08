#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void reverse(char *str) {
	char temp;
	for (int i = 0; i <= (strlen(str)-1) / 2; i++) {
		temp = str[i];
		str[i] = str[strlen(str) - i -1];
		str[strlen(str) - i -1] = temp;
	}
}


//int main() {
//	char str[6];
//	size_t sz = 6;
//	fgets(str, sz, stdin);
//	reverse(str);
//	printf("%s", str);
//
//	return 0;
//}
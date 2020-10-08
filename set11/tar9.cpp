#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void func(char* s, char c) {
	char* ptr;
	ptr = s;
	while (*s) {
		if (*s != c) {
			*ptr = *s;
			ptr++;
		}
		s++;
	}
	*ptr = '\0';
	return;
}

int main() {
	char string[10] = "morning";
	func(string, 'n');
	printf("\n\n %s \n", string);
	getchar();
	return 0;
}
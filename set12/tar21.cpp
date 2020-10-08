#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_middle_letter(char* str) {
	int count, index = 0;
	char* ptr=str;
	while (*ptr) {
		count = 0;
		while (*ptr != '*' && *ptr) {
			count++;
			ptr++;
		}
		if (count % 2) printf(" %c\n", str[index + (count / 2)]);
		else printf(" %c, %c\n", str[index + (count / 2 - 1)], str[index + (count / 2)]);
		if (*ptr) {//check if not at the end of the string
			ptr++;
			index += count + 1;
		}
	}
}


int main() {
	char str[] = "DEFA*KBBG*X*ABC";
	print_middle_letter(str);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* change_str(char str[]) {
	char *ptr, *ch = str;
	char kodem = '.', temp;
	int length = 2;
	ptr = (char*)calloc(length, sizeof(char));
	while (*ch) {
		temp = *ch - '0';
		if (temp > 0 && temp < 10) {
			ptr = (char*)realloc(ptr, (length+temp-1) * sizeof(char));
			for (int i = length; i < length + temp-1; i++) {
				ptr[i - 2] = kodem;
			}
			length += temp - 1;
			ch++;
		}
		else {
			kodem = *ch;
			ptr[length - 2] = *ch++;
			ptr = (char*)realloc(ptr, length++*sizeof(char));
		}
	}
	ptr[length - 2] = '\0';
	return ptr;
}


//int main() {
//	char str[20] = "FFFCE3DEABB";
//	char* new_str = change_str(str);
//	printf("%s", new_str);
//
//	return 0;
//}
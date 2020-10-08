#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void recieve_words(char s[][6]) {
	for (int i = 0; i < 3; i++) {
		printf("%s.\n\n", s[i]);
	}
	printf("\n");
}


//int main() {
//	char str[][6] = {
//					"aaron",
//					"nerd",
//					"faggy",
//	
//	};
//	recieve_words(str);
//	return 0;
//}
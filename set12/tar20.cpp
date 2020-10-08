#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void shift(char* str, int j, int i) {
	char* Pstr = (char*)calloc(strlen(str)+1, sizeof(char));
	for (int k = i, index = 0; index<j; k++, index++) {//copy the sub-string
		Pstr[index] = str[k];
	}
	for(int q = 0; q < j; q++)
		for (int k = i; k <= strlen(str); k++) {//delete it
			str[k] = str[k+1];
		}

	strcat(Pstr, str);//place sub-string at the beggining
	printf("%s", Pstr);
	free(Pstr);
}


//int main() {
//	char str[] = "abcdefghijkl";
//	shift(str, 3, 5);
//
//	return 0;
//}
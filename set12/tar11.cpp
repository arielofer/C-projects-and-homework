#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace(char str1[], char str2[]) {
	char* index = strstr(str1, str2);
	char str3[] = "xyz";
	if (index) {
		if (strlen(str3) > strlen(str2)) {
			char* ptr = index + strlen(str1);
			for(int i = strlen(str1);i > 0 && ptr != index;i--, ptr--) {
				str1[i+1] = str1[i];
			}
		}
		else {
			char* ptr = index + (strlen(str2) - 1);
			for (; ptr[-1] != '\0'; ptr++) {
				ptr[-1] = *ptr;
			}
		}
		for (int i = 0; i < strlen(str3); i++)
			index[i] = str3[i];
	}
	printf("%s", str1);
}


//int main() {
//	char str1[12] = "adfffadads";
//	char str2[] = "adad";
//	replace(str1, str2);
//	
//	return 0;
//}
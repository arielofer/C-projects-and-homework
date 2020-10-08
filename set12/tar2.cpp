#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define len 6
void string_funcs(char* str) {
	printf("%s\n", str);
	char new_str[len * 2];
	strcpy(new_str, str);
	printf("%s\n", strcat(new_str, str));
	char new_str2[len * 2];
	strcpy(new_str2, str);
	printf("%s\n", strcat(new_str2, _strrev(str)));
	_strrev(str);
	char new_str3[len * 2];
	for (int i = 0, j = 0; i < len;i++) {
		new_str3[j++] = str[i];
		new_str3[j++] = str[i];
	}
	printf("%s\n", new_str3);
}


//int main() {
//	char str[6];
//	size_t sz = 6;
//	fgets(str, sz, stdin);
//	string_funcs(str);
//}
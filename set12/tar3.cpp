#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define M 6
#define N 6

void check_for_letters(char str1[], char str2[], char new_str[]) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (str1[i] == str2[j]) {
				new_str[k++] = str1[i];
			}
		}
	}
	if (k < N)
		new_str[k] = '\0';
}


//int main() {
//	char str[6] = "gouba";
//	char new_str[N];
//
//	/*size_t sz = 6;
//	fgets(str, sz, stdin);
//	*/char str2[6] = "fuoda";
//	//fgets(str2, sz, stdin);
//	check_for_letters(str, str2, new_str);
//	printf("%s", new_str);
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void check_appearence(char str1[], char str2[]) {
	int index = -1, count;
	for (int i = 0; str1[i]; i++) {
		if (str1[i++] == str2[0]) {
			count++;
				for (int j = 1; str2[j]; j++) {
					if (str1[i] == str2[j]) {
						count++;
						if (j < 2)
							i++;
					}
				}
			if (count == strlen(str2))
				index = i - 2;
			i--;
		}
		else
			count = 1;
	}
	printf("%d", index);
}


//int main() {
//	char str1[] = "adsfffadads";
//	char str2[] = "ads";
//	check_appearence(str1, str2);
//
//	return 0;
//}
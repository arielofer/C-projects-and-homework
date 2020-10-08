#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//creating a file and appending text to it
int so_not_main() {
	FILE* f = fopen("mylfile3.txt", "wt");
	int res;
	char str[20];

	if (ferror(f))// like !f or f==NULL
	{
		printf("failed too open file!\n");
		return 1;
	}

	//write to file
	fputs("hello world!\n", f);
	fclose(f);

	//append
	f = fopen("mylfile3.txt", "at");
	fputs("and good morning!\n", f);
	fclose(f);

	//print
	f = fopen("mylfile3.txt", "rt");
	fgets(str, 20, f);
	while (!feof(f))
	{
		printf("%s", str);
		fgets(str, 20, f);
	}
	fclose(f);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void write_to_file2()
{
	FILE* fp;
	fp = fopen("spaced_text.txt", "wt");
	char part[] = "this is   a sententce.\nthis  is another one.\nhow   about  that.";
	fputs(part, fp);
	fclose(fp);
}

int main()
{
	FILE* fp, * fixedPtr;
	int space_counter = 0;
	char prev, chr;

	write_to_file2();

	fp = fopen("spaced_text.txt", "rt");
	fixedPtr = fopen("fixed_text.txt", "wt");

	chr = fgetc(fp);
	if (chr != -1) fputc(chr, fixedPtr);
	prev = chr;
	chr = fgetc(fp);
	while (fp && chr != -1)
	{
		if (chr != -1)
		{
			if (prev == ' ' && chr == ' ');
			else	fputc(chr, fixedPtr);
		}
		prev = chr;
		chr = fgetc(fp);
	}

	_fcloseall();

	return 0;
}
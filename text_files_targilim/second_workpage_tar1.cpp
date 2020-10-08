#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void write_to_file()
{
	FILE* fp;
	fp = fopen("book_part.txt", "wt");
	char part[] = "this is a sententce. this is another one.how about that.";
	fputs(part, fp);
	fclose(fp);
}

int you_aint_my_real_main()
{
	FILE* fp;
	int counter=0, sen_counter = 0, max = 0;
	char prev, chr;

	write_to_file();

	fp = fopen("book_part.txt", "rt");
	chr = fgetc(fp);
	prev = chr;
	if(fp) chr = fgetc(fp);
	while(fp && chr != -1)
	{
		counter = 0;
		while (chr != '.')
		{
			if(prev != ' ' && chr == ' ') counter++;
			prev = chr;
			chr = fgetc(fp);
		}

		if (prev != '.' && chr == '.')
			counter++;

		sen_counter++;

		if (counter > max)
			max = counter;
		
		chr = fgetc(fp);
		if (chr == -1)
			break;
		prev = chr;
		chr = fgetc(fp);
	}

	//add last word or check if only one word in file
	if (prev != '.' && prev != ' ' && chr == -1)
	{
		counter++;
		if (!sen_counter)
			sen_counter = 1;
	}
	fclose(fp);

	if (counter > max)
		max = counter;

	printf("amount of sentences is: %d, max amount of words in a sentence is: %d",
		sen_counter, max);


	return 0;
}
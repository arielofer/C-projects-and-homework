#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 20

//reading and writing from a text file and going down a line
int the_main_man() {
	//data to test
	char str[] = "hi", sentence[] = "hello world!";
	char str2[SIZE] = "", sentence2[SIZE] = "xxx";
	int num1 = 6, num2 = 2;
	float f1 = 4.5, f2 = 2;
	FILE* f = fopen("testfile.txt", "wt");
	//check if open was successful
	//writing to file
	fputc('A', f);
	fputc('\n', f); //1
	fputs("\n", f); //2
	fputs(sentence, f);
	fprintf(f, "\n%d %f %s", num1, f1, str);
	fclose(f);

	printf("before reading frome file:\n num2=%d f2=%f str2=|%s| sentence=|%s|\n", num2, f2, str2, sentence2);
	//writing from file to vars
	f = fopen("testfile.txt", "rt");
	// check if open file succeeded
	int ch = fgetc(f);
	printf("ch= %c", ch);
	ch = fgetc(f); //1
	fgets(sentence2, SIZE, f); // 2 read and go down line
	fgets(sentence2, SIZE, f);
	fscanf(f, " %d %f %s", &num2, &f2, str2);
	printf("\nAfter reading from file: \nnum2=%d f2=%f str=<%s> sentence2=<%s>", num2, f2, str2, sentence2);

	fclose(f);

	return 0;
}
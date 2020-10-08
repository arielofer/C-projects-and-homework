#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//student type
typedef struct student {
	char name[20];
	int grade;
}student;

void i_am_not_main()
{
	student arr[3] = { {"yosi",85},{"moshe",90},{"yona",100} };
	student stu;
	for (int i = 0; i < 3; i++)
	{
		printf("%s  %d\n", arr[i].name, arr[i].grade);
	}

	FILE* fp;
	fp = fopen("filedat.dat", "wb");
	fwrite(arr, sizeof(student), 3, fp);
	fclose(fp);

	fp = fopen("filedat.dat", "r+b");
	fread(&stu, sizeof(student), 1, fp);
	int found = 0;
	while (!feof(fp) && !found) {
		if (!strcmp("moshe", stu.name)) {
			stu.grade = 95;
			fseek(fp, -long(sizeof(student)), SEEK_CUR);
			fwrite(&stu, sizeof(student), 1, fp);
			found = 1;
		}
		else fread(&stu, sizeof(student), 1, fp);
	}

	rewind(fp);
	fread(arr, sizeof(student), 3, fp);
	for (int i = 0; i < 3; i++)
	{
		printf("%s  %d\n", arr[i].name, arr[i].grade);
	}
}
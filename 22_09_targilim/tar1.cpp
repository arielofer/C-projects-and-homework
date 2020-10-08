#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//student type
typedef struct student {
	char name[20];
	int grade;
}student;

//read three students from file and print
int not_main() {
	int x;
	student arr[3] = { {"yosi", 85}, {"moshe", 90}, {"yona", 100} };

	student stu;

	//write to new empty file
	FILE* fp;
	fp = fopen("filedat.dat", "w+b");
	if (!fp) {//was the creation successful
		perror("no memory available!\n");
		return 0;
	}

	fwrite(arr, sizeof(student), 3, fp);//write to file all 3 students
	fclose(fp); // close the file

	// read from the file we created
	fp = fopen("filedat.dat", "r+b");
	student arr1[3];
	if (!fp) // was the creation successful
	{ 
		perror("couldn't find file!\n");
		return 1;
	}

	//print
	fread(arr1, sizeof(student), 3, fp);
	for (int i = 0; i < 3; i++)
		printf("%s %d", arr1[i].name, arr1[i].grade);
	fclose(fp);

	return 0;
}
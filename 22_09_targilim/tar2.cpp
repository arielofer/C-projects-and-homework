#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//student type
typedef struct student {
	char name[20];
	int grade;
}student;

//go through a file of students and update grades
int also_not_main() {
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
	if (!fp) // was the read successful
	{
		perror("couldn't find file!\n");
		return 1;
	}

	//create a new file to store and update grades
	FILE* temp = fopen("temp.dat", "wb");
	fread(&stu, sizeof(student), 1, fp);//read grades from file
	int b = 0;
	while (!feof(fp))
	{
		//update
		if (stu.grade > 80)
			stu.grade += 10;
		if (stu.grade > 100)
			stu.grade = 100;

		//copy to new file
		fwrite(&stu, sizeof(student), 1, temp);
		fread(&stu, sizeof(student), 1, fp);
	}

	fclose(fp);
	fclose(temp);

	//write back to original file
	fp = fopen("filedat.dat", "wb");
	temp = fopen("temp.dat", "rb");

	while (!feof(temp))
	{
		fread(&stu, sizeof(student), 1, temp);
		fwrite(&stu, sizeof(student), 1, fp);
	}

	fclose(fp);
	fclose(temp);

	//print
	student arr1[3];
	fp = fopen("filedat.dat", "r+b");
	fread(arr1, sizeof(student), 3, fp);
	for (int i = 0; i < 3; i++)
		printf("%s %d", arr1[i].name, arr1[i].grade);
	fclose(fp);

	return 0;
}
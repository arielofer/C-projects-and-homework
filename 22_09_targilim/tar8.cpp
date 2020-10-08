#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char fname[14];
	char lname[14];
	int grade;// kita
	int is_active;
}student;


int to_main_or_not_to_main() {
	int boger_count = 0;
	student stu;
	student talmidim[] = { {"yosi", "bush", 10, 1}, {"moshe", "cohen", 12, 1} };
	student mumadim[] = { {"yona", "reuven", 10, 1} };

	//load stud to file
	FILE* fptr = fopen("student.dat", "wb");
	fwrite(talmidim, sizeof(student), 2, fptr);
	fclose(fptr);
	
	//load muamadim to file
	fptr = fopen("mumadim.dat", "wb");
	fwrite(mumadim, sizeof(student), 1, fptr);
	fclose(fptr);

	//change seniors status and copy to different file
	//if not boger then increment grade
	fptr = fopen("student.dat", "r+b");
	FILE* bogr = fopen("bogrim.dat", "wb");
	fread(&stu, sizeof(student), 1, fptr);
	while (!feof(fptr)) {
		if (stu.grade == 12) {
			stu.is_active = 0;
			fseek(fptr, -(long)sizeof(student), SEEK_CUR);
			fwrite(&stu, sizeof(student), 1, fptr);
			fseek(fptr, 0, SEEK_CUR);
			fwrite(&stu, sizeof(student), 1, bogr);
			boger_count++;
		}
		else
		{
			stu.grade++;
			fseek(fptr, -(long)sizeof(student), SEEK_CUR);
			fwrite(&stu, sizeof(student), 1, fptr);
			fseek(fptr, 0, SEEK_CUR);
		}
		fread(&stu, sizeof(student), 1, fptr);
	}
	_fcloseall();

	//append mumadim to talmidim file
	fptr = fopen("student.dat", "ab");
	FILE* yudptr = fopen("mumadim.dat", "rb");
	
	fread(&stu, sizeof(student), 1, yudptr);
	while(!feof(yudptr))
	{
		fwrite(&stu, sizeof(student), 1, fptr);
		fread(&stu, sizeof(student), 1, yudptr);
	}
	_fcloseall();

	//load students back to array
	
	//print students
	fptr = fopen("student.dat", "rb");
	fread(&stu, sizeof(student), 1, fptr);
	while (!feof(fptr)) {
		printf("fname: %s, lname: %s, status:%d", stu.fname, stu.lname, stu.is_active);
		fread(&stu, sizeof(student), 1, fptr);
	}
	printf("\n");

	//load bogrim to array
	bogr = fopen("bogrim.dat", "rb");
	student *bogrim = (student*)malloc(boger_count * sizeof(student));
	fread(bogrim, sizeof(student), boger_count, bogr);
	fclose(bogr);

	//print bogrim array
	for (int i = 0; i < boger_count; i++)
		printf("fname: %s, lname: %s", bogrim[i].fname, bogrim[i].lname);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
typedef struct {
	unsigned grade;
	char name[LEN];
}student;

int comp_int(const void* e1, const void* e2) {
	if (*(int*)e1 < *(int*)e2)return -1;
	if (*(int*)e1 > *(int*)e2)return 1;
	return 0;
}

int comp_str(const void* e1, const void* e2) {
	return strcmp(*(char**)(e1), *(char**)(e2));
}


int comp_student(const void* e1, const void* e2) {
	if (((student*)e1)->grade < ((student*)e2)->grade)return -1;
	if (((student*)e1)->grade > ((student*)e2)->grade)return 1;
	return 0;
}


int main() {
	//for bsearch
	int num = 9, *p;
	char *s = "moshe" , ** w;
	student st = { 40, "sason" }, * find;
	//start
	int A[] = { 21,1 ,20 ,10 ,9 ,7 ,5 };
	const char* str[] = { "avi", "moshe", "david", "sason" };
	student stu[] = { {100, "avi"},{20,"moshe"},{98, "david"},{40,"sason"} };
	qsort(A, sizeof(A) / sizeof(A[0]), sizeof(int), comp_int);
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(char*), comp_str);
	qsort(stu, sizeof(stu) / sizeof(stu[0]), sizeof(student), comp_student);
	p = (int*)bsearch(&num, A, sizeof(A) / sizeof(A[0]), sizeof(int), comp_int);
	w = (char**)bsearch(&s, str, sizeof(str) / sizeof(str[0]), sizeof(char*), comp_str);
	find = (student*)bsearch(&st, stu, sizeof(stu) / sizeof(stu[0]), sizeof(student), comp_student);

	return 0;
}
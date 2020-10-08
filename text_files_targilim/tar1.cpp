#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	int age;
	long id;
}person;

//reading and writing structs from text file
int not_main()
{
	person parr[3];
	FILE* fin;

	fin = fopen("persons.txt", "wt");
	person temp[3] = { {"daniel", 18, 316359}, 
		{"niv", 15, 533892},
		{"shaked", 10, 586151} };
	
	//put into file
	for (int i = 0; i < 3; i++)
		fprintf(fin, "%s %d %ld\n", temp[i].name, temp[i].age, temp[i].id);
	fclose(fin);

	fin = fopen("persons.txt", "rt");
	if (!fin)
		printf("error open file!\n");
	else
	{
		//put to new array
		for (int i = 0; i < 3; i++)
			fscanf(fin, "%s %d %ld\n", parr[i].name, &parr[i].age, &parr[i].id);
		fclose(fin);

		//print
		for (int i = 0; i < 3; i++)
			printf("%-12s %3d %9ld\n", parr[i].name, parr[i].age, parr[i].id);
	}

	return 0;
}
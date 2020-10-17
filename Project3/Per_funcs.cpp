# define _CRT_SECURE_NO_WARNINGS
#include "Per_funcs.h"

//-----------------------------------------------------------------------------
//								Add To List
//								-----------
//
// General : The function gets the names array, the dates array, a pointer to the
//  dynamic Persons list and a pointer to the length of the array. the function
//  adds the next person in the old database to the new one and increments len.
//  the function also prints the detils of the newly added person.
//
// Parameters :
// names (In)
// dates (In)
// list	 (In & Out)
// len   (In & Out)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void AddToList(const char* names[], const int dates[][COLS], Person *list[], int *len)
{
	int i, found, max_serial;
	Person p;
	Date* t = (Date*)malloc(sizeof(Date));

	if (*list == NULL)
	{
		*list = (Person*)realloc(*list, sizeof(Person));
		strcpy(p.full_name, names[0]);
		p.serial_num = 1;
		t->day = dates[0][0], t->month = dates[0][1], t->year = dates[0][2];
		p.pDate = t;
	}
	else
	{
		max_serial = (*list)[0].serial_num;

		for (i = 0; i < MAX; i++)
		{
			found = 0;
			for (int j = 0; j < *len; j++)
			{
				if (max_serial < (*list)[j].serial_num)
					max_serial = (*list)[j].serial_num;

				if (!strcmp(names[i], (*list)[j].full_name))
				{
					found = 1;
					break;
				}
			}

			if (!found)
				break;
		}

		if (i == MAX)
		{
			printf("no persons left to transfer!\n");
			return;
		}
		else
		{
			*list = (Person*)realloc(*list, (*len + 1) * sizeof(Person));
			strcpy(p.full_name, names[i]);
			p.serial_num = max_serial + 1;
			t->day = dates[i][0], t->month = dates[i][1], t->year = dates[i][2];
			p.pDate = t;
		}
	}

	(*list)[*len] = p;
	(*len)++;
	printf("\n%d) %s\t%d.%d.%d\n\n", p.serial_num, p.full_name, t->day, t->month, t->year);
}

//-----------------------------------------------------------------------------
//								Print List
//								----------
//
// General : The function gets the dynamic Persons list and the length of the array.
//  the function prints all the Persons in the list.
//
// Parameters :
// list	 (In)
// len   (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void PrintList(Person list[], int len)
{
	if (list == NULL) printf("list is empty!\n");
	else
	{
		printf("current list:\n\n");
		for (int i = 0; i < len; i++)
			printf("%d) %s\t%d.%d.%d\n", list[i].serial_num, list[i].full_name,
				list[i].pDate->day, list[i].pDate->month, list[i].pDate->year);
	}
}

//-----------------------------------------------------------------------------
//								Date Compare
//								------------
//
// General : The function gets Persons from the list.
//  the function compares between their dates.
//
// Parameters :
// list	 (In)
// len   (In)
//
// Return Value :
//  1 if the first person is younger the second.
// -1 if the first person is older the second.
//  0 if the first person is as old as the second.
//
//-----------------------------------------------------------------------------
int DateComp(const void *a, const void *b)
{
	Person* d1 = (Person*)a, * d2 = (Person*)b;

	if (d1->pDate->year > d2->pDate->year) return 1;
	else if (d1->pDate->year < d2->pDate->year) return -1;
	else
	{
		if (d1->pDate->month > d2->pDate->month) return 1;
		else if (d1->pDate->month < d2->pDate->month) return -1;
		else
		{
			if (d1->pDate->day > d2->pDate->day) return 1;
			else if (d1->pDate->day < d2->pDate->day) return -1;
			else return 0;
		}
	}
}

//-----------------------------------------------------------------------------
//							Sort List By Date
//							-----------------
//
// General : The function gets the dynamic Persons list and the length of the array.
//  the function sorts the persons from oldest to youngest and prints the list.
//
// Parameters :
// list	 (In & Out)
// len   (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void SortListByDate(Person *list[], int len)
{
	qsort(*list, len, sizeof(Person), DateComp);
	PrintList(*list, len);
}

//-----------------------------------------------------------------------------
//							Write List To File
//							------------------
//
// General : The function gets the dynamic Persons list, the length of the array,
//  and a file name. the function writes the Persons list to the file.
//
// Parameters :
// list		 (In)
// len		 (In)
// file_name (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void WriteListToFile(Person list[], int len, const char* file_name)
{
	FILE* fp = fopen(file_name, "wt");
	if (fp == NULL)
	{
		printf("file not found!\n");
		return;
	}
	else
	{
		fwrite(list, sizeof(Person), len, fp);
		printf("\nfile saved\n\n");
		fclose(fp);
	}
}

//-----------------------------------------------------------------------------
//							Load File To list
//							-----------------
//
// General : The function gets the dynamic Persons list, the length of the array,
//  and a file name. the function reads Persons from the file and writes
//  to the Persons list.
//
// Parameters :
// list		 (In)
// len		 (In)
// file_name (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void LoadToListFromFile(Person *list[], int *len, const char* file_name)
{
	FILE* fp = fopen(file_name, "rt");
	Person p;
	if (fp == NULL)
	{
		printf("file not found!\n");
		return;
	}
	else
	{
		if (feof(fp))
		{
			printf("file is empty! not attempting a load\n");
			return;
		}

		*len = 0;
		fread(&p, sizeof(Person), 1, fp);
		while (!feof(fp))
		{
			*list = (Person*)realloc(*list,(*len + 1) * sizeof(Person));
			(*list)[*len] = p;
			(*len)++;
			fread(&p, sizeof(Person), 1, fp);
		}
		printf("\nfile loaded\n\n");
		fclose(fp);
	}
}

//-----------------------------------------------------------------------------
//								Print Menu
//								----------
//
// General : The function prints all the commands for the user and what they do.
//
// Parameters : None.
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void MenuPrint()
{
	printf("Press 1 to add a new person to the list\n\n");
	printf("Press 2 to print all persons on the list\n\n");
	printf("Press 3 to sort all persons by age, then print\n\n");
	printf("Press 4 to save current list to file\n\n");
	printf("Press 5 to read the file into the list\n\n");
	printf("Press E to exit the program\n\n\n");
	printf("===> ");
}
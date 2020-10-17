# define _CRT_SECURE_NO_WARNINGS
# define MAX 7 //number of rows
# define COLS 3
# define LEN 30 // max length of full name

// includes
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// typedefs
typedef struct DateType
{
	int day;
	int month;
	int year;
}Date; // date of birth

typedef struct PersonType
{
	int serial_num;
	char full_name[LEN];
	Date* pDate; //pointer to a date of birth in the list
}Person;

//protos
void AddToList(const char* names[], const int dates[][COLS], Person *list[], int *len);
void PrintList(Person list[], int len);
int DateComp(const void* a, const void* b);
void SortListByDate(Person *list[], int len);
void WriteListToFile(Person list[], int len, const char* file_name);
void LoadToListFromFile(Person *list[], int *len, const char* file_name);
void MenuPrint();
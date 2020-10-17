# define _CRT_SECURE_NO_WARNINGS
#include "Per_funcs.h"

//-----------------------------------------------------------------------------
// Project 3
// ---------
//
// General : The program transfers all the persons from the old database
//   to the new one, sorts by date and writes and loads from a file
//
// Input : command character.
//
// Process : according to entered command.
//
// Output : Prints newly entered Person/all the Person list/ writing or loading was
//   successful(according to entered command).
//
//-----------------------------------------------------------------------------
// Programmer : Ariel Ofer
// Date : 17.10.2020
//-----------------------------------------------------------------------------
int main()
{
	//array of names
	const char* names[MAX] = { "Sasson_Sassoni", "Pooh", "Jamees Bond",
	"Elvis_is_alive!", "Shilgiya", "Cleopatra", "sisso_Vesimmhoo" };

	//matrix of dates of birth
	const int dates[MAX][COLS] =
	{
		{10, 1, 1988},
		{12, 12, 1948},
		{4, 12, 1970},
		{11, 11, 1890},
		{11, 11, 1948},
		{1, 10, 1213},
		{12, 11, 1948}
	};

	// file name
	const char* f_name = "Persons.txt";
	char cmd;

	//new list
	Person* list = NULL;
	int len = 0;
	
	// menu
	int ok = 1;

	//main menu
	while (ok)
	{
		MenuPrint();
		scanf(" %c", &cmd);

		switch (cmd)
		{
		case '1':
			AddToList(names, dates, &list, &len);
			break;
		case '2':
			PrintList(list, len);
			break;
		case '3':
			SortListByDate(&list, len);
			break;
		case '4':
			WriteListToFile(list, len, f_name);
			break;
		case '5':
			LoadToListFromFile(&list, &len, f_name);
			break;
		case 'e':
		case 'E':
			printf("exiting...\n");
			for(int i = 0; i < len; i++)
				free(list[i].pDate);
			free(list);
			ok = 0;
			break;
		default:
			printf("unknown command, please try again");
		}
	}

	return 0;
}
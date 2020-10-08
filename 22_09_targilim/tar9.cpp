#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prisoner {
	long id;
	char lname[20];
	char fname[20];
	int punishment; // in months
	int served_time; // in months
	int behavior; // from 1-4 (4 is worst)
}prisoner;

void printP(prisoner p)
{
	printf("id: %ld, name: %s %s\n", p.id, p.fname, p.lname);
	printf("-------------------------\n");
}

int should_i_main_or_should_i_go()
{
	FILE* prisonPtr;
	prisoner arr[] = { {325047, "trump", "donald", 9, 3, 1},
					   {321907, "obama", "mickey", 4, 3, 1},
					   {313564, "gantz", "goofy", 5, 2, 3}
	}, temp;

	// write arr to file
	prisonPtr = fopen("asirim.dat", "wb");
	fwrite(arr, sizeof(prisoner), sizeof(arr) / sizeof(arr[0]), prisonPtr);
	fclose(prisonPtr);

	// seif alef
	prisonPtr = fopen("asirim.dat", "r+b");
	fread(&temp, sizeof(prisoner), 1, prisonPtr);
	while (!feof(prisonPtr)) // if behavior code = 1 reduce punishment by 3 months
	{
		if (temp.behavior == 1)
		{
			temp.punishment -= 3;
			if (temp.punishment < 0)
				temp.punishment = 0;
			fseek(prisonPtr, -long(sizeof(prisoner)), SEEK_CUR);
			fwrite(&temp, sizeof(prisoner), 1, prisonPtr);
			fseek(prisonPtr, 0, SEEK_CUR);
		}

		fread(&temp, sizeof(prisoner), 1, prisonPtr);
	}

	fclose(prisonPtr);
	prisonPtr = fopen("asirim.dat", "rb");

	//seif bet
	fread(&temp, sizeof(prisoner), 1, prisonPtr);
	printf("prisoners to free:\n\n");
	while (!feof(prisonPtr)) // if behavior code = 1, check if did their time
	{
		if (temp.behavior == 1)
		{
			if (temp.punishment <= temp.served_time)
				printP(temp);
		}

		fread(&temp, sizeof(prisoner), 1, prisonPtr);
	}

	fclose(prisonPtr);

	return 0;
}
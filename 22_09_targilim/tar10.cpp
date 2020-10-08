#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int day;
	int month;
	int year;
}Date;

typedef struct event {
	Date date;
	int day_in_week;// 1-7
	int amount_of_guests;// 50-900
}event;

int main()
{
	FILE* fptr;
	event arr[] = { {{03,06,2002}, 1, 600},
					{{05,05,2005}, 4, 500},
					{{18,05,1971}, 1, 900}
				  }, temp;
	Date max; int max_day, max_guests, max_events;
	int days[8] = {0};// 1-7

	//load to file
	fptr = fopen("happy.dat", "wb");
	fwrite(arr, sizeof(event), sizeof(arr) / sizeof(arr[0]), fptr);
	fclose(fptr);

	//seif alef - print the date of event with biggest amount of guests
	//seif bet - print the day with biggest amount of guests
	fptr = fopen("happy.dat", "r+b");
	fread(&temp, sizeof(event), 1, fptr);
	max = temp.date; max_guests = temp.amount_of_guests;
	days[temp.day_in_week]++;
	fread(&temp, sizeof(event), 1, fptr);
	while (!feof(fptr)) {

		// seif alef
		if (max_guests < temp.amount_of_guests)
		{
			max_guests = temp.amount_of_guests;
			max = temp.date;
		}

		// seif bet
		days[temp.day_in_week]++;
		fread(&temp, sizeof(event), 1, fptr);
	}

	fclose(fptr);

	// seif alef
	printf("biggest event is on %d/%d/%d, amount of guests is %d\n", max.day, max.month,
		   max.year, max_guests);
	
	// seif bet
	max_day = 1, max_events = days[1];
	for (int i = 2; i <= 7; i++)
	{
		if (days[i] > max_events)
		{
			max_events = days[i];
			max_day = i;
		}
	}

	printf("day with biggest amount of events is %d, amount of events is: %d", max_day, max_events);

	return 0;
}
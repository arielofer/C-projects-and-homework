#define _CRT_SECURE_NO_WARNINGS
#include "Headers2.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

Date fill_date() {
	int day, month, year;
	scanf("%d %d %d", &day, &month, &year);
	return Date{ day, month, year };
}


void fill_cd(CD* cd) {
	char name[20], singer_name[20];
	float length;
	int players;
	for (int i = 0; i < 2; i++) {
		_flushall();
		printf("enter song name:\n");
		fgets(name, 20, stdin);
		strcpy(cd->tracklist[i].song_name, name);
		_flushall();
		printf("enter singer name:\n");
		fgets(singer_name, 20, stdin);
		strcpy(cd->tracklist[i].singer_name, singer_name);
		_flushall();
		printf("enter song length:\n");
		scanf("%f", &length);
		cd->tracklist[i].length = length;
		printf("enter date:\n");
		cd->tracklist[i].date = fill_date();
		printf("enter number of players:\n");
		scanf("%d", &players);
		cd->tracklist[i].num_players = players;
	}
}


void print_cd(CD cd) {
	for (int i = 0; i < 2; i++) {
		printf("song %d:\n", i+1);
		printf("name: %s\n", cd.tracklist[i].song_name);
		printf("singer name: %s\n", cd.tracklist[i].singer_name);
		printf("length: %.2f\n", cd.tracklist[i].length);
		printf("date: %d/%d/%d\n", cd.tracklist[i].date.day, cd.tracklist[i].date.month, cd.tracklist[i].date.year);
		printf("number of players: %d\n", cd.tracklist[i].num_players);
	}
}

int length_of_cd(Song tracklist[]) {
	float sum_length = 0;
	for (int i = 0; i < 2; i++)
		sum_length += tracklist[i].length;

	return sum_length;
}

int is_length_less_then_4(Song tracklist[]) {
	int ok = 1;
	for (int i = 0; i < 2 && ok; i++)
		if (tracklist[i].length >= 4)
			ok = 0;
	return ok;
}

void print_shortest_song(CD cd) {
	float min = 1000; int index= 0;
	for (int i = 0; i < 2; i++) {
		if (cd.tracklist[i].length < min) {
			min = cd.tracklist[i].length;
			index = i;
		}
	}
	printf("song name is: %s and singer name is: %s", cd.tracklist[index].song_name, cd.tracklist[index].singer_name);
}

void amount_of_songs_per_amount_of_players(CD cd_arr[], int players[]) {
	for(int j = 0; j<2; j++)
	for (int i = 0; i < 10; i++) {
		players[cd_arr[j].tracklist[i].num_players]++;
	}
}

int songs_before_date(CD cd, Date date) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		switch (cd.tracklist[i].date.year<date.year)
		{
		case 1:
			count++;
			break;
		case 0:
			if(cd.tracklist[i].date.year == date.year)
				switch (cd.tracklist[i].date.month < date.month)
				{
				case 1:
					count++;
					break;
				case 0:
					if(cd.tracklist[i].date.month == date.month)
						switch (cd.tracklist[i].date.year < date.day)
						{
						case 1:
							count++;
							break;
						}
					break;
				default:
					break;
				}
		}
	}
	return count;
}



#pragma once
#include "headers2.h"

typedef struct {
	char song_name[20];
	char singer_name[20];
	float length;
	Date date;
	int num_players;
}Song;
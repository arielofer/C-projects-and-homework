#pragma once
#include "Headers2.h"

void fill_cd(CD* cd);
void print_cd(CD cd);
int length_of_cd(Song tracklist[]);
int is_length_less_then_4(Song tracklist[]);
void print_shortest_song(CD cd);
void amount_of_songs_per_amount_of_players(CD cd, int players[]);
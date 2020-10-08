#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"

typedef struct Team 
{
	char *teamName;
	int num_of_players;
	struct player **plarray; // dynamic array of the team's 
							 // players. each node is a pointer to
							 // a player who plays for the team.
	
	struct Team* next; // a reference to the next node
}teamRec, *teamPtr;
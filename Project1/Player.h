#pragma once

#include "Team.h"

typedef struct player // football player type
{
	char *playerID;
	int age;
	char *firstName;
	char *lastName;

}playerRec ,*playerPtr;

typedef struct playerNode {
	playerRec PL;
	struct Team* tmptr; // a pointer to a node in a linked list
						// representing the team the player plays for.
	
	struct playerNode* next; // a reference to the next node
}playerNode, *playerNodePtr;
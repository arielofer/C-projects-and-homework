#pragma once

//                  --the main struct--
#include "Player.h"
#include "Team.h"

typedef struct headType {
	struct Team* teamlist; // points to the head of a linked
						   // list of teams

	struct playerNode* playerList; // points to the head of a linked
								   // list of players
}headder, *headPtr;
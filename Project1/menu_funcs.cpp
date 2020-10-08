#define _CRT_SECURE_NO_WARNINGS
// also adds all structs
#include "menu_funcs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 50

//global head instant
extern headder head;

//file names
const char* PFILENAME = "players.dat";
const char* TFILENAME = "teams.dat";

//-----------------------------------------------------------------------------
//								Get String
//								----------
//
// General : The function gets input from user, builds a dynamic 
//	string and return it
//
// Parameters :
//
// Return Value : a pointer to a dynamic string.
//
//-----------------------------------------------------------------------------
char* GetString()
{
	char chr;
	int len = 1;
	char* str = NULL;
	str = (char*)realloc(str, sizeof(char) * (len + 1));
	chr = getchar();
	str[len - 1] = chr;
	while (chr != '\n')
	{
		chr = getchar();
		++len;
		str = (char*)realloc(str, sizeof(char) * (len + 1));
		str[len - 1] = chr;
		if (len == MAX_STRING_LENGTH) break;
	}
	str[len - 1] = '\0';
	return str;
}

//-----------------------------------------------------------------------------
//							Build Players file
//							------------------
//
// General : The function gets input from user, builds a player instance 
//	and writes to the players file N times
//
// Parameters :
// N (In)
//
// Return Value :
//
//-----------------------------------------------------------------------------
void BuildPlayersFile(int N)
{
	FILE* fp = fopen(PFILENAME, "wb");
	char *ID, *Fname, *Lname;
	int age;
	playerRec player;
	getchar();
	for (int i = 0; i < N; i++)
	{
		printf("~ enter id: ");
		player.playerID = GetString();
		printf("~ enter first name: ");
		player.firstName = GetString();
		printf("~ enter last name: ");
		player.lastName = GetString();
		printf("~ enter age: ");
		scanf("%d", &player.age);

		fwrite(&player, sizeof(playerRec), 1, fp);
		fseek(fp, 0, SEEK_CUR);
	}
}

//-----------------------------------------------------------------------------
//							Build Teams file
//							----------------
//
// General : The function gets input from user, builds a team instance 
//	and writes to the players file N times
//
// Parameters :
// N (In)
//
// Return Value :
//
//-----------------------------------------------------------------------------
void BuildTeamsFile(int N)
{
	FILE* fp = fopen(TFILENAME, "wb");
	char* Tname;
	teamRec team;
	getchar();
	for (int i = 0; i < N; i++)
	{
		printf("~ enter team name: ");
		team.teamName = GetString();
		team.num_of_players = 0;
		team.plarray = NULL;

		fwrite(&team, sizeof(teamRec), 1, fp);
		fseek(fp, 0, SEEK_CUR);
	}
}

//-----------------------------------------------------------------------------
//							Build Head instance
//							-------------------
//
// General : The function reads data from the players and teams files,
//  and enters it to the head instance. 
//
// Parameters :
//
// Return Value :
//
//-----------------------------------------------------------------------------
void HeadBuild()
{
	statusType status;
	FILE* fp;
	playerRec player;
	teamRec team;

	fp = fopen(PFILENAME, "rb");
	
	fread(&player, sizeof(playerRec), 1, fp);
	fseek(fp, 0, SEEK_CUR);
	while (!feof(fp)) {
		status = insertPlayer(player.playerID, player.lastName, player.firstName, player.age);
		if (status == DUPLICATE_RECORD) break;
		fread(&player, sizeof(playerRec), 1, fp);
		fseek(fp, 0, SEEK_CUR);
	}
	
	fclose(fp);

	fp = fopen(TFILENAME, "rb");

	fread(&team, sizeof(teamRec), 1, fp);
	fseek(fp, 0, SEEK_CUR);
	while (!feof(fp)) {
		status = insertTeam(team.teamName);
		if (status == DUPLICATE_RECORD) break;
		fread(&team, sizeof(teamRec), 1, fp);
		fseek(fp, 0, SEEK_CUR);
	}

	fclose(fp);
}

//-----------------------------------------------------------------------------
//								Find Player
//								-------------
//
// General : The function looks for the player with the given ID 
//	in the players linked list
//
// Parameters :
// playerID (In)
//
// Return Value : a pointer to the player node in the linked list or
//				  NULL if not found
//
//-----------------------------------------------------------------------------
playerNodePtr findPlayer(char *playerID)
{
	playerNodePtr p = head.playerList;
	while (p)
	{
		if (!strcmp(p->PL.playerID, playerID))
			return p;
		p = p->next;
	}

	return NULL;
}

//-----------------------------------------------------------------------------
//								Insert Player
//								-------------
//
// General : The function adds a new player to the start
//	of the Players linked list 
//
// Parameters :
// playerID (In)
// lastName (In)
// firstName (In)
// age (In)
//
// Return Value : SUCCESS if the operation was successful or
// DUPLICATE_RECORD if the player already exists in the system
//
//-----------------------------------------------------------------------------
statusType insertPlayer(char *playerID, char* lastName, char* firstName,
	int age)
{
	statusType status = SUCCESS;
	playerNodePtr p, q = findPlayer(playerID);
	if (q) 
	{
		status = DUPLICATE_RECORD;
		return status;
	}

	// new player
	p = (playerNodePtr)malloc(sizeof(playerNode));
	p->PL.playerID = _strdup(playerID);
	p->PL.lastName = _strdup(lastName);
	p->PL.firstName = _strdup(firstName);
	p->PL.age = age;
	p->tmptr = NULL; // teamless player
	p->next = head.playerList;
	head.playerList = p;
	return status;
}

//-----------------------------------------------------------------------------
//							Delete Player from team
//							-----------------------
//
// General : The function deletes a the pointer to this player
// from the team he played for.
//
// Parameters :
// playerID (In)
//
// Return Value : SUCCESS if the operation was successful or
// MISSING_RECORD if the player does not exists in the system
// or the player doesn't belong to any team
//-----------------------------------------------------------------------------
statusType deletePlayerFromTeam(char* playerID) 
{
	playerNodePtr p = findPlayer(playerID);
	teamPtr t;
	int i, k = 0;
	statusType status = SUCCESS;

	if (!p || !p->tmptr) status = MISSING_RECORD;
	else
	{
		t = p->tmptr;
		p->tmptr = NULL; // remove pointer to team

		//find the player index in the team's player array
		for (i = 0; i < t->num_of_players; i++) 
		{
			if(t->plarray[i]->playerID == playerID)
			{
				k = i;
				break;
			}
		}

		//remove player from array
		for (i = k + 1; i < t->num_of_players; i++)
			t->plarray[i - 1] = t->plarray[i];

		t->num_of_players--;
		t->plarray = (playerPtr*)realloc(t->plarray,
			t->num_of_players * sizeof(playerPtr));
	}

	return status;
}

//-----------------------------------------------------------------------------
//								Delete Player
//								-------------
//
// General : The function deletes a player with the given ID
// from the Player linked list and the pointer to this player from
// the team he played for if he does.
//
// Parameters :
// playerID (In)
//
// Return Value : SUCCESS if the operation was successful or
// MISSING_RECORD if the player doesn't exists in the system
//
//-----------------------------------------------------------------------------
statusType deletePlayer(char* playerID)
{
	playerNodePtr p = findPlayer(playerID), q = head.playerList;
	statusType status = SUCCESS;
	if (!p) status = MISSING_RECORD;
	else
	{
		if (p->tmptr) status = deletePlayerFromTeam(playerID);
		
		//if the player is at the head of the list
		if (head.playerList == p)
		{
			head.playerList = q->next;
			free(p->PL.playerID); free(p->PL.firstName); free(p->PL.lastName);
			free(p);
		}
		else
		{
			//look for the player until one node before the end
			while (q->next)
			{
				if (q->next == p) 
				{
					q->next = p->next;
					free(p->PL.playerID); free(p->PL.firstName); free(p->PL.lastName);
					free(p);
					break;
				}
				q = q->next;
			}
		}
	}

	return status;
}

//-----------------------------------------------------------------------------
//									Find Team
//									---------
//
// General : The function looks for the team with the given name 
//	in the teams linked list
//
// Parameters :
// name (In)
//
// Return Value : a pointer to the team node in the linked list or
//				  NULL if not found
//
//-----------------------------------------------------------------------------
teamPtr findTeam(char* name)
{
	teamPtr t = head.teamlist;
	while (t)
	{
		if (!strcmp(t->teamName, name))
			return t;
		t = t->next;
	}

	return NULL;
}

//-----------------------------------------------------------------------------
//								Insert Team
//								-----------
//
// General : The function adds a new team to the start
//	of the Teams linked list 
//
// Parameters :
// name (In)
//
// Return Value : SUCCESS if the operation was successful or
// DUPLICATE_RECORD if the team already exists in the system
//
//-----------------------------------------------------------------------------
statusType insertTeam(char* name)
{
	statusType status = SUCCESS;
	teamPtr t, k = findTeam(name);
	if (k)
	{
		status = DUPLICATE_RECORD;
		return status;
	}

	// new team
	t = (teamPtr)malloc(sizeof(Team));
	t->teamName = _strdup(name);
	t->num_of_players = 0;
	t->plarray = NULL; // no players in the new team
	t->next = head.teamlist;
	head.teamlist = t;
	return status;
}

//-----------------------------------------------------------------------------
//								Delete Team
//								-----------
//
// General : The function deletes a team with the given name
// from the Team linked list and the pointers to this team from
// all the players that played for this team.
//
// Parameters :
// name (In)
//
// Return Value : SUCCESS if the operation was successful or
// MISSING_RECORD if the team doesn't exists in the system
//
//-----------------------------------------------------------------------------
statusType deleteTeam(char* name)
{
	int i;
	teamPtr t = findTeam(name), k = head.teamlist;
	statusType status = SUCCESS;
	if (!t) status = MISSING_RECORD;
	else
	{
		if (t->plarray)
		{
			for (i = 0; i < t->num_of_players; i++)
				deletePlayerFromTeam(t->plarray[i]->playerID);
		}

		//if the player is at the head of the list
		if (head.teamlist == t)
			head.teamlist = t->next;
		else
		{
			//look for the team in the linked list
			while (k->next != t)
			{
				k = k->next;
			}

			k->next = t->next;
		}

		free(t->teamName); free(t->plarray);
		free(t);
	}

	return status;
}

//-----------------------------------------------------------------------------
//							Join player to Team
//							-------------------
//
// General : The function adds the player with the given ID
// (if he doesnt play for a team) to the team with the given name.
//
// Parameters :
// playerID (In)
// team_name (In)
//
// Return Value : SUCCESS if the operation was successful or
// MISSING_RECORD if the team or player doesn't exists in the system
// or the player already plays for a team
//
//-----------------------------------------------------------------------------
statusType joinPlayerToTeam(char* playerID, char* team_name) 
{
	statusType status = SUCCESS;
	playerNodePtr p = findPlayer(playerID);
	teamPtr t = findTeam(team_name);

	if (!p || !t) status = MISSING_RECORD;
	else 
	{
		if (p->tmptr) status = MISSING_RECORD;
		else
		{
			p->tmptr = t;
			if (!t->num_of_players) // team has no players
			{
				t->plarray = (playerPtr*)realloc(t->plarray, sizeof(playerPtr));
				t->plarray[0] = &(p->PL);
				t->num_of_players = 1;
			}
			else
			{
				t->plarray = (playerPtr*)realloc
							(t->plarray, (t->num_of_players + 1) * sizeof(playerPtr));
				t->plarray[t->num_of_players] = &(p->PL);
				t->num_of_players++;
			}
		}
	}
	return status;
}

//-----------------------------------------------------------------------------
//								print players
//							    -------------
//
// General : The function prints all the players according
// to the order they appear in the linked list.
//
// Parameters :
// None
//
// Return Value :
// None
//
//-----------------------------------------------------------------------------
void printPlayers(void)
{
	playerNodePtr p = head.playerList;
	if (!p) printf("[-] No players");
	else
	{
		int i = 1;
		while (p)
		{
			printf("[%d] first name: %s, last name: %s, id: %s, age: %d\n", i++,
				p->PL.firstName, p->PL.lastName, p->PL.playerID, p->PL.age);
			p = p->next;
		}
	}
}

//-----------------------------------------------------------------------------
//								print teams
//							    -----------
//
// General : The function prints all the teams according
// to the order they appear in the linked list.
//
// Parameters :
// None
//
// Return Value :
// None
//
//-----------------------------------------------------------------------------
void printTeams(void)
{
	teamPtr t = head.teamlist;
	if (!t) printf("[-] No teams");
	else
	{
		int i = 1;
		while (t)
		{
			printf("[%d] team name: %s\n", i++, t->teamName);
			t = t->next;
		}
	}
}

//-----------------------------------------------------------------------------
//							print team details
//							------------------
//
// General : The function prints all the details of the
// team with the given name if it exists. if the team has no
// players the function will print 0
//
// Parameters :
// name (In)
//
// Return Value :
// SUCCESS if the team exists in the system else MISSING_RECORD
//
//-----------------------------------------------------------------------------
statusType printTeamDetails(char* name)
{
	playerNodePtr p;
	teamPtr t = findTeam(name);
	statusType status = SUCCESS;
	if (!t) status = MISSING_RECORD;
	else
	{
		printf("-- players in %s --\n\n", name);
		if (!t->plarray) printf("0");
		else
		{
			for (int i = 0; i < t->num_of_players; i++)
			{
				p = findPlayer(t->plarray[i]->playerID);
				printf("[%d] first name: %s, last name: %s, id: %s, age: %d\n",
					i+1, p->PL.firstName, p->PL.lastName, p->PL.playerID, p->PL.age);
			}
		}
	}

	return status;
}

//-----------------------------------------------------------------------------
//							sort and print team details
//							---------------------------
//
// General : The function sorts the players array of the
// team with the given name if it exists and has players it prints 
// the players details.
//
// Parameters :
// name (In)
//
// Return Value :
// SUCCESS if the team exists in the system else MISSING_RECORD
//
//-----------------------------------------------------------------------------
statusType sortAndPrintTeamDetails(char* name)
{
	playerNodePtr p, q;
	playerPtr temp;
	teamPtr t = findTeam(name);
	statusType status = SUCCESS;
	if (!t || !t->plarray) status = MISSING_RECORD;
	else
	{
		int ok = 1, k =0;
		while (ok) {
			ok = 0;
			for (int i = 0; i < t->num_of_players - 1 - k; i++) {
				p = findPlayer(t->plarray[i]->playerID);
				q = findPlayer(t->plarray[i + 1]->playerID);
				if (strcmp(p->PL.lastName, q->PL.lastName) == 1) {
					temp = t->plarray[i];
					t->plarray[i] = t->plarray[i + 1];
					t->plarray[i + 1] = temp;
					ok = 1;
				}
			}
			k++;
		}

		printTeamDetails(name);
	}

	return status;
}

//-----------------------------------------------------------------------------
//								Player Node Count
//								-----------------
//
// General : The function gets a linked list of players and counts how
//  many nodes it has
//
// Parameters :
// list (In)
//
// Return Value : the amount of nodes in the linked list
//
//-----------------------------------------------------------------------------
int PlayerNodeCount(playerNodePtr list)
{
	int counter = 0;
	while (list)
	{
		list = list->next;
		++counter;
	}

	return counter;
}

//-----------------------------------------------------------------------------
//								team Node Count
//								---------------
//
// General : The function gets a linked list of teams and counts how
//  many nodes it has
//
// Parameters :
// list (In)
//
// Return Value : the amount of nodes in the linked list
//
//-----------------------------------------------------------------------------
int TeamsNodeCount(teamPtr list)
{
	int counter = 0;
	while (list)
	{
		list = list->next;
		++counter;
	}

	return counter;
}

//-----------------------------------------------------------------------------
//								sort team list by name
//								----------------------
//
// General : The function sorts the teams linked list 
//  by name in an ascending order.
//
// Parameters :
//
// Return Value :
// SUCCESS if the team linked list isnt empty else MISSING_RECORD
//
//-----------------------------------------------------------------------------
statusType SortTeamsByName()
{
	statusType status = SUCCESS;
	teamPtr t = head.teamlist, s, temp ,prev;
	if (!t) status = MISSING_RECORD;
	else
	{
		int len = TeamsNodeCount(head.teamlist);
		if (len > 1)
		{
			int ok = 1, k = 0;
			while (ok) {
				t = head.teamlist, prev = t, s = t->next;
				ok = 0;
				for (int i = 0; i < len - 1 - k; i++) {
					if (strcmp(t->teamName, s->teamName) == 1) {
						if (t == head.teamlist)
						{
							t->next = s->next;
							s->next = t;
							head.teamlist = s;
							prev = s;
						}
						else 
						{
							prev->next = s;
							t->next = s->next;
							s->next = t;
							prev = s;
						}
						temp = t;
						t = s;
						s = temp;
						ok = 1;
					}
					t= t->next;
					if (prev->next != t) prev = prev->next;
					s = s->next;
				}
				k++;
			}
		}
	}

	return status;
}

//-----------------------------------------------------------------------------
//								sort team list by size
//								----------------------
//
// General : The function sorts the teams linked list 
//  by the number of players in an ascending order.
//
// Parameters :
//
// Return Value :
// SUCCESS if the team linked list isnt empty else MISSING_RECORD
//
//-----------------------------------------------------------------------------
statusType SortTeamsBySize()
{
	statusType status = SUCCESS;
	teamPtr t = head.teamlist, s, temp, prev;
	if (!t) status = MISSING_RECORD;
	else
	{
		int len = TeamsNodeCount(head.teamlist);
		if (len > 1)
		{
			int ok = 1, k = 0;
			while (ok) {
				t = head.teamlist, prev = t, s = t->next;
				ok = 0;
				for (int i = 0; i < len - 1 - k; i++) {
					if (t->num_of_players > s->num_of_players) {
						
						// if t is at head
						if (t == head.teamlist)
						{
							t->next = s->next;
							s->next = t;
							head.teamlist = s;
							prev = s;
						}
						else
						{
							prev->next = s;
							t->next = s->next;
							s->next = t;
							prev = s;
						}

						//switch back to t before s
						temp = t;
						t = s;
						s = temp;
						ok = 1;
					}

					t = t->next;
					if (prev->next != t) prev = prev->next;
					s = s->next;
				}

				k++;
			}
		}
	}

	return status;
}

//-----------------------------------------------------------------------------
//								Is player available
//								-------------------
//
// General : The function gets the id of a player and checks if 
//  exists and if he plays for a team
//
// Parameters :
// ID (In)
//
// Return Value :
// SUCCESS if the the player exists else MISSING_RECORD
//
//-----------------------------------------------------------------------------
statusType IsPlayerAvailable(char* ID)
{
	statusType status = SUCCESS;
	playerNodePtr p = findPlayer(ID);

	if (!p) status = MISSING_RECORD;
	else
	{
		if (!p->tmptr) printf("player with id: %s is available!\n", ID);
		else
		{
			printf("player with id: %s is not available, plays for %s\n\n", ID, 
				p->tmptr->teamName);
			printTeamDetails(p->tmptr->teamName);
		}
	}

	return status;
}

void Exit()
{
	printf("Bye!\n");

	//delete players
	playerNodePtr p = head.playerList;
	while (p)
	{
		deletePlayer(p->PL.playerID);
		p = head.playerList;
	}

	//delete teams
	teamPtr t = head.teamlist;
	while (t)
	{
		deleteTeam(t->teamName);
		t = head.teamlist;
	}
}

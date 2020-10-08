#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// include head, player and team structs
# include "Head.h"

// typedef definition
typedef enum {
	FAILURE, SUCCESS, INVALID_INPUT,
	DUPLICATE_RECORD, MISSING_RECORD
} statusType;

typedef enum { FALSE, TRUE } boolean;

//function protos
char* GetString();
void BuildPlayersFile(int N);
void BuildTeamsFile(int N);
void HeadBuild();
playerNodePtr findPlayer(char* playerID);
statusType insertPlayer(char* playerID, char* lastName, char* firstName, int age);
statusType deletePlayerFromTeam(char* playerID);
statusType deletePlayer(char* playerID);
teamPtr findTeam(char* name);
statusType insertTeam(char* name);
statusType deleteTeam(char* name);
statusType joinPlayerToTeam(char* playerID, char* team_name);
void printPlayers(void);
void printTeams(void);
statusType printTeamDetails(char* name);
statusType sortAndPrintTeamDetails(char* name);
statusType SortTeamsByName();
statusType SortTeamsBySize();
statusType IsPlayerAvailable(char* ID);
void Exit();

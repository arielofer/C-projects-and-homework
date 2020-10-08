#define _CRT_SECURE_NO_WARNINGS
#include "menu_funcs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern headder head = { NULL, NULL };

//clear screen
void clrscreen() {
	system("@cls||clr");
}

//print menu screen
void menu()
{
	printf("-- the following commands are available --\n\n");
	printf("[1] find player\n\n[2] find team\n\n");
	printf("[3] insert player\n\n[4] insert team\n\n");
	printf("[5] join player to team\n\n[6] delete player\n\n");
	printf("[7] delete player from team\n\n[8] delete team\n\n");
	printf("[9] print players\n\n[10] print teams\n\n");
	printf("[11] print team players\n\n[12] sort team players\n\n");
	printf("[13] sort teams by name\n\n[14] sort teams by size\n\n");
	printf("[15] is player available?\n\n[16] exit\n\n");
}

int main()
{
	int ok = 1, cmd, len, i;;
	playerNodePtr p;
	teamPtr t;
	char* str, * ID, *first, *last, * age, *Tname, chr;
	statusType status;

	while(ok)
	{
		clrscreen();
		menu();
		printf("~ enter the number of the desired command: ");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1: //find player
			clrscreen();
			str = NULL;
			printf("~ enter the ID of the desired player: ");
			getchar();
			str = GetString();
			clrscreen();
			p = findPlayer(str);
			if (!p) printf("player not found!\n");
			else printf("success\n");
			getchar();
			free(str);
			break;

		case 2: //find team
			clrscreen();
			str = NULL;
			printf("~ enter the name of the desired team: ");
			getchar();
			str = GetString();
			clrscreen();
			t = findTeam(str);
			if (!t) printf("team Not found!\n");
			else printf("success\n");
			getchar();
			free(str);
			break;

		case 3: //insert player
			clrscreen();
			i = 0, len = 1;
			ID = NULL, first = NULL, last = NULL, age = NULL;
			str = NULL;
			printf("~ enter the player details divided by spaces: ");
			getchar();
			str = GetString();
			clrscreen();
			
			//get ID
			chr = str[i++];
			ID = (char*)realloc(ID, sizeof(char) * (len + 1));
			ID[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				ID = (char*)realloc(ID, sizeof(char) * (len + 1));
				ID[len - 1] = chr;
				if (len == 50) break;
			}

			ID[len - 1] = '\0';
			
			if (chr == '\0')
			{
				status = insertPlayer(ID, last, first, atoi(age));
				if (status != SUCCESS) printf("ERROR\n");
				else printf("success\n");
				getchar();
				free(str); free(ID); free(first); free(last); free(age);
				break;
			}
				
			//get Fname
			len = 1;
			chr = str[i++];
			first = (char*)realloc(first, sizeof(char) * (len + 1));
			first[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				first = (char*)realloc(first, sizeof(char) * (len + 1));
				first[len - 1] = chr;
				if (len == 50) break;
			}

			first[len - 1] = '\0';

			if (chr == '\0')
			{
				status = insertPlayer(ID, last, first, atoi(age));
				if (status != SUCCESS) printf("ERROR\n");
				else printf("success\n");
				getchar();
				free(str); free(ID); free(first); free(last); free(age);
				break;
			}

			//get Lname
			len = 1;
			chr = str[i++];
			last = (char*)realloc(last, sizeof(char) * (len + 1));
			last[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				last = (char*)realloc(last, sizeof(char) * (len + 1));
				last[len - 1] = chr;
				if (len == 50) break;
			}

			last[len - 1] = '\0';

			if (chr == '\0')
			{
				status = insertPlayer(ID, last, first, atoi(age));
				if (status != SUCCESS) printf("ERROR\n");
				else printf("success\n");
				getchar();
				free(str); free(ID); free(first); free(last); free(age);
				break;
			}

			//get age
			len = 1;
			chr = str[i++];
			age = (char*)realloc(age, sizeof(char) * (len + 1));
			age[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				age = (char*)realloc(age, sizeof(char) * (len + 1));
				age[len - 1] = chr;
				if (len == 50) break;
			}

			age[len - 1] = '\0';

			
			status = insertPlayer(ID, last, first, atoi(age));
			if (status != SUCCESS) printf("ERROR\n");
			else printf("success\n");
			getchar();
			free(str); free(ID); free(first); free(last); free(age);

			break;

		case 4: //insert team
			clrscreen();
			str = NULL;

			printf("~ enter the team name: ");
			getchar();
			str = GetString();
			clrscreen();
			status = insertTeam(str);
			free(str);
			if (status != SUCCESS) printf("error!\n");
			else printf("success\n");
			getchar();
			break;

		case 5: //join player to team
			clrscreen();
			str = NULL, ID = NULL, Tname = NULL;
			i = 0;

			printf("~ enter player ID and team name in one line divided by a space: ");
			getchar();
			str = GetString();
			clrscreen();

			//get ID
			len = 1;
			chr = str[i++];
			ID = (char*)realloc(ID, sizeof(char) * (len + 1));
			ID[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				ID = (char*)realloc(ID, sizeof(char) * (len + 1));
				ID[len - 1] = chr;
				if (len == 50) break;
			}

			ID[len - 1] = '\0';

			if (chr == '\0')
			{
				status = joinPlayerToTeam(ID, Tname);
				if (status != SUCCESS) printf("ERROR\n");
				else printf("success\n");
				getchar();
				free(str); free(ID); free(Tname);
				break;
			}

			//get Tname
			len = 1;
			chr = str[i++];
			Tname = (char*)realloc(Tname, sizeof(char) * (len + 1));
			Tname[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				Tname = (char*)realloc(Tname, sizeof(char) * (len + 1));
				Tname[len - 1] = chr;
				if (len == 50) break;
			}

			Tname[len - 1] = '\0';

			status = joinPlayerToTeam(ID, Tname);
			if (status != SUCCESS) printf("ERROR\n");
			else printf("success\n");
			getchar();
			free(str); free(ID); free(Tname);
			break;

		case 6: //delete player
			clrscreen();
			str = NULL;

			printf("~ enter player ID to delete: ");
			getchar();
			str = GetString();
			clrscreen();

			status = deletePlayer(str);
			if (status != SUCCESS) printf("ERROR\n");
			else printf("success\n");
			getchar();
			free(str);
			break;

		case 7: //delete player from team
			clrscreen();
			str = NULL;

			printf("~ enter player ID to remove from team: ");
			getchar();
			str = GetString();
			clrscreen();

			status = deletePlayerFromTeam(str);
			if (status != SUCCESS) printf("ERROR\n");
			else printf("success\n");
			getchar();
			free(str);
			break;
		
		case 8: //delete team
			clrscreen();
			str = NULL;

			printf("~ enter team name to delete: ");
			getchar();
			str = GetString();
			clrscreen();

			status = deleteTeam(str);
			if (status != SUCCESS) printf("ERROR\n");
			else printf("success\n");
			getchar();
			free(str);
			break;

		case 9: // print players
			clrscreen();
			printPlayers();
			getchar(); getchar();
			break;

		case 10: // print teams
			clrscreen();
			printTeams();
			getchar(); getchar();
			break;

		case 11: //print team details
			clrscreen();
			str = NULL;
			
			printf("~ enter team name to print players: ");
			getchar();
			str = GetString();
			clrscreen();

			status = printTeamDetails(str);
			if (status != SUCCESS) printf("error!\n");
			getchar();
			free(str);
			break;

		case 12: //sort team players
			clrscreen();
			str = NULL;
			
			printf("~ enter team name to sort players: ");
			getchar();
			str = GetString();
			clrscreen();

			status = sortAndPrintTeamDetails(str);
			if (status != SUCCESS) printf("error!\n");
			getchar();
			free(str);
			break;

		case 13: //sort teams by name
			clrscreen();
			
			status = SortTeamsByName();
			if (status != SUCCESS) printf("error!\n");
			else printf("success\n");
			getchar(); getchar();
			break;

		case 14: //sort teams by size
			clrscreen();
			
			status = SortTeamsBySize();
			if (status != SUCCESS) printf("error!\n");
			else printf("success\n");
			getchar(); getchar();
			break;
		
		case 15:
			clrscreen();
			str = NULL;
			
			printf("~ enter player ID check if available: ");
			getchar();
			str = GetString();
			clrscreen();

			status = IsPlayerAvailable(str);
			if (status != SUCCESS) printf("error!\n");
			getchar();
			free(str);
			break;

		case 16:
			clrscreen();
			Exit();
			getchar();
			ok = 0;
			break;

		default:
			clrscreen();
			printf("invalid command! try again\n");
			getchar();
		}

	}

	return 0;
}
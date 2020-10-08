#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int num;
	struct Node* next;
}Soldier, *sPtr;


void insertAfter(sPtr *s, int value) 
{
	sPtr p = (sPtr)malloc(sizeof(Soldier));
	p->num = value;
	if (*s == NULL) *s = p;
	else p->next = (*s)->next;
	(*s)->next = p;
	(*s) = p;
}

void delAfter(sPtr s, int *x)
{
	sPtr p = (sPtr)malloc(sizeof(Soldier));
	if (s != NULL && s->next != s) 
	{
		p = s->next;
		*x = p->num;
		s->next = p->next;
		free(p);
	}
}

void print(sPtr p)
{
	int x = p->num;
	while (p->next->num != x) {
		printf("%d-->", p->num);
		p = p->next;
	}
	printf("\n");
}

int big_boi_main()
{
	sPtr s = (sPtr)malloc(sizeof(Soldier)), p;
	s->num = 1; s->next = s;
	//p = s;
	for (int i = 2; i <= 41; i++)
	{
		insertAfter(&s, i);
	}
	int x;
	while (s->next != s)
	{
		s = s->next;
		delAfter(s, &x);
		printf("%d was killed\n", x);
		
		//print(p);
		//s = s->next;
	}
	printf("last to survive is: %d", s->num);
	return 0;
}
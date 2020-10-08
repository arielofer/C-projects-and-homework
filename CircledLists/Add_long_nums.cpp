#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int num;
	struct Node* next;
}listNode, *Ptr;

void write_to_file()
{
	FILE* fp;
	fp = fopen("numbers.txt", "wt");
	fputs("453627819230\n", fp);
	fputs("213709325761\n", fp);
	fclose(fp);
}

void build_numbers(Ptr* p1, Ptr* p2)
{
	FILE* fp = fopen("numbers.txt", "rt");
	Ptr start1, start2, p = NULL, q;
	char temp[4] = "";

	start1 = (Ptr)malloc(sizeof(listNode));

	fgets(temp, 5, fp);
	start1->num = atoi(temp);
	start1->next = p;
	p = start1;
	while (strcmp(temp, "\n")) {
		q = (Ptr)malloc(sizeof(listNode));
		fgets(temp, 5, fp);
		if (strcmp(temp, "\n")) break;
		q->num = atoi(temp);
		q->next = NULL;
		p->next = q;
		p = p->next;
	}

	p->next = start1;
	p1 = &start1;

	start2 = (Ptr)malloc(sizeof(listNode));
}

int main() {
	write_to_file();
	Ptr p1, p2;
	build_numbers(&p1, &p2);

	while (p1) 
	{
		printf("%d", p1->num);
		p1 = p1->next;
	}

	return 0;
}

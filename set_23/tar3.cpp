#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct eivar {
	int num;
	struct eivar* next;
}Node, *Nptr;


int main() {
	Nptr head = NULL, p, q;
	int num, size = 0;
	scanf("%d", &num);
	while (num >= 0) {
		if (num <= 99) {
			q = (Nptr)malloc(sizeof(struct eivar));
			q->num = num;
			q->next = NULL;
			if (!head) head = q;
			else {
				p = head;
				while (p->next)p = p->next;
				p->next = q;
			}
		}
		scanf("%d", &num);
	}
	p = head;
	while (p) {
		printf("%d, ", p->num);
		p = p->next;
	}
	printf("\n");
	//reverse
	Nptr rev = NULL;
	p = head;
	while (p) {
		q = p->next;
		p->next = rev;
		rev = p;
		p = q;
	}
	while (rev) {
		printf("%d, ", rev->num);
		rev = rev->next;
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"

void print_s(stack s)
{
	while (!stack_empty(s))
		printf("-\n%d\n-", s.data[s.top--]);
}

int main()
{
	stack s;
	stack_init(&s);
	stack_push(&s, 4); stack_push(&s, 3);
	stack_push(&s, 2); stack_push(&s, 1);

	print_s(s);
	print_s(s);
}

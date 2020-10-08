#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "DStack.h"

void stack_init(stack* s)
{
	s->top = -1;
	s->data = NULL;
}

int stack_empty(stack s)
{
	return (s.top == -1);
}

int stack_full(stack s) 
{
	return 0;
}

void stack_push(stack* s, stack_item x)
{
	stack_item* temp = (stack_item*)realloc(s->data, sizeof(stack_item) * (s->top + 2));
	if (!temp)
	{
		s->data = temp;
		s->data[++s->top] = x;
	}
}
stack_item stack_pop(stack* s)
{
	if (!stack_empty(*s))
	{
		stack_item x = s->data[s->top--];
		s->data = (stack_item*)realloc(s->data, sizeof(stack_item) * (s->top + 1));
		return x;
	}

	return 0;
}
stack_item stack_top(stack s)
{
	if (!stack_empty(s))
		return s.data[s.top];
	return 0;
}
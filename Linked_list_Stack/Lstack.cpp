#include "LStack.h"

void stack_init(stack* s)
{
	s->top = NULL;
}

int stack_empty(stack s)
{
	return (s.top == NULL);
}

int stack_full(stack s)
{
	return 0;
}

void stack_push(stack* s, stack_item x)
{
	struct node_type *temp = (node_type*)malloc(sizeof(struct node_type));
	
	temp->data = x;
	temp->next = s->top;
	s->top = temp;
}
stack_item stack_pop(stack* s)
{
	if (!stack_empty(*s))
	{
		struct node_type *temp = s->top;
		stack_item data = s->top->data;
		s->top = temp->next;
		free(temp);
		return data;
	}

	return 0;
}

stack_item stack_top(stack s)
{
	if (!stack_empty(s))
	{
		return s.top->data;
	}
	return 0;
}

void print_s(stack s)
{
	stack temp; stack_init(&temp);
	while (!stack_empty(s))
	{
		printf("-\n%d\n-", s.top->data);
		stack_push(&temp, stack_pop(&s));
	}
	while (!stack_empty(temp))
	{
		stack_push(&s, stack_pop(&temp));
	}

}
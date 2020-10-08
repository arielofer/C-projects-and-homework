#pragma once

typedef int stack_item;

typedef struct
{
	int top;
	stack_item *data;
}stack;

//protos
void stack_init(stack* s);
int stack_empty(stack s);
int stack_full(stack s);
void stack_push(stack* s, stack_item x);
stack_item stack_pop(stack* s);
stack_item stack_top(stack s);
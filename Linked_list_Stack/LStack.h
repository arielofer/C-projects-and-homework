#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int stack_item;

struct node_type
{
	stack_item data;
	struct node_type* next;
};

typedef struct
{
	struct node_type* top; //head
}stack;

//protos
void stack_init(stack* s);
int stack_empty(stack s);
int stack_full(stack s);
void stack_push(stack* s, stack_item x);
stack_item stack_pop(stack* s);
stack_item stack_top(stack s);
void print_s(stack s);
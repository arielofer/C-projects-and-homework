#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int que_item;

typedef struct node_type
{
	que_item info;
	struct node_type* next;
} node;

typedef struct //queue
{
	node* head, * rear;
}queue;

void queue_init(queue *q);
void enqueue(queue* q, que_item x);
que_item dequeue(queue *q);
que_item queue_top(queue q);
int queue_empty(queue q);
void queue_print(queue* q);
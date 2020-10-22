#include "queue.h"

void queue_init(queue* q)
{
	q->rear = q->head = NULL;
}

void enqueue(queue* q, que_item x)
{
	que_node* a = (que_node*)malloc(sizeof(que_node));

	a->info = x;
	a->next = NULL;
	if (queue_empty(*q))
		q->head = q->rear = a;
	else // insert in back
	{
		q->rear->next = a;
		q->rear = a;
	}
}

que_item dequeue(queue* q)
{
	que_item x = q->head->info;
	que_node* a = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
		q->rear = NULL;
	free(a);
	return x;
}

que_item queue_top(queue q)
{
	return q.head->info;
}

int queue_empty(queue q)
{
	return q.head == NULL;
}

void queue_print(queue* q)
{
	queue temp;
	queue_init(&temp);

	while (!queue_empty(*q))
	{
		printf("%d <== ", queue_top(*q));
		enqueue(&temp, dequeue(q));
	}
	while (!queue_empty(temp))
	{
		enqueue(q, dequeue(&temp));
	}
}

void queue_sort(queue* q)
{
	queue temp; queue_init(&temp);
	que_item x, y, min;
}
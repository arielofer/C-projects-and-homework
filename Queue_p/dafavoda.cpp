#include "queue.h"

//tar2
que_item min_in_both(queue *q1, queue *q2)
{
	queue tq1, tq2; queue_init(&tq1); queue_init(&tq2);
	que_item x, y, min = -1;
	
	x = dequeue(q1);
	y = dequeue(q2);

	while (!queue_empty(*q1) && !queue_empty(*q2))
	{
		if (x == y)
		{
			min = x;
			enqueue(&tq1, x);
			enqueue(&tq2, y);
			break;
		}
		else
		{
			if (x > y)
			{
				enqueue(&tq2, y);
				y = dequeue(q2);
			}
			else
			{
				enqueue(&tq1, x);
				x = dequeue(q1);
			}
		}
	}

	enqueue(&tq1, x);
	enqueue(&tq2, y);

	while (!queue_empty(tq1))
		enqueue(q1, dequeue(&tq1));
	
	while (!queue_empty(tq2))
		enqueue(q2, dequeue(&tq2));

	return min;
}

//tar4
void no_dups(queue* q)
{
	queue temp; queue_init(&temp);
	que_item x;
	int found;

	while (!queue_empty(*q))
	{
		x = dequeue(q);

		found = 0;
		enqueue(&temp, -999);
		while (queue_top(temp) != -999)
		{
			if (queue_top(temp) == x)
				found = 1;

			enqueue(&temp, dequeue(&temp));
		}

		dequeue(&temp);
		if (!found) enqueue(&temp, x);

	}

	while (!queue_empty(temp))
		enqueue(q, dequeue(&temp));
}

//tar6
int times_in_queue(queue* q, que_item n)
{
	int counter = 0;
	queue temp; queue_init(&temp);
	while(!queue_empty(*q))
	{
		if(queue_top(*q) == n)
			counter++;
		
		enqueue(&temp, dequeue(q));
	}

	while (!queue_empty(temp))
		enqueue(q, dequeue(&temp));

	return counter;
}

//tar 10


int main()
{
	queue q1, q2; queue_init(&q1); queue_init(&q2);
	que_item x;

	scanf("%d", &x);
	while (x != -1)
	{
		enqueue(&q1, x);
		scanf("%d", &x);
	}

	/*scanf("%d", &x);
	while (x != -1)
	{
		enqueue(&q2, x);
		scanf("%d", &x);
	}*/

	//tar2 - only works with sorted queues
	//printf("min is %d\n", min_in_both(&q1, &q2));

	//tar4
	no_dups(&q1);

	queue_print(&q1);
	printf("\n");
	//queue_print(&q2);

	//tar6
	printf("%d appears %d times in queue\n", queue_top(q1), times_in_queue(&q1, queue_top(q1)));

	return 0;
}
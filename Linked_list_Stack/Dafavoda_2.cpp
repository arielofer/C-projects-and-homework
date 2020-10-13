#include "LStack.h"

//tar1
stack product_of_blocks(stack s)
{
	stack temp; stack_init(&temp);
	stack_item x, prev;
	int counter = 1;
	x = stack_pop(&s);
	prev = x;

	while (!stack_empty(s))
	{
		x = stack_pop(&s);
		if (x == prev)
		{
			counter++;
		}
		else
		{
			if (counter > 1)
			{
				stack_push(&temp, x * counter);
				counter = 1;
			}
			prev = x;
		}
	}

	return temp;
}

int main()
{
	stack s, s2;
	stack_init(&s);
	stack_init(&s2);
	stack_push(&s, 4); stack_push(&s, 4);
	stack_push(&s, 2); //stack_push(&s, 1);

	//tar1
	s2 = product_of_blocks(s);
	print_s(s2);

	return 0;
}
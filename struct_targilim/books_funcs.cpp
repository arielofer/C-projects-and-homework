#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Headers.h"
#include <string.h>


void less_then_5_print(book_stock stock) {
	for (int i = 0; i < 10; i++) {
		if (stock.stock[i].amount_in_stock < 5)
			printf("%s\n", stock.stock[i].name);
	}
}

void more_then_4_sum_prices(authors list) {
	for (int i = 0; i < 5; i++)
		if (list.list[i].amount_written > 4)
			printf("%.2f\n", list.list[i].sum_of_prices);
}

void array_of_authors(authors list, authors* new_list, int* size) {
	int count = 0;
	for (int i = 0; i < 5;i++)
		if (list.list[i].amount_written > 10) {
			new_list->list[count++] = list.list[i];
		}
	*size = count;
}

void min_price_books(authors list, book_stock stock) {
	int index = 0;
	float min = 1000;
	for (int i = 0; i < 5; i++) {
		if (min > list.list[i].sum_of_prices) {
			index = 0;
			min = list.list[i].sum_of_prices;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (stock.stock[i].author_code == index)
			printf("%s, ", stock.stock[i].name);
	}
	printf("\n");
}


void sort_by_name(authors* list) {
	author temp;
	int ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i < 4; i++) {
			if (strcmp(list->list[i].name, list->list[i + 1].name) == 1) {
				temp = list->list[i];
				list->list[i] = list->list[i + 1];
				list->list[i + 1] = temp;
				ok = 1;
			}
		}
	}
}
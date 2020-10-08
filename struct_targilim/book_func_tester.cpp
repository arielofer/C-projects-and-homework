#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Headers.h"


book_stock bookstock = {
	book {"book1", 0, 1975, 5, 14.90},
	{"book2", 0, 1978, 2, 15.90},
	{"adventure1", 1, 1973, 1, 20.90},
	{"space race", 1, 1965, 7, 10.90},
	{"cats", 2, 1985, 3, 13.90},
	{"dogs", 2, 1983, 5, 11.90},
	{"science 101", 3, 1995, 11, 16.90},
	{"yellow bear", 4, 1955, 4, 12.90},
	{"flying gay kid", 4, 1959, 3, 14.90},
	{"girl on drugs", 4, 1960, 5, 17.90}
};


authors author_list = {
	author {"h.p lovecraft", 11, 14.90 + 15.90},
	{"dr. suess", 1, 20.90 + 16.90},
	{"j.k. rowling", 2, 14.90 + 15.90},
	{"aaron sack", 3, 3 * 16.90},
	{"the lorax", 5, 14.90 + 17.90 + 12.90}
};


authors new_list;


//int main() {
//	less_then_5_print(bookstock);
//	more_then_4_sum_prices(author_list);
//	int size = 0;
//	array_of_authors(author_list, &new_list, &size);
//	for (int i = 0; i < size; i++) {
//		printf("%s\n", new_list.list[i].name);
//	}
//	min_price_books(author_list, bookstock);
//	sort_by_name(&author_list);
//	for (int i = 0; i < 5; i++)
//		printf("%s, ", author_list.list[i].name);
//	printf("\n");
//
//	return 0;
//}
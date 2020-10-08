#pragma once

//constants
#define N 10 // board dimentions(N*(N*2))
#define n 5 // amount of directions(including 0)

typedef struct Direction {
	int nline;
	int ncol;
}dir_array[n];
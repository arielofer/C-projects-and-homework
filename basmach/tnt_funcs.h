#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//constants
#define N 10 // board dimentions(N*(N*2))

//typedefs
typedef struct Direction {
	int ncol;
	int nline;
}dir_array;

//protos
void clr_screen();
void board_build(int board[][N + 2], int n);
void print_board(int board[][N + 2]);
void con_trof(int board[][N + 2]);

#pragma once

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Monom.h"

//defines
#define MAX_STRING_LENGTH 50

//protos
char* GetString();
PolyNodePtr PolyBuild(char* str);
void polynomePrint(PolyNodePtr poly);
PolyNodePtr PolyAdd(PolyNodePtr p1, PolyNodePtr p2);
PolyNodePtr PolyMul(PolyNodePtr p1, PolyNodePtr p2);
void derivative(PolyNodePtr* p, int depth);
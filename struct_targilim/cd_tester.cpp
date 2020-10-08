#include "Headers2.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main() {
	CD cd1 = {};
	fill_cd(&cd1);
	print_cd(cd1);

	return 0;
}
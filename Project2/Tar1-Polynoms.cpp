#define _CRT_SECURE_NO_WARNINGS
#include "poly_funcs.h"

int poly_main()
{
	PolyNodePtr p1, p2, sum ,mul;
	char* str= NULL;
	int depth;

	// get 2 polynomes
	printf("please enter polynom:\n");
	str = GetString();
	p1 = PolyBuild(str);

	printf("please enter polynom:\n");
	str = GetString();
	p2 = PolyBuild(str);

	// addition & multiplication
	sum = PolyAdd(p1, p2);
	mul = PolyMul(p1, p2);

	printf("sum of p1 and p2 is:");
	polynomePrint(sum);
	printf("product of p1 and p2 is:");
	polynomePrint(mul);
	
	//derivative of the product polynom
	printf("enter derivative path\n");
	scanf("%d", &depth);
	derivative(&mul, depth);

	return 0;
}
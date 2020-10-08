#define _CRT_SECURE_NO_WARNINGS
#include "poly_funcs.h"

//-----------------------------------------------------------------------------
//								Get String
//								----------
//
// General : The function gets input from user, builds a dynamic 
//	string and return it
//
// Parameters :
//
// Return Value : a pointer to a dynamic string.
//
//-----------------------------------------------------------------------------
char* GetString()
{
	char chr;
	int len = 1;
	char* str = NULL;
	str = (char*)realloc(str, sizeof(char) * (len + 1));
	chr = getchar();
	str[len - 1] = chr;
	while (chr != '\n')
	{
		chr = getchar();
		++len;
		str = (char*)realloc(str, sizeof(char) * (len + 1));
		str[len - 1] = chr;
		if (len == MAX_STRING_LENGTH) break;
	}
	str[len - 1] = '\0';
	return str;
}

//-----------------------------------------------------------------------------
//						add monom to Polynome and sort
//						------------------------------
//
// General : The function gets a polynom and a new monom details.
//   the function adds it to the polynom and keeps it sorted.
//
// Parameters :
// head (In & out)
// coe (In)
// pow (out)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void AddPolyToListSorted(PolyNodePtr* head, int coe, int pow)
{
	PolyNodePtr pos = *head, last = *head, p;

	p = (PolyNodePtr)malloc(sizeof(PolyNodeRec));
	if (p == NULL) printf("error");
	else {
		p->monom.coefficient = coe;
		p->monom.power = pow;
		p->next = NULL;

		if (*head == NULL)
			*head = p;
		else
		{
			while (pos && pos->monom.power >= p->monom.power)
			{
				//if the powers are the same sum the coefficients
				if (pos->monom.power == p->monom.power)
				{
					pos->monom.coefficient += p->monom.coefficient;

					//dont continue
					return;
				}
				last = pos;
				pos = pos->next;
			}

			//if p's power bigger then head's
			if (pos == last)
			{
				p->next = (*head);
				(*head) = p;
			}

			// last => p => pos
			else
			{
				last->next = p;
				p->next = pos;
			}
		}
	}
}

//-----------------------------------------------------------------------------
//								Polynome builder
//								----------------
//
// General : The function gets a dynamic string str (user input), and builds
//   a linked list of PolyNodes from it.
//
// Parameters :
// str (In)
//
// Return Value : a pointer to the linked list.
//
//-----------------------------------------------------------------------------
PolyNodePtr PolyBuild(char* str)
{
	PolyNodePtr p = NULL;
	char chr = ' ', *pow = NULL, *coe = NULL;
	int i = 0, len;

	if (!str[i])
	{
		AddPolyToListSorted(&p, 0, 0);
	}
	else
	{
		while (chr != '\0')
		{
			// get the coefficient
			len = 1;
			coe = (char*)malloc((len + 1) * sizeof(char));
			chr = str[i++];
			coe[len - 1] = chr;
			while (chr != ' ')
			{
				chr = str[i++];
				++len;
				coe = (char*)realloc(coe, (len + 1) * sizeof(char));
				coe[len - 1] = chr;
				if (len == MAX_STRING_LENGTH) break;
			}
			coe[len - 1] = '\0';

			// get the power
			len = 1;
			pow = (char*)malloc((len + 1) * sizeof(char));
			chr = str[i++];
			pow[len - 1] = chr;
			while (chr != ' ' && chr != '\0')
			{
				chr = str[i++];
				++len;
				pow = (char*)realloc(pow, (len + 1) * sizeof(char));
				pow[len - 1] = chr;
				if (len == MAX_STRING_LENGTH) break;
			}
			pow[len - 1] = '\0';

			AddPolyToListSorted(&p, atoi(coe), atoi(pow));
		}
	}

	return p;
}

//-----------------------------------------------------------------------------
//								Polynome printer
//								----------------
//
// General : The function gets a polynome and prints it
//
// Parameters :
// poly (In)
//
// Return Value : None.
//
//-----------------------------------------------------------------------------
void polynomePrint(PolyNodePtr poly)
{
	while (poly)
	{
		if (poly->monom.coefficient)
			printf("%d %d ", poly->monom.coefficient, poly->monom.power);
		poly = poly->next;
	}
	printf("\n");
}

//-----------------------------------------------------------------------------
//								Polynome addition
//								-----------------
//
// General : The function gets a 2 polynoms and returns their sum
//
// Parameters :
// p1 (In)
// p2 (In)
//
// Return Value : a pointer to a polynom which is the sum of p1 and p2.
//
//-----------------------------------------------------------------------------
PolyNodePtr PolyAdd(PolyNodePtr p1, PolyNodePtr p2)
{
	PolyNodePtr Psum = NULL;

	while (p1)
	{
		//add p1 to the sum
		AddPolyToListSorted(&Psum, p1->monom.coefficient, p1->monom.power);
		p1 = p1->next;
	}

	while(p2)
	{
		//add p2 to the sum
		AddPolyToListSorted(&Psum, p2->monom.coefficient, p2->monom.power);
		p2 = p2->next;
	}

	return Psum;
}

//-----------------------------------------------------------------------------
//								Polynome multiplication
//								-----------------------
//
// General : The function gets a 2 polynoms and returns their product
//
// Parameters :
// p1 (In)
// p2 (In)
//
// Return Value : a pointer to a polynom which is the product of p1 and p2.
//
//-----------------------------------------------------------------------------
PolyNodePtr PolyMul(PolyNodePtr p1, PolyNodePtr p2)
{
	PolyNodePtr Pmul = NULL, temp;
	int coe_pro, pow_sum;

	while (p1)
	{
		temp = p2;
		while (temp)
		{
			coe_pro = p1->monom.coefficient * temp->monom.coefficient;
			pow_sum = p1->monom.power + temp->monom.power;
			
			AddPolyToListSorted(&Pmul, coe_pro, pow_sum);

			temp = temp->next;
		}

		p1 = p1->next;
	}

	return Pmul;
}

//-----------------------------------------------------------------------------
//									derivative
//									----------
//
// General : The function gets a polynom, and an integer and returns
//  its derivative function in the given depth
//
// Parameters :
// p (In & Out)
// depth (In)
//
// Return Value : None
//
//-----------------------------------------------------------------------------
void derivative(PolyNodePtr* p, int depth)
{
	PolyNodePtr pos;

	for (int i = 0; i < depth; i++)
	{
		pos = *p;
		while (pos)
		{
			pos->monom.coefficient *= pos->monom.power;
			pos->monom.power--;

			pos = pos->next;
		}
		polynomePrint(*p);
	}
}
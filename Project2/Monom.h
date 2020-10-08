#pragma once

// a single monomial
typedef struct { 
	int coefficient;
	int power;
}Monom, *Mptr;

// a node of a linked list of Monomes that represents a polynome
typedef struct PolyNode{
	Monom monom;
	PolyNode* next; // a pointer to the next node in the polynome
}PolyNodeRec, *PolyNodePtr;
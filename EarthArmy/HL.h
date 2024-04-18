#pragma once
#include "../DS/ArrayStack.h"
#include "Healer.h"
class HL
{
	ArrayStack<Healer*> Heal;
	int count;
public:
	HL(); 
	~HL();

	bool insert(Healer* u);

	bool remove(unit*& u); 

	int getCount(); 


	void print(); 
};


#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
class EarthSoldierList
{
	LinkedQueue<unit*> l;
	int count;
public:
	


	bool insert(unit*& u);

	bool remove(unit*& u);

	void print();

};


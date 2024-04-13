#pragma once
#include "../unit.h"
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"../unit.h"
class AlienSoldierList
{
	LinkedQueue<unit*> l;
	int count;
public:
	AlienSoldierList();
	bool insert(unit*& u);
	bool remove(unit*& u);
	void print();
};


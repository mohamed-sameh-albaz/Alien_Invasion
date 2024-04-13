#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"EarthSoldier.h"
class EarthSoldierList
{
	LinkedQueue<unit*> soldierList; //change list name
	int count;
public:
	EarthSoldierList();
	bool insert(unit* u);	//remove reference 
	bool remove(unit*& u);
	void print();
	int getCount();
};

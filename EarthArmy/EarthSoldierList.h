#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"EarthSoldier.h"
class EarthSoldierList
{
	LinkedQueue<EarthSoldier*> soldierList; //change list name
	int count;
public:
	EarthSoldierList();
	~EarthSoldierList();

	bool insert(EarthSoldier* u);	//remove reference 
	bool remove(unit*& u);
	void print();
	int getCount();
};

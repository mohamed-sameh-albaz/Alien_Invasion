#pragma once
#include "../DS/priQueue.h"
#include "../DS/LinkedQueue.h"
#include "EarthSoldier.h"
#include "EarthTank.h"

class UML
{
	priQueue<unit*> soldiersToHeal;
	LinkedQueue<unit*> tanksToHeal;
	int count;
public:
	~UML();
	UML() { count = 0; }
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
};


#pragma once
#include "../DS/priQueue.h"
#include "../DS/LinkedQueue.h"
#include "EarthSoldier.h"
#include "EarthTank.h"

class UML
{
	priQueue<unit*> soldiersToHeal;
	LinkedQueue<unit*> tanksToHeal;
public:
	~UML();
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
};


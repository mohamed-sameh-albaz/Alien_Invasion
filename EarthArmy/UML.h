#pragma once
#include "../DS/priQueue.h"
#include "../DS/LinkedQueue.h"
#include "EarthSoldier.h"
#include "EarthTank.h"

class UML
{
	priQueue<unit*> soldiersToHeal;
	LinkedQueue<unit*> tanksToHeal;//must be changed
	int healed_count, curr_count;
public:
	~UML();
	UML(); 
	int get_healed_count();
	void set_healed_count(int a);
	int get_curr_count();
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
};


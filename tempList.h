#pragma once
#include "unit.h"
#include "DS/LinkedQueue.h"
class tempList
{
	LinkedQueue<unit*> list;
	int count;
	static bool firstPrinted;
public:
	tempList();
	~tempList();
	bool insert(unit* unit);
	bool remove(unit*& unit);
	int getCount();
	void print(type attacker,int id);
};


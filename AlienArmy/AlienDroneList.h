#pragma once
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"../DS/Node.h"

class AlienDroneList
{
	double_endedQueue<unit*> l;
	int count;
public:
	
	AlienDroneList();
	bool RemoveEnd(unit*& u);
	bool RemoveFront(unit*& u);
	bool InsertEnd(unit*& u);
	bool insertFront(unit*& u);
	void print();
	int getCount();
};


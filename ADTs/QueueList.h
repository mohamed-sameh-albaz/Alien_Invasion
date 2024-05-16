#pragma once
#include<iostream>
#include"../unit.h"
#include "../EarthArmy/EarthSoldier.h"
#include"../DS/LinkedQueue.h"

class QueueList :public LinkedQueue<unit*>
{
	int count;
public:
	QueueList();
	~QueueList();
	int getCount();
	bool insert(unit* newUnit);
	bool peek(unit*& frontUnit);
	bool remove(unit*& removedUnit);
	void print(type unitType);
};
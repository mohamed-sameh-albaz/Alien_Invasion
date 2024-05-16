#pragma once
#include<iostream>
#include"../unit.h"
#include"../DS/priQueue.h"

class PriQueueList : public priQueue<unit*>
{
	int count;
public:
	PriQueueList();
	~PriQueueList();
	int getCount();
	bool insert(unit*addedUnit,int priority);
	bool peek(unit*& peekedUnit);
	bool remove(unit*& pickedUnit);
	void print();
};
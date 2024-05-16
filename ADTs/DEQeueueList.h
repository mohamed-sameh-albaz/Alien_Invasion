#pragma once
#include<iostream>
#include"../unit.h"
#include"../DS/double_endedQueue.h"

class DEQueueList :public double_endedQueue<unit*>
{
	int count;
public:
	DEQueueList();
	~DEQueueList();
	int getCount();
	bool removeEnd(unit*& pickedUnit);
	bool removeFront(unit*& pickedUnit);
	bool insertEnd(unit* addedUnit);
	bool insertFront(unit* addedUnit);
	bool backPeek(unit*& peekedUnit);
	bool frontPeek(unit*& peekedUnit);
	void print();
};
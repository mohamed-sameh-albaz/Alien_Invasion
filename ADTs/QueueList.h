#pragma once
#include<iostream>
#include"../unit.h"
#include "../EarthArmy/EarthSoldier.h"
#include"../DS/LinkedQueue.h"


//template <typename T>
class QueueList :public LinkedQueue<unit*>
{
	int count;
public:
	QueueList() { count = 0; }
	~QueueList()
	{
		LinkedQueue::~LinkedQueue();
	}
	int getCount()
	{
		return count;
	}
	bool insert(unit* newUnit)
	{
		count++;
		return enqueue(newUnit);
	}
	bool peek(unit*& frontUnit)
	{
		return LinkedQueue::peek(frontUnit);
	}
	bool remove(unit*& removedUnit)
	{
		if (dequeue(removedUnit))
		{
			count--;
			return true;
		}
		return false;
	}
	void print(type unitType=AD)
	{
		Node<unit*> *nextUnit = frontPtr;
		cout << count;
		switch (unitType)
		{
		case ES:cout << " ES [";
			break;
		case AS:cout << " AS [";
			break;
		default:cout << " units [";//killed list
		}
		while (nextUnit)
		{
			if (nextUnit->getItem()->get_type() == ES) {
				unit* mySol = nextUnit->getItem();
				EarthSoldier* toBePrinted = dynamic_cast<EarthSoldier*>(mySol);
				if (toBePrinted->isInfected()) {
					cout << "#";
				}
			}
			cout << nextUnit->getItem()->get_id();
			if (nextUnit->getNext())
				cout << ", ";
			nextUnit = nextUnit->getNext();
		}
		cout << "]" << endl;
		cout << "_____________________________________________________\n";
	}
};
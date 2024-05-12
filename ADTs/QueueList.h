#pragma once
#include<iostream>
#include"../unit.h"
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
	void print(type unitType)
	{
		Node<unit*> *nextUnit = frontPtr;
		cout << count;
		switch (unitType)
		{
		case EG:cout << " EG [";
			break;
		case ES:cout << " ES [";
			break;

		case ET:cout << " ET [";
			break;

		case AS:cout << " AS [";
			break;

		case AD:cout << " AD [";
			break;

		case AM:cout << " AM [";
			break;
		}
		while (nextUnit)
		{
			cout << nextUnit->getItem()->get_id();
			if (nextUnit->getNext())
				cout << ", ";
			nextUnit = nextUnit->getNext();
		}
		cout << "]" << endl;
		cout << "_____________________________________________________\n";
	}
};
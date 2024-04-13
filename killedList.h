#pragma once
#include<iostream>
#include"unit.h"
#include"DS/LinkedQueue.h"
using namespace std;

class killedList
{
	LinkedQueue<unit*> deadList;
	int count;

public:
	killedList() :count(0)
	{
	}

	~killedList()
	{
	}

	bool insert(unit*& killedUnit)
	{
		count++;
		return deadList.enqueue(killedUnit);
	}

	void print()
	{
		LinkedQueue<unit*> temp;
		unit* tempUnit;
		cout << "\n============== killed/Destructed Units ==============" << endl;
		cout << count << " units [";
		while (!deadList.isEmpty())
		{
			deadList.dequeue(tempUnit);
			cout << tempUnit->get_id();
			temp.enqueue(tempUnit);
			if (!deadList.isEmpty())
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;
		while (!temp.isEmpty())
		{
			temp.dequeue(tempUnit);
			deadList.enqueue(tempUnit);
		}
	}
	
};


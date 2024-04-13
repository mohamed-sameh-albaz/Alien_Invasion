#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"EarthSoldier.h" // including EarthSoldier
using namespace std;

class EarthSoldierList
{
	LinkedQueue<unit*> soldierList; //change list name
	int count;
public:
	EarthSoldierList() { count = 0;
	}
	bool insert(unit* u) { //remove refrence 
		count++;
		return soldierList.enqueue(u);
	}
	bool remove(unit*& u) {

		if (soldierList.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	void print() { //change output form
		LinkedQueue<unit*> l1;
		unit* u;
		cout << getCount() << " ES [";
		while (soldierList.dequeue(u)) {
			cout<<u->get_id();
			//cout << endl << "______________________" << endl;
			l1.enqueue(u);
			if (!soldierList.isEmpty())
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;

		while (l1.dequeue(u))
			soldierList.enqueue(u);

	}
	
	int getCount()
	{
		return count;
	}


};


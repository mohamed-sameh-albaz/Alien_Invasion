#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"AlienSoldier.h" //including soldier
using namespace std;

class AlineSoldierList
{
	LinkedQueue<unit*> alienSoldierList; //change list name
	int count;
public:
	AlineSoldierList() {
		count = 0;
}
	bool insert(unit* u) {  //remove refrence 
		count++;
		return alienSoldierList.enqueue(u);
	}
	bool remove(unit*& u) {
		if (alienSoldierList.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	void print() {  //change output form
		LinkedQueue<unit*> l1;
		unit* u;

		cout << getCount() << " AS [";
		while (alienSoldierList.dequeue(u)) {
			cout << u->get_id();
			//cout << endl << "______________________" << endl;
			l1.enqueue(u);
			if (!alienSoldierList.isEmpty())
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;

		while (l1.dequeue(u))
			alienSoldierList.enqueue(u);

	}
	int getCount()
	{
		return count;
	}
};


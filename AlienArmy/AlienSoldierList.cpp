#pragma once
#include "../unit.h"
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"../unit.h"
class AlineSoldierList
{
	LinkedQueue<unit*> l;
	int count;
public:
	AlineSoldierList() {
		count = 0;
}
	bool insert(unit*& u) {
		count++;
		return alienSoldierList.enqueue(u);
	}
	bool remove(unit*& u) {
		if (l.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	void print() {
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
};


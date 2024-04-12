#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
class EarthSoldierList
{
	LinkedQueue<unit*> l;
	int count;
public:
	EarthSoldierList() { count = 0;
	}
	bool insert(unit*& u) {
		count++;
		return l.enqueue(u);
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
		while (l.dequeue(u)) {
			u->disp();
			cout << endl << "______________________" << endl;
			l1.enqueue(u);
		}

		while (l1.dequeue(u))
			l.enqueue(u);

	}



};


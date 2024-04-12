#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
class EarthSoldierList 
{
	LinkedQueue<unit*> l;

public:
	bool insert(unit*& u) {
		return l.enqueue(u);
	}
	bool remove(unit*& u) {
		return l.dequeue(u);
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


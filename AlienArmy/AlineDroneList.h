#pragma once
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"../DS/Node.h"

class AlineDroneList
{
	double_endedQueue<unit*> l;
	int count;
public:
	AlineDroneList() { count = 0;
	}
	bool RemoveEnd(unit*& u) {

		if (l.dequeueBack(u))
			count--;
		else return 0;
		return 1;

	}
	bool RemoveFront(unit*& u) {
		if (l.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	bool InsertEnd(unit*& u) {
		count++;
		return l.enqueue(u);


	}
	bool insertFront(unit*& u) {
		count++;
		return l.enqueueFront(u);


	}

	void print() {
		double_endedQueue<unit*> l1;
		unit* u;
		while (l.dequeue(u)) {
			u->disp();
			cout << endl << "______________________" << endl;
			l1.enqueue(u);
		}

		while (l1.dequeue(u))
			l.enqueue(u);

	}
	int getCount() {
		return count;
	}
};


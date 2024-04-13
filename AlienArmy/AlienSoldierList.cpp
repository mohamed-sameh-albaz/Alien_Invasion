#include "AlienSoldierList.h"
#include <print>

AlienSoldierList::AlienSoldierList()
{
		count = 0;
}

	bool AlienSoldierList::insert(unit*& u) {
		count++;
		return l.enqueue(u);
	}
	bool AlienSoldierList::remove(unit*& u) {
		if (l.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	void AlienSoldierList::print() {
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

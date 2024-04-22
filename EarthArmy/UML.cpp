#include "UML.h"

UML::~UML()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}

bool  UML::insert(unit* u) {
	if (u->get_type() == AS) {
		soldiersToHeal.enqueue(u, -1 * (u->get_health() / u->get_initial_health() * 100));
		return true;
	}
	else if (u->get_type() == ET) {
		tanksToHeal.enqueue(u);
		return true;
	}
	else return false;
}

bool  UML::remove(unit*& u) {
	if (!soldiersToHeal.isEmpty()) {
		int i;
		soldiersToHeal.dequeue(u, i);
		return true;
	}
	else if (!tanksToHeal.isEmpty()) {
		tanksToHeal.dequeue(u);
		return true;
	}
	else return false;
}

void  UML::print() {
	priQueue<unit*> tmpS = soldiersToHeal;
	LinkedQueue<unit*> tmpT = tanksToHeal;

	while (!tmpS.isEmpty()) {
		unit* u = nullptr;
		int tmp;
		tmpS.dequeue(u, tmp);
		u->disp();
		cout << endl << "---------------------------" << endl;
	}
	while (!tmpT.isEmpty()) {
		unit* u = nullptr;
		tmpT.dequeue(u);
		u->disp();
		cout << endl << "---------------------------" << endl;
	}
}

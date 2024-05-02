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
	if (u->get_type() == ES) {
		soldiersToHeal.enqueue(u, -1 * (u->get_health() / u->get_initial_health() * 100));
		count++;
		return true;
	}
	else if (u->get_type() == ET) {
		tanksToHeal.enqueue(u);
		count++;
		return true;
	}
	else return false;
}

bool  UML::remove(unit*& u) {
	if (!soldiersToHeal.isEmpty()) {
		int i;
		soldiersToHeal.dequeue(u, i);
		count--;
		return true;
	}
	else if (!tanksToHeal.isEmpty()) {
		tanksToHeal.dequeue(u);
		count--;
		return true;
	}
	else return false;
}

void  UML::print() {
	priQueue<unit*> tmpS;
	LinkedQueue<unit*> tmpT;
	cout << "\n============== Units To Be Healed ==============" << endl;
	cout << count << " units [";

	while (!soldiersToHeal.isEmpty()) {
		unit* u = nullptr;
		int tmp;
		soldiersToHeal.dequeue(u, tmp);
		tmpS.enqueue(u, tmp);
		cout << u->get_id();
		if (!soldiersToHeal.isEmpty() || !tanksToHeal.isEmpty()) cout << ", ";
	}

	while (!tanksToHeal.isEmpty()) {
		unit* u = nullptr;
		tanksToHeal.dequeue(u);
		tmpT.enqueue(u);
		cout << u->get_id();
		if (!tanksToHeal.isEmpty()) cout << ", ";
	}

	cout << "]" << endl;
	while (!tmpS.isEmpty()) {
		unit* u = nullptr;
		int n;
		tmpS.dequeue(u, n);
		soldiersToHeal.enqueue(u, n);
	}
	while (!tmpT.isEmpty()) {
		unit* u = nullptr;
		tmpT.dequeue(u);
		tanksToHeal.enqueue(u);
	}
}

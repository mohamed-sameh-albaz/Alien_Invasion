#include "AlienSoldierList.h"

AlienSoldierList::AlienSoldierList()
{
	count = 0;
}

AlienSoldierList::~AlienSoldierList()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}

bool AlienSoldierList::insert(AlienSoldier* u) {
	count++;
	return alienSoldierList.enqueue(u);
}
bool AlienSoldierList::remove(unit*& u) {
	AlienSoldier* a;
	if (alienSoldierList.dequeue(a)) {
		count--;
		u = a;
	}
	else {
		u = a;
		return 0;
	}
	return 1;
}
void AlienSoldierList::print() {
	LinkedQueue<AlienSoldier*> l1;
	AlienSoldier* u;

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

int AlienSoldierList::getCount()
{
	return count;
}

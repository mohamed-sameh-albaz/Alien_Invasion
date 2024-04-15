#include "AlienSoldierList.h"

AlienSoldierList::AlienSoldierList()
{
	count = 0;
}

bool AlienSoldierList::insert(unit* u) {
	count++;
	return alienSoldierList.enqueue(u);
}
bool AlienSoldierList::remove(unit*& u) {
	if (alienSoldierList.dequeue(u))
		count--;
	else return 0;
	return 1;
}
void AlienSoldierList::print() {
	LinkedQueue<unit*> l1;
	unit* u;
	if (!l1.isEmpty()) {

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
}

int AlienSoldierList::getCount()
{
	return count;
}

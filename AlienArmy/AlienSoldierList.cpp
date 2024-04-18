#include "AlienSoldierList.h"

AlienSoldierList::AlienSoldierList()
{
	count = 0;
}

AlienSoldierList::~AlienSoldierList()
{
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
	LinkedQueue<unit*> tempList;
	unit* tempSoldier;

	cout << getCount() << " AS [";
	while (alienSoldierList.dequeue(tempSoldier)) {
		cout << tempSoldier->get_id();
		tempList.enqueue(tempSoldier);
		if (!alienSoldierList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (tempList.dequeue(tempSoldier))
			alienSoldierList.enqueue(tempSoldier);
}

int AlienSoldierList::getCount()
{
	return count;
}
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
		return 0;
	}
	return 1;
}
void AlienSoldierList::print() {
	LinkedQueue<AlienSoldier*> tempList;
	AlienSoldier* tempSoldier;

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
	cout << "_____________________________________________________\n";

	while (tempList.dequeue(tempSoldier))
			alienSoldierList.enqueue(tempSoldier);
}

int AlienSoldierList::getCount()
{
	return count;
}
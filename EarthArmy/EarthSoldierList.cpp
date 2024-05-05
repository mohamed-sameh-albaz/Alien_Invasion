#include "EarthSoldierList.h"

EarthSoldierList::EarthSoldierList() {
	count = 0;
}
EarthSoldierList::~EarthSoldierList()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}
bool EarthSoldierList::insert(EarthSoldier* u) {
	count++;
	return soldierList.enqueue(u);
}

bool EarthSoldierList::peek(EarthSoldier*& pickedUnit)
{
	return soldierList.peek(pickedUnit);
}

bool EarthSoldierList::remove(unit*& u) {
	EarthSoldier* a;
	if (soldierList.dequeue(a)) {
		u = a;
		count--;
	}
	else {
		return 0;
	}
	return 1;
}
void EarthSoldierList::print() {		
	LinkedQueue<EarthSoldier*> tempList;
	EarthSoldier* u;
	cout << getCount() << " ES [";
	while (soldierList.dequeue(u)) {
		cout << u->get_id();
		tempList.enqueue(u);
		if (!soldierList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";

	while (tempList.dequeue(u))
		soldierList.enqueue(u);

}
int EarthSoldierList::getCount()
{
	return count;
}
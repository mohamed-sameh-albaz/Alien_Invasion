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
bool EarthSoldierList::remove(unit*& u) {
	EarthSoldier* a;
	if (soldierList.dequeue(a)) {
		u = a;
		count--;
	}
	else {
		u = a;
		return 0;
	}
	return 1;
}
void EarthSoldierList::print() {		//change output form
	LinkedQueue<EarthSoldier*> l1;
	EarthSoldier* u;
	cout << getCount() << " ES [";
	while (soldierList.dequeue(u)) {
		cout << u->get_id();
		//cout << endl << "______________________" << endl;
		l1.enqueue(u);
		if (!soldierList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (l1.dequeue(u))
		soldierList.enqueue(u);

}
int EarthSoldierList::getCount()
{
	return count;
}
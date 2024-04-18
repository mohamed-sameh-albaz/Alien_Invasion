#include "EarthSoldierList.h"

EarthSoldierList::EarthSoldierList() {
	count = 0;
}
EarthSoldierList::~EarthSoldierList()
{
}
bool EarthSoldierList::insert(unit* u) {
	count++;
	return soldierList.enqueue(u);
}
bool EarthSoldierList::remove(unit*& u) {

	if (soldierList.dequeue(u))
		count--;
	else return 0;
	return 1;
}
void EarthSoldierList::print() {
	LinkedQueue<unit*> l1;
	unit* u;
	cout << getCount() << " ES [";
	while (soldierList.dequeue(u)) {
		cout << u->get_id();
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
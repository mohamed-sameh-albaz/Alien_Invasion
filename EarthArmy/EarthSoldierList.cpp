#include "EarthSoldierList.h"
#include<iostream>
using namespace std;
EarthSoldierList::EarthSoldierList() {
	count = 0;
}
bool EarthSoldierList::insert(unit*& u) {
	count++;
	return l.enqueue(u);
}
bool EarthSoldierList::remove(unit*& u) {

	if (l.dequeue(u))
		count--;
	else return 0;
	return 1;
}
void EarthSoldierList::print() {
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

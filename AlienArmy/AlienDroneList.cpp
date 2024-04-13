#include "AlienDroneList.h"
#include"../DS/QueueADT.h"
#include<iostream>
#include <print>
using namespace std;
AlienDroneList::AlienDroneList() {
	count = 0;
}
bool AlienDroneList:: RemoveEnd(unit*& u) {

	if (l.dequeueBack(u))
		count--;
	else return 0;
	return 1;

}
bool AlienDroneList::RemoveFront(unit*& u) {
	if (l.dequeue(u))
		count--;
	else return 0;
	return 1;
}
bool AlienDroneList::InsertEnd(unit*& u) {
	count++;
	return l.enqueue(u);


}
bool AlienDroneList::insertFront(unit*& u) {
	count++;
	return l.enqueueFront(u);


}

void AlienDroneList::print() {
	double_endedQueue<unit*> l1;
	unit* u;
	while (l.dequeue(u)) {
		u->disp();
		cout << endl << "______________________" << endl;
		l1.enqueue(u);
	}

	while (l1.dequeue(u))
		l.enqueue(u);

}
int AlienDroneList::getCount() {
	return count;
}
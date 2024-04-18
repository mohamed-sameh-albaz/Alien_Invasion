#include "AlienDroneList.h"

AlienDroneList::AlienDroneList() {
	count = 0;
}
AlienDroneList::~AlienDroneList()
{
	unit* A;
	while (removeFront(A)) {
		delete A;
		A = nullptr;
	}
}
bool AlienDroneList:: removeEnd(unit*& u) {
	AlienDrone* a;

	if (droneList.dequeueBack(a)) {
		count--;
		u = a;
	}
	else { 
		u = a;
		return 0;
	
	}
	return 1;

}
bool AlienDroneList::removeFront(unit*& u) {

	AlienDrone* a;
	if (droneList.dequeue(a)) {
		u = a;
		count--;
	}
	else {
		u = a;
		return 0;
	

	}
	return 1;
}
bool AlienDroneList::insertEnd(AlienDrone* u) {
	count++;
	return droneList.enqueue(u);


}
bool AlienDroneList::insertFront(AlienDrone* u) {
	count++;
	return droneList.enqueueFront(u);


}

void AlienDroneList::print() {   //change output form
	double_endedQueue<AlienDrone*> l1;
	AlienDrone* u;

	cout << getCount() << " AD [";
	while (droneList.dequeue(u)) {
		cout << u->get_id();
		//cout << endl << "______________________" << endl;
		l1.enqueue(u);
		if (!droneList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (l1.dequeue(u))
		droneList.enqueue(u);

}
int AlienDroneList::getCount() {
	return count;
}
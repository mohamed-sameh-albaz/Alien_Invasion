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
		return 0;
		}
	return 1;
}
bool AlienDroneList::insertEnd(AlienDrone* u) {
	count++;
	return droneList.enqueue(u);
}
bool AlienDroneList::peekFront(unit*& u)
{
	AlienDrone* peekeddrone = nullptr;
	if (droneList.peekFront(peekeddrone))
		u = peekeddrone;
	return u;
}
bool AlienDroneList::peekBack(unit*& u)
{
	AlienDrone* peekeddrone = nullptr;
	if (droneList.peekBack(peekeddrone))
		u = peekeddrone;
	return u;
}

bool AlienDroneList::insertFront(AlienDrone* u) {
	count++;
	return droneList.enqueueFront(u);
}

void AlienDroneList::print() {
	double_endedQueue<AlienDrone*> tempList;
	AlienDrone* tempDrone;

	cout <<" "<< getCount() << " AD [";
	while (droneList.dequeue(tempDrone)) {
		cout << tempDrone->get_id();
		tempList.enqueue(tempDrone);
		if (!droneList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";

	while (tempList.dequeue(tempDrone))
		droneList.enqueue(tempDrone);
}
int AlienDroneList::getCount() 
{
	return count;
}
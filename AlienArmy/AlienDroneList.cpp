#include "AlienDroneList.h"

AlienDroneList::AlienDroneList() {
	count = 0;
}
AlienDroneList::~AlienDroneList()
{
}
bool AlienDroneList:: RemoveEnd(unit*& u) {

	if (droneList.dequeueBack(u))
		count--;
	else return 0;
	return 1;

}
bool AlienDroneList::RemoveFront(unit*& u) {
	if (droneList.dequeue(u))
		count--;
	else return 0;
	return 1;
}
bool AlienDroneList::InsertEnd(unit* u) {  
	count++;
	return droneList.enqueue(u);
}
bool AlienDroneList::insertFront(unit* u) {  
	count++;
	return droneList.enqueueFront(u);
}

void AlienDroneList::print() {
	double_endedQueue<unit*> tempList;
	unit* tempDrone;

	cout << getCount() << " AD [";
	while (droneList.dequeue(tempDrone)) {
		cout << tempDrone->get_id();
		tempList.enqueue(tempDrone);
		if (!droneList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (tempList.dequeue(tempDrone))
		droneList.enqueue(tempDrone);
}
int AlienDroneList::getCount() 
{
	return count;
}
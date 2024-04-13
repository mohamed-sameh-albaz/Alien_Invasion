#include "AlienDroneList.h"

AlienDroneList::AlienDroneList() {
	count = 0;
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

void AlienDroneList::print() {   //change output form
	double_endedQueue<unit*> l1;
	unit* u;

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
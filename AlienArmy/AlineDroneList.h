#pragma once
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"../DS/Node.h"

class AlineDroneList 
{
	double_endedQueue<unit*> l;

public:
	bool RemoveEnd(unit*&u) {
		
		return l.dequeueBack(u);
		
		
	}
bool RemoveFront(unit*& u) {

	return l.dequeue(u);
}
bool InsertEnd(unit*& u) {
	
	return l.enqueue(u);


}
bool insertFront(unit* &u) {

	return l.enqueueFront(u);


}

	void print() {
		double_endedQueue<unit*> l1;
		unit* u;
		while (l.dequeue(u)) {
			u->disp();
			cout << endl << "______________________"<<endl;
			l1.enqueue(u);
		}

		while (l1.dequeue(u))
			l.enqueue(u);

	}
};


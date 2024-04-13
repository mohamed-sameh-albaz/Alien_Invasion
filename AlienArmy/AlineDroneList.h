#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/double_endedQueue.h"
#include"../DS/Node.h"
#include"AlienDrone.h" //including drone
using namespace std;

class AlineDroneList
{
	double_endedQueue<unit*> droneList; //change list name
	int count;
public:
	AlineDroneList() { count = 0;
	}
	bool RemoveEnd(unit*& u) {

		if (droneList.dequeueBack(u))
			count--;
		else return 0;
		return 1;

	}
	bool RemoveFront(unit*& u) {
		if (droneList.dequeue(u))
			count--;
		else return 0;
		return 1;
	}
	bool InsertEnd(unit* u) { //remove refrence
		count++;
		return droneList.enqueue(u);


	}
	bool insertFront(unit* u) { //remove refrence
		count++;
		return droneList.enqueueFront(u);


	}

	void print() {   //change output form
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
	int getCount() {
		return count;
	}
};


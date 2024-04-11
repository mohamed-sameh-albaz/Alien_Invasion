#pragma once
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"

class AlineDroneList :   public LinkedQueue<unit*>
{
public:
	bool dequeueBack(unit*u) {
		if (isEmpty())
			return false;
		if (frontPtr == backPtr)
			dequeue(u);
		else {
			Node<unit*>* temp = frontPtr;
			while (temp->getNext() != backPtr)
				temp = temp->getNext();
			u = backPtr->getItem();
			/*Node<unit*>* dellptr = backPtr;
			delete dellptr;
			dellptr = nullptr;*/
			backPtr = temp;
		}
		return true;
		
	}
	void disp() {
		if (isEmpty())
			return;

		Node<unit*>* temp = frontPtr;
		while (temp!=backPtr) {
			temp->getItem()->disp();
			cout << "\n\n";
			temp = temp->getNext();

		}
		backPtr->getItem()->disp();
		cout << "\n\n";
		

	}
};


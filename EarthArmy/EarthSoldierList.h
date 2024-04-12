#pragma once
#include "../unit.h"
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"../DS/Node.h"
#include"EarthSoldier.h"
class EarthSoldierList :public LinkedQueue<unit*>
{
	
	void disp() {
		if (isEmpty())
			return;

		Node<unit*>* temp = frontPtr;
		while (temp != backPtr) {
			temp->getItem()->disp();
			cout << "\n\n";
			temp = temp->getNext();

		}
		backPtr->getItem()->disp();
		cout << "\n\n";
	}
	
};

#include "QueueList.h"

QueueList::QueueList():count(0)
{
}

QueueList::~QueueList()
{
	LinkedQueue::~LinkedQueue();
}

int QueueList::getCount()
{
	return count;
}

bool QueueList::insert(unit* newUnit)
{
	count++;
	return enqueue(newUnit);
}

bool QueueList::peek(unit*& frontUnit)
{
	return LinkedQueue::peek(frontUnit);
}

bool QueueList::remove(unit*& removedUnit)
{
	if (dequeue(removedUnit))
	{
		count--;
		return true;
	}
	return false;
}

void QueueList::print(type unitType)
{
	Node<unit*>* nextUnit = frontPtr;
	cout << " " << count;
	switch (unitType)
	{
	case ES:cout << " ES [";
		break;
	case AS:cout << " AS [";
		break;
	case saver:cout << " SU [";
		break;
	case Dead:cout << " units [";//killed list
		break;
	case saver:cout << " SU [";
	}
	while (nextUnit)
	{
		if (nextUnit->getItem()->get_type() == ES) {
			unit* IES = nextUnit->getItem();	//Infected Earth Soldier
			EarthSoldier* toBePrinted = dynamic_cast<EarthSoldier*>(IES);
			if (toBePrinted->isInfected()) {
				cout << "#";
			}
		}
		cout << nextUnit->getItem()->get_id();
		if (nextUnit->getNext())
			cout << ", ";
		nextUnit = nextUnit->getNext();
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";
}


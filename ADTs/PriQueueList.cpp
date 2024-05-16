#include "PriQueueList.h"

PriQueueList::PriQueueList() :count(0)
{
}

PriQueueList::~PriQueueList()
{
	priQueue::~priQueue();
}

int PriQueueList::getCount()
{
	return count;
}

bool PriQueueList::insert(unit* addedUnit, int priority)
{
	if (enqueue(addedUnit, priority))
	{
		count++;
		return true;
	}
	return false;
}

bool PriQueueList::peek(unit*& peekedUnit)
{
	int pri;
	return priQueue::peek(peekedUnit, pri);
}

bool PriQueueList::remove(unit*& pickedUnit)
{
	int pri;
	if (dequeue(pickedUnit, pri))
	{
		count--;
		return true;
	}
	return false;
}

void PriQueueList::print()
{
	int pri;
	priNode<unit*>* nextUnit = head;
	cout << " " << getCount() << " EG [";
	while (nextUnit)
	{
		cout << nextUnit->getItem(pri)->get_id();
		if (nextUnit->getNext())
			cout << ", ";
		nextUnit = nextUnit->getNext();
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";
}




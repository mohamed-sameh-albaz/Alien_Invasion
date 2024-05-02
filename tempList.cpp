#include "tempList.h"

tempList::tempList() :count(0)
{
}

tempList::~tempList()
{
	unit* A;
	while (list.dequeue(A)) {
		delete A;
		A = nullptr;
	}
}

bool tempList::insert(unit* tempunit)
{
	count++;
	return list.enqueue(tempunit);
}

bool tempList::remove(unit*& tempunit)
{
		if (list.dequeue(tempunit)) {
			count--;
			return 1;
		}
		return 0;
}

void tempList::print()
{
	LinkedQueue<unit*> temp;
	unit* tempUnit;
	cout << "\n============== Temp Units ==============" << endl;
	cout << count << " units [";
	while (!list.isEmpty())
	{
		list.dequeue(tempUnit);
		cout << tempUnit->get_id();
		temp.enqueue(tempUnit);
		if (!list.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (!temp.isEmpty())
	{
		temp.dequeue(tempUnit);
		list.enqueue(tempUnit);
	}
}
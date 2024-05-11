#include "killedList.h"

killedList::killedList():count(0)
{
}

killedList::~killedList()
{
	unit* A;
	while (deadList.dequeue(A)) {
		delete A;
		A = nullptr;
	}
}

bool killedList::insert(unit* killedUnit)
{
	count++;
	return deadList.enqueue(killedUnit);
}

bool killedList::remove(unit*& killedUnit)
{
	return deadList.dequeue(killedUnit);
}

void killedList::print()
{
	LinkedQueue<unit*> temp;
	unit* tempUnit;
	cout << "\n============== killed/Destructed Units ==============" << endl;
	cout << count << " units [";
	while (!deadList.isEmpty())
	{
		deadList.dequeue(tempUnit);
		cout << tempUnit->get_id();
		temp.enqueue(tempUnit);
		if (!deadList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;

	while (!temp.isEmpty())
	{
		temp.dequeue(tempUnit);
		deadList.enqueue(tempUnit);
	}
}
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

int tempList::getCount()
{
	return count;
}

void tempList::print(type attacker,int id )
{
	LinkedQueue<unit*> temp;
	unit* tempUnit;
	cout << "\n============== Units fighting at current step ==============" << endl;//must be changed with current step 
	switch (attacker)
	{
	case EG:cout << " EG ";
		break;
	case ES:cout << " ES ";
		break;

	case ET:cout << " ET ";
		break;

	case AS:cout << " AS ";
		break;

	case AD:cout << " AD ";
		break;

	case AM:cout << " AM ";
		break;
	}
	cout << id << " shots [";
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
#include "StackList.h"

StackList::StackList():count(0)
{
}

StackList::~StackList()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}

int StackList::getCount()
{
	return count;
}

bool StackList::insert(unit* newUnit)
{
	count++;
	return push(newUnit);
}

bool StackList::peek(unit*& frontUnit)
{
	return ArrayStack::peek(frontUnit);
}

bool StackList::remove(unit*& removedUnit)
{
	if (pop(removedUnit))
	{
		count--;
		return true;
	}
	return false;
}

void StackList::print(type unitType)
{
	int topUnit = count - 1;
	cout << " " << count;
	switch (unitType)
	{
	case ET:cout << " ET [";
		break;
	case EH:cout << " EH [";
		break;
	}
	for (int i = topUnit; i >= 0; i--)
	{
		cout << items[i]->get_id();
		if (i > 0)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	cout << "_____________________________________________________\n";
}
#include "EarthTankList.h"

EarthTankList::EarthTankList() :count(0)
{
}
EarthTankList::~EarthTankList()
{
	unit* A;
	while (remove(A)) {
		delete A;
		A = nullptr;
	}
}
bool EarthTankList::insert(EarthTank* newTank)
{
	if (tankList.push(newTank))
	{
		count++;
		return true;
	}
	return false;
}
bool EarthTankList::remove(unit*& deletedTank)
{
	EarthTank* removedTank;
	if (tankList.pop(removedTank))
	{
		deletedTank = removedTank;
		count--;
		return true;
	}
	return false;
}

int EarthTankList::getCount()
{
	return count;
}

void EarthTankList::print()
{
	ArrayStack<EarthTank*>tempList;
	EarthTank* tempTank;
	cout << getCount() << " ET [";
	while (!tankList.isEmpty())
	{
		tankList.pop(tempTank);
		cout << tempTank->get_id();
		tempList.push(tempTank);
		if (!tankList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	while (!tempList.isEmpty())
	{
		tempList.pop(tempTank);
		tankList.push(tempTank);
	}
}

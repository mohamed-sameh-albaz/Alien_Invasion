#include "EarthGunList.h"

EarthGunList::EarthGunList() :count(0)
{
}
EarthGunList::~EarthGunList()
{
	unit* a;
	int x;
	while (remove(a,x)) {
		delete a;
		a = nullptr;
	}

}
bool EarthGunList::insert(EarthGun* newGun)
{
	int priority = newGun->get_health() + newGun->get_power();
	if (GunList.enqueue(newGun, priority))
	{
		count++;
		return true;
	}
	return false;
}
bool EarthGunList::remove(unit*& deletedUnit, int& deletedPri)
{
	EarthGun* pickedGun;
	int pri;
	if (GunList.dequeue(pickedGun, pri))
	{
		deletedUnit = pickedGun;
		count--;
		deletedPri = pri;
		return true;
	}
	return false;
}

int EarthGunList::getCount()
{
	return count;
}

void EarthGunList::print()
{
	priQueue<EarthGun*> tempList;
	EarthGun* tempGun;
	int pri;
	cout << getCount() << " EG [";
	while (!GunList.isEmpty())
	{
		GunList.dequeue(tempGun, pri);
		cout << tempGun->get_id();
		tempList.enqueue(tempGun, pri);
		if (!GunList.isEmpty())
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
	while (!tempList.isEmpty())
	{
		tempList.dequeue(tempGun, pri);
		GunList.enqueue(tempGun, pri);
	}
}
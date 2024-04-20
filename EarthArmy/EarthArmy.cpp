#include "EarthArmy.h"
EarthArmy::EarthArmy()
{
	GunneryList = new EarthGunList;
	soldierList = new EarthSoldierList;
	tankList = new EarthTankList;
}

EarthArmy::~EarthArmy()
{
	delete GunneryList;
	delete soldierList;
	delete tankList;
	GunneryList = nullptr;
	soldierList = nullptr;
	tankList = nullptr;
}

bool EarthArmy::addUnit(unit* newUnit)
{
	
	if (newUnit)
	{
		type unitType = newUnit->get_type();
		switch (unitType)
		{
		case EG:	return GunneryList->insert(dynamic_cast<EarthGun*>(newUnit));
		case ES:	return soldierList->insert(dynamic_cast<EarthSoldier*>(newUnit));
		case ET:	return tankList->insert(dynamic_cast<EarthTank*>(newUnit));
		}
	}
	else return false;
}

bool EarthArmy::insertTemp(unit* tempUnit)
{
	return tempList.enqueue(tempUnit);
}

bool EarthArmy::removeTemp(unit*& tempUnit)
{
	return tempList.dequeue(tempUnit);
}

bool EarthArmy::pickGun(unit*& pickedGun, int& pri)
{
	return (GunneryList->remove(pickedGun, pri));
}

bool EarthArmy::pickTank(unit*& pickedTank)
{
	return(tankList->remove(pickedTank));
}

bool EarthArmy::pickSoldier(unit*& pickedSoldier)
{
	return(soldierList->remove(pickedSoldier));
}

void EarthArmy::print()
{
	cout << "============== Earth Army Alive Units ==============" << endl;
	soldierList->print();
	tankList->print();
	GunneryList->print();
}

void EarthArmy::attack()
{
}

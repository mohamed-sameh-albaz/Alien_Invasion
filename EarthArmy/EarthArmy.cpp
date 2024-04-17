#include "EarthArmy.h"
EarthArmy::EarthArmy()
{
	GunneryList = new EarthGunList;
	soldierList = new EarthSoldierList;
	tankList = new EarthTankList;
}

EarthArmy::~EarthArmy()
{
}

bool EarthArmy::addUnit(unit*& newUnit)
{
	if (newUnit) {

		string type = newUnit->get_type(); //if enum use switch
		if (type == "Gunnery")
		{
			return GunneryList->insert(dynamic_cast<EarthGun*>(newUnit));
		}
		if (type == "soldier")
		{
			return soldierList->insert(dynamic_cast<EarthSoldier*>(newUnit));//ref --> initial value of reference to non-const must be an lvalue
		}
		if (type == "tank")
		{
			return tankList->insert(dynamic_cast<EarthTank*>(newUnit));
		}
	}
	else return false;
}

bool EarthArmy::insertTemp(unit*& tempUnit)
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

//pick healer//

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

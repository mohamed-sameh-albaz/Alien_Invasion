#include "EarthArmy.h"
EarthArmy::EarthArmy()
{
	GunneryList = new EarthGunList;
	soldierList = new QueueList;
	tankList = new EarthTankList;
	healers = new HL;
}

EarthArmy::~EarthArmy()
{
	delete GunneryList;
	delete soldierList;
	delete tankList;
	delete healers;
	healers = nullptr;
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
		case ES:	return soldierList->insert(/*dynamic_cast<EarthSoldier*>*/(newUnit));
		case ET:	return tankList->insert(dynamic_cast<EarthTank*>(newUnit));
		case EH:	return healers->insert(dynamic_cast<Healer*>(newUnit));
		}
	}
	else return false;
}

bool EarthArmy::pickGun(unit*& pickedGun)
{
	return (GunneryList->remove(pickedGun));
}

bool EarthArmy::pickTank(unit*& pickedTank)
{
	return(tankList->remove(pickedTank));
}

EarthGunList* EarthArmy::get_GunneryList()
{
	return GunneryList;
}

QueueList* EarthArmy::get_soldierList()
{
	return soldierList;
}

EarthTankList* EarthArmy::get_tankList()
{
	return tankList;
}

bool EarthArmy::pickSoldier(unit*& pickedSoldier)
{
	return(soldierList->remove(pickedSoldier));
}

bool EarthArmy::pickHealer(unit*& pickedHealer)
{
	return (healers->remove(pickedHealer));
}

bool EarthArmy::peekGun(unit*& peekedGun)
{
	return GunneryList->peek(peekedGun);
}

bool EarthArmy::peekTank(unit*& peekedTank)
{
	return tankList->peek(peekedTank);
}

bool EarthArmy::peekSoldier(unit*& peekedSoldier)
{
	return soldierList->peek(peekedSoldier);
}

void EarthArmy::print()
{
	cout << "============== Earth Army Alive Units ==============" << endl;
	soldierList->print(ES);
	tankList->print();
	GunneryList->print();
	healers->print();
}

void EarthArmy::attack()
{
	unit* attackingSol = nullptr;
	unit* attackingGun = nullptr;
	unit* attackingTank = nullptr;
	unit* attackingHealer = nullptr;
	peekSoldier(attackingSol);//pick doesnot remove the unit from its original list
	if (attackingSol)
		attackingSol->attack();
	peekTank(attackingTank);
	if (attackingTank)
		attackingTank->attack();
	peekGun(attackingGun);
	if (attackingGun)
		attackingGun->attack();
	pickHealer(attackingHealer);
	if (attackingHealer) {
		attackingHealer->attack();
		dynamic_cast<Healer*>(attackingHealer)->suicide();
	}
}

int EarthArmy::getListCnt(type neededUnit)
{
	switch (neededUnit)
	{
	case(ES):return soldierList->getCount();
	case(ET):return tankList->getCount();
	case(EG):return GunneryList->getCount();
	}
}

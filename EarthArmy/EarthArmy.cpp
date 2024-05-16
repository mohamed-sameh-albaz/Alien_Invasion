#include "EarthArmy.h"
EarthArmy::EarthArmy()
{
	GunneryList = new PriQueueList;
	soldierList = new QueueList;
	tankList = new  StackList;
	healers = new  StackList;
	SaverList = new QueueList;
	infectedCount = 0;
}

EarthArmy::~EarthArmy()
{
	delete GunneryList;
	delete soldierList;
	delete tankList;
	delete healers;
	delete SaverList;
	healers = nullptr;
	GunneryList = nullptr;
	soldierList = nullptr;
	tankList = nullptr;
	SaverList = nullptr;
}

bool EarthArmy::addUnit(unit* newUnit)
{
	
	if (newUnit)
	{
		type unitType = newUnit->get_type();
		switch (unitType)
		{
		case EG:	
		{
			int GunPri = newUnit->get_health() + newUnit->get_power();
			return GunneryList->insert(newUnit,GunPri);
		}
		case ES:	return soldierList->insert(newUnit);
		case ET:	return tankList->insert(newUnit);
		case EH:	return healers->insert(newUnit);
		case saver:	return SaverList->insert(newUnit);
		}
	}
	return false;
}

bool EarthArmy::pickGun(unit*& pickedGun)
{
	return (GunneryList->remove(pickedGun));
}

bool EarthArmy::pickTank(unit*& pickedTank)
{
	return(tankList->remove(pickedTank));
}

StackList* EarthArmy::get_healers()
{
	return healers;
}

PriQueueList* EarthArmy::get_GunneryList()
{
	return GunneryList;
}

QueueList* EarthArmy::get_soldierList()
{
	return soldierList;
}

StackList* EarthArmy::get_tankList()
{
	return tankList;
}

void EarthArmy::setInfectedCount(int infectedCnt)
{
	infectedCount = infectedCnt;
}

int EarthArmy::getInfectedCount()
{
	return infectedCount;
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

bool EarthArmy::peekHealer(unit*& peekedHealer)
{
	return healers->peek(peekedHealer);
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
	tankList->print(ET);
	GunneryList->print();
	healers->print(EH);
}

void EarthArmy::attack()
{
	unit* attackingSol = nullptr;
	unit* attackingGun = nullptr;
	unit* attackingTank = nullptr;
	peekSoldier(attackingSol);//pick does not remove the unit from its original list
	if (attackingSol)
		attackingSol->attack();
	peekTank(attackingTank);
	if (attackingTank)
		attackingTank->attack();
	peekGun(attackingGun);
	if (attackingGun)
		attackingGun->attack();

}

void EarthArmy::heal()
{
	unit* attackingHealer = nullptr;
	peekHealer(attackingHealer);
	if (attackingHealer) {
		attackingHealer->attack();
	}
}

int EarthArmy::getListCnt(type neededUnit)
{
	switch (neededUnit)
	{
	case(ES):return soldierList->getCount();
	case(ET):return tankList->getCount();
	case(EG):return GunneryList->getCount();
	case(saver):return SaverList->getCount();
	}
}

#include "AlienArmy.h"
AlienArmy::AlienArmy()
{
	droneList = new DEQueueList;
	soldierList = new QueueList;
	monsterList = new MonsterList;
}
AlienArmy::~AlienArmy()
{
	delete droneList;
	delete soldierList;
	delete monsterList;
	droneList = nullptr;
	soldierList = nullptr;
	monsterList = nullptr;
}

bool AlienArmy::addUnit(unit* newUnit)
{
	if(newUnit)
	{
		type unitType = newUnit->get_type();
		switch (unitType)
		{
		case AS:	return soldierList->insert(newUnit);
		case AM:	return monsterList->insert(dynamic_cast<monster*>(newUnit));
		case AD:	return droneList->insertEnd(newUnit);
		}
	}
	return false;
}

DEQueueList* AlienArmy::get_droneList()
{
	return droneList;
}

QueueList* AlienArmy::get_soldierList()
{
	return soldierList;
}

MonsterList* AlienArmy::get_monsterList()
{
	return monsterList;
}

bool AlienArmy::peekSoldier(unit*& peekedUnit)
{
	return soldierList->peek(peekedUnit);
}

bool AlienArmy::peekFrontDrone(unit*& peekedUnit)
{
	return droneList->frontPeek(peekedUnit);
}

bool AlienArmy::peekBackDrone(unit*& peekedUnit)
{
	return (getListCnt(AD) > 1) ? droneList->peekBack(peekedUnit) : false;
}

bool AlienArmy::peekMonster(unit*& peekedUnit)
{
	return monsterList->peek(peekedUnit);
}

bool AlienArmy::pickFrontDrone(unit*& pickedDrone)
{
	return (droneList->removeFront(pickedDrone));
}

bool AlienArmy::pickEndDrone(unit*& pickedDrone)
{
	return (getListCnt(AD) > 1) ? droneList->removeEnd(pickedDrone) : false;
}

bool AlienArmy::pickSoldier(unit*& pickedSoldier)
{
	return (soldierList->remove(pickedSoldier));
}

bool AlienArmy::pickMonster(unit*& pickedMonster)
{
	return(monsterList->remove(pickedMonster));

}

void AlienArmy::print()
{
	cout << "\n============== Alien Army Alive Units ==============" << endl;
	soldierList->print(AS);
	monsterList->print();
	droneList->print();
}

void AlienArmy::attack()
{
	unit *attackingSol=nullptr;
	unit *attackingMo=nullptr;
	unit *attackingFDrone=nullptr;
	unit *attackingBDrone=nullptr;

	if (peekSoldier(attackingSol))
		attackingSol->attack();
	if (peekMonster(attackingMo))
		attackingMo->attack();
	if (peekFrontDrone(attackingFDrone))
		attackingFDrone->attack();
	if (peekBackDrone(attackingBDrone))
		attackingBDrone->attack();
}

int AlienArmy::getListCnt(type neededUnit)
{
	switch (neededUnit)
	{
	case(AS):return soldierList->getCount();
	case(AD):return droneList->getCount();
	case(AM):return monsterList->getCount();
	}
}

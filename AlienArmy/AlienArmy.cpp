#include "AlienArmy.h"
#include"../tempList.h"
AlienArmy::AlienArmy()
{
	droneList = new AlienDroneList;
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
		case AS:	return soldierList->insert(dynamic_cast<AlienSoldier*>(newUnit));
		case AM:	return monsterList->insert(dynamic_cast<monster*>(newUnit));
		case AD:	return droneList->insertEnd(dynamic_cast<AlienDrone*>(newUnit));
		}
	}
	else return false;
}

AlienDroneList* AlienArmy::get_droneList()
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

bool AlienArmy::peeksoldier(unit*& pickedunit)
{
	return soldierList->peek(pickedunit);
}

bool AlienArmy::peekFrontdrone(unit*& pickedunit)
{
	return droneList->peekFront(pickedunit);
}

bool AlienArmy::peekbackdrone(unit*& pickedunit)
{
	return droneList->peekBack(pickedunit);
}

bool AlienArmy::peekmonster(unit*& pickedunit)
{
	return monsterList->peek(pickedunit);
}

bool AlienArmy::pickFrontDrone(unit*& pickedDrone)
{
	return (droneList->removeFront(pickedDrone));
}

bool AlienArmy::pickEndDrone(unit*& pickedDrone)
{
	return (droneList->removeEnd(pickedDrone));
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

	if (peeksoldier(attackingSol))
		attackingSol->attack();
	if (peekmonster(attackingMo))
		attackingMo->attack();
	if (peekFrontdrone(attackingFDrone))
		attackingFDrone->attack();
	if (peekbackdrone(attackingBDrone))
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

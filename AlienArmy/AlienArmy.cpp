#include "AlienArmy.h"
#include"../tempList.h"
AlienArmy::AlienArmy()
{
	droneList = new AlienDroneList;
	soldierList = new AlienSoldierList;
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

AlienSoldierList* AlienArmy::get_soldierList()
{
	return soldierList;
}

MonsterList* AlienArmy::get_monsterList()
{
	return monsterList;
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
	soldierList->print();
	monsterList->print();
	droneList->print();
}

void AlienArmy::attack()
{
	tempList temp;
	unit *attacker;
	if (pickSoldier(attacker))
		attacker->attack();
	if (pickMonster(attacker))
		attacker->attack();

	if (pickFrontDrone(attacker))
		attacker->attack();
	if (pickEndDrone(attacker))
		attacker->attack();

	
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

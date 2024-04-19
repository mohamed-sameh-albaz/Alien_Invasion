#include "AlienArmy.h"

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
	type unitType = newUnit->get_type();
	
	if(newUnit)
	{
		switch (unitType)
		{
		case AS:	return soldierList->insert(dynamic_cast<AlienSoldier*>(newUnit));
		case AM:	return monsterList->insert(dynamic_cast<monster*>(newUnit));
		case AD:	return droneList->insertEnd(dynamic_cast<AlienDrone*>(newUnit));
		}
	}
	else return false;
}

bool AlienArmy::insertTemp(unit* tempUnit)
{
	return tempList.enqueue(tempUnit);
}

bool AlienArmy::removeTemp(unit*& tempUnit)
{
	return tempList.dequeue(tempUnit);
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
}

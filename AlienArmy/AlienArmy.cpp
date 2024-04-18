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

bool AlienArmy::addUnit(unit*& newUnit)
{
	if (newUnit) {
		string type = newUnit->get_type(); //if enum use switch
		if (type == "alienDrone")
		{
			return droneList->InsertEnd(dynamic_cast<AlienDrone*>(newUnit));//ref --> initial value of reference to non-const must be an lvalue
		}
		if (type == "alienSoldier")
		{
			return soldierList->insert(dynamic_cast<AlienSoldier*>(newUnit));//ref --> initial value of reference to non-const must be an lvalue
		}
		if (type == "monster")
		{
			return monsterList->insert(dynamic_cast<monster*>(newUnit));
		}
	}
	else return false;
}

bool AlienArmy::insertTemp(unit*& tempUnit)
{
	return tempList.enqueue(tempUnit);
}

bool AlienArmy::removeTemp(unit*& tempUnit)
{
	return tempList.dequeue(tempUnit);
}

bool AlienArmy::pickFrontDrone(unit*& pickedDrone)
{
	return (droneList->RemoveFront(pickedDrone));
}

bool AlienArmy::pickEndDrone(unit*& pickedDrone)
{
	return (droneList->RemoveEnd(pickedDrone));
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

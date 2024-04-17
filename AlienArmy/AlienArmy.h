#pragma once
#include"../unit.h"
#include"AlienDroneList.h"
#include"AlienSoldierList.h"
#include"MonsterList.h"

class AlienArmy
{
	AlienDroneList * droneList;
	AlienSoldierList * soldierList;
	MonsterList * monsterList;
	LinkedQueue<unit*> tempList;
public:
	AlienArmy()
	{
		droneList = new AlienDroneList;
		soldierList = new AlienSoldierList;
		monsterList = new MonsterList;
	}
	~AlienArmy()
	{
	}

	bool addUnit(unit*& newUnit)
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

	bool insertTemp(unit*& tempUnit)
	{
		return tempList.enqueue(tempUnit);
	}

	bool removeTemp(unit*& tempUnit)
	{
			return tempList.dequeue(tempUnit);
	}

	bool pickFrontDrone(unit*& pickedDrone)
	{
		return (droneList->RemoveFront(pickedDrone));
	}

	bool pickEndDrone(unit*& pickedDrone)
	{
		return (droneList->RemoveEnd(pickedDrone));
	}

	bool pickSoldier(unit*& pickedSoldier) 
	{
		return (soldierList->remove(pickedSoldier));
	}

	bool pickMonster(unit*& pickedMonster)
	{
		return(monsterList->remove(pickedMonster));

	}

	void print()
	{
		cout << "\n============== Alien Army Alive Units ==============" << endl;
		soldierList->print();
		monsterList->print();
		droneList->print();
	}

	void attack()
	{
	}
};


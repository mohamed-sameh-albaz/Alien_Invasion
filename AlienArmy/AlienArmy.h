#pragma once
#include"../unit.h"
#include"AlineDroneList.h"
#include"AlineSoldierList.h"
#include"MonsterList.h"

class AlienArmy
{
	AlineDroneList * droneList;
	AlineSoldierList * soldierList;
	MonsterList * monsterList;
	LinkedQueue<unit*> tempList;

	int tempListCnt;
public:
	AlienArmy() :tempListCnt(0)
	{
		droneList = new AlineDroneList;
		soldierList = new AlineSoldierList;
		monsterList = new MonsterList;
	}
	~AlienArmy()
	{
	}

	bool addUnit(unit*& newUnit)
	{
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

	bool insertTemp(unit*& tempUnit)
	{
		tempListCnt++;
		return tempList.enqueue(tempUnit);
	}

	bool removeTemp(unit*& tempUnit)
	{
		tempListCnt--;
		return tempList.dequeue(tempUnit);
	}

	bool pickFrontDrone(unit*& pickedDrone)
	{
		if(droneList->RemoveFront(pickedDrone))
		{
			return insertTemp(pickedDrone);
		}
		return false;
	}

	bool pickEndDrone(unit*& pickedDrone)
	{
		if(droneList->RemoveEnd(pickedDrone))
		{
			return insertTemp(pickedDrone);
		}
		return false;
	}

	bool pickSoldier(unit*& pickedSoldier) 
	{
		if(soldierList->remove(pickedSoldier))
		{
			return insertTemp(pickedSoldier);
		}
		return false;
	}

	bool pickMonster(unit*& pickedMonster)
	{
		if(monsterList->remove(pickedMonster))
		{
			return insertTemp(pickedMonster);
		}
		return false;
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


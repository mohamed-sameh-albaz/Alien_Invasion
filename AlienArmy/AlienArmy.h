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
public:
	AlienArmy();
	~AlienArmy();
	bool addUnit(unit* newUnit);
	bool pickFrontDrone(unit*& pickedDrone);
	bool pickEndDrone(unit*& pickedDrone);
	bool pickSoldier(unit*& pickedSoldier);
	bool pickMonster(unit*& pickedMonster);	
	void print();
	void attack();
	int getListCnt(type neededUnit);

};


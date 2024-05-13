#pragma once
#include"../unit.h"
#include"AlienDroneList.h"
#include"MonsterList.h"
#include"AlienSoldier.h"
#include"../ADTs/QueueList.h"
class AlienArmy
{
	AlienDroneList * droneList;
	QueueList * soldierList;
	MonsterList * monsterList;
public:
	AlienArmy();
	~AlienArmy();
	bool addUnit(unit* newUnit);
	AlienDroneList* get_droneList();
	QueueList* get_soldierList();
	MonsterList* get_monsterList();

	bool peeksoldier(unit*& pickedunit);
	bool peekFrontdrone(unit*& pickedunit);
	bool peekbackdrone(unit*& pickedunit);
	bool peekmonster(unit*& pickedunit);

	bool pickFrontDrone(unit*& pickedDrone);
	bool pickEndDrone(unit*& pickedDrone);
	bool pickSoldier(unit*& pickedSoldier);
	bool pickMonster(unit*& pickedMonster);	
	void print();
	void attack();
	int getListCnt(type neededUnit);

};


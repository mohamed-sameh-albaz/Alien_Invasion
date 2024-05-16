#pragma once
#include"../unit.h"
#include"MonsterList.h"
#include"../ADTs/QueueList.h"
#include"../ADTs/DEQeueueList.h"
class AlienArmy
{
	DEQueueList * droneList;
	QueueList * soldierList;
	MonsterList * monsterList;
public:
	AlienArmy();
	~AlienArmy();
	bool addUnit(unit* newUnit);
	DEQueueList* get_droneList();
	QueueList* get_soldierList();
	MonsterList* get_monsterList();

	bool peekSoldier(unit*& pickedunit);
	bool peekFrontDrone(unit*& pickedunit);
	bool peekBackDrone(unit*& pickedunit);
	bool peekMonster(unit*& pickedunit);
	bool pickFrontDrone(unit*& pickedDrone);
	bool pickEndDrone(unit*& pickedDrone);
	bool pickSoldier(unit*& pickedSoldier);
	bool pickMonster(unit*& pickedMonster);	
	void print();
	void attack();
	int getListCnt(type neededUnit);

};


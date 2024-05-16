#pragma once
#include"../unit.h"
#include "UML.h"
#include"../ADTs/QueueList.h"
#include"../ADTs/StackList.h"
#include"../ADTs/PriQueueList.h"
class EarthArmy
{
	QueueList* soldierList;
	QueueList* SaverList;
	PriQueueList * GunneryList;
	StackList* tankList;
	StackList* healers;
	int infectedCount;
public:
	EarthArmy();
	~EarthArmy();
	bool addUnit(unit* newUnit);
	bool pickGun(unit*& pickedGun);
	bool pickTank(unit*& pickedTank);
	StackList* get_healers();
	PriQueueList* get_GunneryList();
	QueueList* get_soldierList();
	StackList* get_tankList();
	void setInfectedCount(int infectedCnt);
	int getInfectedCount();
	bool pickSoldier(unit*& pickedSoldier);
	bool pickHealer(unit*& pickedHealer);
	bool peekGun(unit*& peekedGun);
	bool peekHealer(unit*& peekedHealer);
	bool peekTank(unit*& peekedTank);
	bool peekSoldier(unit*& peekedSoldier);
	void print();
	void attack();
	void heal();
	int getListCnt(type neededUnit);
};


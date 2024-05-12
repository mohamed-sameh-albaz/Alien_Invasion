#pragma once
#include"../unit.h"
#include"EarthGunList.h"
#include"EarthSoldierList.h"
#include"EarthTankList.h"
#include "HL.h"
#include "UML.h"
#include"../ADTs/QueueList.h"
#include"../ADTs/StackList.h"
class EarthArmy
{
	QueueList* soldierList;
	EarthGunList * GunneryList;
	StackList* tankList;
	StackList* healers;
public:
	EarthArmy();
	~EarthArmy();
	bool addUnit(unit* newUnit);
	bool pickGun(unit*& pickedGun);
	bool pickTank(unit*& pickedTank);
	EarthGunList* get_GunneryList();
	QueueList* get_soldierList();
	StackList* get_tankList();
	bool pickSoldier(unit*& pickedSoldier);
	bool pickHealer(unit*& pickedHealer);
	bool peekGun(unit*& peekedGun);
	bool peekTank(unit*& peekedTank);
	bool peekSoldier(unit*& peekedSoldier);
	void print();
	void attack();
	int getListCnt(type neededUnit);
};


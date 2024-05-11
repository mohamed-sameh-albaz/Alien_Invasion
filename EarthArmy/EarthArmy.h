#pragma once
#include"../unit.h"
#include"EarthGunList.h"
#include"EarthSoldierList.h"
#include"EarthTankList.h"
#include "HL.h"
#include "UML.h"

class EarthArmy
{
	EarthGunList * GunneryList;
	EarthSoldierList * soldierList;
	EarthTankList * tankList;
	HL* healers;
public:
	EarthArmy();
	~EarthArmy();
	bool addUnit(unit* newUnit);
	bool pickGun(unit*& pickedGun);
	bool pickTank(unit*& pickedTank);
	EarthGunList* get_GunneryList();
	EarthSoldierList* get_soldierList();
	EarthTankList* get_tankList();
	bool pickSoldier(unit*& pickedSoldier);
	bool pickHealer(unit*& pickedHealer);
	bool peekGun(unit*& peekedGun);
	bool peekTank(unit*& peekedTank);
	bool peekSoldier(unit*& peekedSoldier);
	void print();
	void attack();
	int getListCnt(type neededUnit);
};


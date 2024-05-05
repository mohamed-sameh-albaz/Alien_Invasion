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
	bool pickGun(unit*& pickedGun, int& pri);
	bool pickTank(unit*& pickedTank);
	bool pickSoldier(unit*& pickedSoldier);
	bool pickHealer(unit*& pickedHealer);
	void print();
	void attack();
	int getListCnt(type neededUnit);
};


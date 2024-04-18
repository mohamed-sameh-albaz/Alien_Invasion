#pragma once
#include"../unit.h"
#include"EarthGunList.h"
#include"EarthSoldierList.h"
#include"EarthTankList.h"

class EarthArmy
{
	EarthGunList * GunneryList;
	EarthSoldierList * soldierList;
	EarthTankList * tankList;
	LinkedQueue<unit*> tempList;
public:
	EarthArmy();
	~EarthArmy();
	bool addUnit(unit* newUnit);
	bool insertTemp(unit* tempUnit);
	bool removeTemp(unit*& tempUnit);
	bool pickGun(unit*& pickedGun, int& pri);
	bool pickTank(unit*& pickedTank);
	bool pickSoldier(unit*& pickedSoldier);
	void print();
	void attack();
};


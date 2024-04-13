#pragma once
#include"../unit.h"
#include"EarthGunList.h"
#include"EarthSoldierList.h"
#include"EarthTankList.h"

class EarthArmy
{
	//Army lists
	EarthGunList * GunneryList;
	EarthSoldierList * soldierList;
	EarthTankList * tankList;
		//healer list
	LinkedQueue<unit*> tempList;
	
	int tempListCnt;
public:
	EarthArmy():tempListCnt(0)
	{
		GunneryList = new EarthGunList;
		soldierList = new EarthSoldierList;
		tankList = new EarthTankList;
	}

	~EarthArmy()
	{
	}

	bool addUnit(unit*& newUnit)
	{
		string type = newUnit->get_type(); //if enum use switch
		if (type == "Gunnery")
		{
			return GunneryList->insert(dynamic_cast<EarthGun*>(newUnit));
		}
		if (type == "soldier")
		{
			return soldierList->insert(dynamic_cast<EarthSoldier*>(newUnit));//ref --> initial value of reference to non-const must be an lvalue
		}
		if (type == "tank")
		{
			return tankList->insert(dynamic_cast<EarthTank*>(newUnit));
		}
		//healer type
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

	bool pickGun(unit*& pickedGun ,int& pri) 
	{
		if(GunneryList->remove(pickedGun, pri))
		{
			return insertTemp(pickedGun);
		}
	}

	bool pickTank(unit*& pickedTank) 
	{
		if(tankList->remove(pickedTank))
		{
			return insertTemp(pickedTank);
		}
	}
	
	bool pickSoldier(unit*& pickedSoldier) 
	{
		if(soldierList->remove(pickedSoldier))
		{
			return insertTemp(pickedSoldier);
		}
		return false;
	}

	//pick healer//
	
	void print()
	{
		cout << "============== Earth Army Alive Units =============="<<endl;
		soldierList->print();
		tankList->print();
		GunneryList->print();
	}

	void attack()
	{
	}
};


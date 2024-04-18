#pragma once
#include<iostream>
#include"../unit.h"
#include"EarthGun.h"
#include"../DS/priQueue.h"
using namespace std;

class EarthGunList
{
	int count;
	priQueue<EarthGun*> GunList;

public:
	EarthGunList() ;
	~EarthGunList();

	bool insert(EarthGun* newGun);
	
	bool remove(unit*& deletedUnit, int& deletedPri);
	

	int getCount();
	

	void print();
	

	/*bool removeGunnery(EarthGun* deletedGun, int& deletedPri)
	{
		int priority;
		if (GunList.dequeue(deletedGun,priority))
		{
			num--;
			deletedPri = priority;
			return true;
		}
		return false;
	}*/
};


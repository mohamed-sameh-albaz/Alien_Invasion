#pragma once
#include"../unit.h"
#include"../EarthArmy/EarthGun.h"
#include"../DS/priQueue.h"
#include<iostream>
class EarthGunList
{
	int num;
	priQueue<EarthGun*> GunList;

public:
	EarthGunList() :num(0)
	{
	}
	bool addGunnery(EarthGun* newGun)
	{
		int priority = newGun->get_health() + newGun->get_power();
		if (GunList.enqueue(newGun,priority))
		{
			num++;
			//print();
			return true;
		}
		return false;
	}
	bool removeGunnery(EarthGun* deletedGun, int& deletedPri)
	{
		int priority;
		if (GunList.dequeue(deletedGun,priority))
		{
			num--;
			deletedPri = priority;
			return true;
		}
		return false;
	}
	bool pickGun(unit*& pickedUnit)
	{
		EarthGun* pickedGun;
		int pri;
		if (GunList.dequeue(pickedGun,pri))
		{
			pickedUnit = pickedGun;
			return true;
		}
		else
		{
			cout << "Cannot pick any units ,The List Is Empty" << endl;
			return false;
		}
	}
	void print()
	{
		if (GunList.isEmpty())
		{
			cout << "The List Is Empty" << endl;
			return;
		}
		priQueue<EarthGun*> tempList;
		EarthGun* tempGun;
		int pri;
		while (!GunList.isEmpty())
		{
			GunList.dequeue(tempGun, pri);
			tempGun->disp();
			cout << endl << "----------------------------" << endl;
			tempList.enqueue(tempGun, pri);
		}
		while (!tempList.isEmpty())
		{
			tempList.dequeue(tempGun, pri);
			GunList.enqueue(tempGun, pri);
		}
	}
};


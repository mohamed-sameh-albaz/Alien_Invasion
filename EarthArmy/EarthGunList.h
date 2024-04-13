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
	EarthGunList() :count(0)
	{
	}
	bool insert(EarthGun* newGun)
	{
		int priority = newGun->get_health() + newGun->get_power();
		if (GunList.enqueue(newGun,priority))
		{
			count++;
			return true;
		}
		return false;
	}
	bool remove(unit*& deletedUnit ,int& deletedPri)
	{
		EarthGun* pickedGun;
		int pri;
		if (GunList.dequeue(pickedGun,pri))
		{
			deletedUnit = pickedGun;
			count--;
			deletedPri = pri;
			return true;
		}
		else
		{
			cout << "Cannot pick any gunnery ,The List Is Empty" << endl;
			return false;
		}
	}

	int getCount()
	{
		return count;
	}

	void print()
	{
		//if (GunList.isEmpty())
		//{
		//	cout << "The gunnery List Is Empty" << endl;
		//	return;
		//}
		priQueue<EarthGun*> tempList;
		EarthGun* tempGun;
		int pri;
		cout << getCount() << " EG [";
		while (!GunList.isEmpty())
		{
			GunList.dequeue(tempGun, pri);
			cout << tempGun->get_id();
			//cout << endl << "----------------------------" << endl;
			tempList.enqueue(tempGun, pri);
			if (!GunList.isEmpty())
			{
				cout << ", ";
			}
		}
		cout << "]" << endl;
		while (!tempList.isEmpty())
		{
			tempList.dequeue(tempGun, pri);
			GunList.enqueue(tempGun, pri);
		}
	}

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


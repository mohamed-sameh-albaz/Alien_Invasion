#pragma once
#include<iostream>
#include"../unit.h"
#include"../EarthArmy/EarthTank.h"
#include"../DS/ArrayStack.h"
using namespace std;

class EarthTankList
{
	int count;
	ArrayStack<EarthTank*> tankList;

public:
	EarthTankList():count(0)
	{
	}
	bool insert(EarthTank* newTank)
	{
		if (tankList.push(newTank))
		{
			count++;
			return true;
		}
		return false;
	}
	bool remove(unit*& deletedTank)
	{
		EarthTank* removedTank;
		if (tankList.pop(removedTank))
		{
			deletedTank = removedTank;
			count--;
			return true;
		}
		cout << "Cannot pick any tank ,The List Is Empty" << endl;////////////// put in other units or delete it?
		return false;
	}

	int getCount()
	{
		return count;
	}

	void print()
	{
		//if (tankList.isEmpty()) //may be deleted
		//{
		//	cout << "The tank List Is Empty" << endl;
		//	return;
		//}
		ArrayStack<EarthTank*>tempList;
		EarthTank* tempTank;
		cout << getCount()<<" ET [";
		while (!tankList.isEmpty())
		{
			tankList.pop(tempTank);
			cout<<tempTank->get_id();
			//cout << endl << "----------------------------" << endl;
			tempList.push(tempTank);
			if (!tankList.isEmpty())
			{
				cout << ", ";
			}
		}
		cout <<"]" << endl;
		while (!tempList.isEmpty())
		{
			tempList.pop(tempTank);
			tankList.push(tempTank);
		}
	}

	/*bool pickTank(unit*& pickedUnit)
	{
		EarthTank* pickedTank;
		if (tankList.pop(pickedTank))
		{
			pickedUnit = pickedTank;
			return true;
		} 
		else
		{
			cout << "Cannot pick any units ,The List Is Empty" << endl;
			return false;
		}
	}*/

};


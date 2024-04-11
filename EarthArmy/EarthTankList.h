#pragma once
#include"../unit.h"
#include"../EarthArmy/EarthTank.h"
#include"../DS/ArrayStack.h"
#include<iostream>
using namespace std;

class EarthTankList
{
	int num;
	ArrayStack<EarthTank*> tankList;

public:
	EarthTankList():num(0)
	{
	}
	bool addTank(EarthTank* newTank)
	{
		if (tankList.push(newTank))
		{
			num++;
			return true;
		}
		return false;
	}
	bool removeUnit(EarthTank* deletedTank)
	{
		if (tankList.pop(deletedTank))
		{
			num--;
			return true;
		}
		return false;
	}
	bool pickTank(unit*& pickedUnit)
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
	}
	void print()
	{
		if (tankList.isEmpty())
		{
			cout << "The List Is Empty" << endl;
			return;
		}
		ArrayStack<EarthTank*>tempList;
		EarthTank* tempTank;
		while (!tankList.isEmpty())
		{
			tankList.pop(tempTank);
			tempTank->disp();
			cout << endl << "----------------------------" << endl;
			tempList.push(tempTank);
		}
		while (!tempList.isEmpty())
		{
			tempList.pop(tempTank);
			tankList.push(tempTank);
		}
	}
};


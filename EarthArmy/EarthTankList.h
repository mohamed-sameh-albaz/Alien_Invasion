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
	EarthTankList();
	~EarthTankList();

	bool insert(EarthTank* newTank);
	
	bool remove(unit*& deletedTank);
	

	int getCount();
	

	void print();
	

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


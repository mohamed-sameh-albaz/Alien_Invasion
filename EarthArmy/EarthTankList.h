#pragma once
#include"../EarthArmy/EarthTank.h"
#include"../DS/ArrayStack.h"
#include<iostream>
#include<stack>
using namespace std;

class EarthTankList
{
private:
	ArrayStack<EarthTank*>TankList();
	stack<EarthTank*>list;
public:
	EarthTankList();
	void addUnit(EarthTank* newTank);
	void removeUnit(EarthTank* deletedTank);
	void print()const;
};


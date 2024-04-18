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
};


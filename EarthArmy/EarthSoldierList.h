#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"EarthSoldier.h"
using namespace std;

class EarthSoldierList
{
	LinkedQueue<EarthSoldier*> soldierList; 
	int count;
public:
	EarthSoldierList();
	~EarthSoldierList();

	bool insert(EarthSoldier* u);	
	bool remove(unit*& u);
	void print();
	int getCount();
};

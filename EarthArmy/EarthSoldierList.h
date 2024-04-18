#pragma once
#include<iostream>
#include "../unit.h"
#include"../DS/LinkedQueue.h"
#include"EarthSoldier.h"
using namespace std;

class EarthSoldierList
{
	LinkedQueue<unit*> soldierList; 
	int count;
public:
	EarthSoldierList();
	~EarthSoldierList();
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
	int getCount();
};

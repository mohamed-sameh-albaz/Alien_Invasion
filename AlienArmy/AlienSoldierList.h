#pragma once
#include<iostream>
#include"../DS/LinkedQueue.h"
#include"AlienSoldier.h" 
#include"../unit.h"
using namespace std;

class AlienSoldierList
{
	LinkedQueue<unit*> alienSoldierList; 
	int count;
public:
	AlienSoldierList();
	bool insert(unit* u);
	bool remove(unit*& u);
	void print();
	int getCount();
	~AlienSoldierList();
};


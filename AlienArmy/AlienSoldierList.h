#pragma once
#include<iostream>
#include"../DS/LinkedQueue.h"
#include"AlienSoldier.h" 
#include"../unit.h"
using namespace std;

class AlienSoldierList
{
	LinkedQueue<AlienSoldier*> alienSoldierList;
	int count;
public:
	AlienSoldierList();
	~AlienSoldierList();
	bool insert(AlienSoldier* u);
	bool peek(unit*&);
	bool remove(unit*& u);
	void print();
	int getCount();
};


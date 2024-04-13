#pragma once
#include<iostream>
#include"../DS/LinkedQueue.h"
#include"AlienSoldier.h" //including soldier
#include"../unit.h"
using namespace std;

class AlienSoldierList
{
	LinkedQueue<unit*> alienSoldierList; //change list name
	int count;
public:
	AlienSoldierList();
	bool insert(unit* u);		//remove refrence 
	bool remove(unit*& u);
	void print();
	int getCount();
};

